# drvAsynI2C

This module provides EPICS device support for accessing I2C bus.

## Dependencies

   - EPICS base 3.14.12.5 (or newer)
   - asynDriver 4-26 (or newer)
   - i2c-tools

## Installation

 1.  Edit "configure/RELEASE" according to your environment
 2.  Type `make` inside the top directory

## Usage

### Loading the driver
To load the driver use the command inside the IOC

>     drvAsynI2CConfigure( "NAME", "I2Cbus", autoConnect )

where `NAME` is the name used by asyn to identify the driver,
`I2Cbus` is the name of the I2C device on the filesystem
and `autoConnect` is a flag whether the driver should automatically
connect to the device or not.

### Writing to/Reading from the bus
The driver provides an asynOctet interface for reading from/writing to the bus.
This interfaces uses a binary format. The first byte of a write command is
always treated as the slave address on the bus without the R/!W bit.
The setting of this bit is managed by the kernel module.
All following bytes will be send to the slave device.

The directory `example` contains a small IOC controlling an AD7998 ADC via streamDevice.
(Note: This example uses also the devGpio device support which can also
 be found on [github](https://github.com/ffeldbauer/epics-devgpio) )

### Using StreamDevice
Using this driver in combination with StreamDevice is unfortunately not that easy.
The first problem is the `writeHandler` of StreamDevice's AsynInterface. This handler
tries to flush any buffered messages before sending by reading 256 bytes until
the driver returns asynTimeout or asynError. As soon as a valid slave address is set up
in the I2C kernel module, such a read call will always succeed and thus returns asynSuccess.

The current workaround is to forbid read calls with a maximum length of 256 bytes which should
not have any real use case on an I2C bus.

The second problem is the implementation of the `readHandler` of StreamDevice's AsynInterface.
The number of bytes read by StreamDevice has to be limited by the `MaxInput` variable in the
protocol file. If this number is larger than 1, e.g. if the used slave devices have 16-bit
(or larger) registers, StreamDevice will perform at least two read calls. The first has always
a maximum length of one byte. That means for devices with 16-bit registers StreamDevice would
read two times the first byte if setting `MaxInput = 2`. To successfull read the complete
register content one has to read three bytes and ignore the first one. Example:

>     MaxInput = 3;
>     
>     read16bitRegister {
>       out ${1} 2;
>       in  "%*01r%02r";
>     }

## Known Issues
   - none    

