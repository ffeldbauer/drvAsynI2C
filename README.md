# drvAsynI2C

This module provides EPICS device support for accessing I2C bus.

## Dependencies

   - EPICS base 3.14.12.5 (or newer)
   - asynDriver 4-26 (or newer)
   - i2c-tools

## Installation

 1.  Set EPICS_BASE and ASYN variables in "configure/RELEASE"
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

## Known Issues
   - Using StreamDevice is currently not working!!! As soon as a valid slave address is set
     each write command from StreamDevice generates an endless loop!
     The reason is, that line [AsynDriverInterface.cc:631](https://github.com/epics-modules/stream/blob/master/streamDevice/src/AsynDriverInterface.cc#L631)
     will always return asynSuccess, when the configured slave address is valid.
    
