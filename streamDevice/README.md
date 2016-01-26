# Using StreamDevice with drvAsynI2C

It is possible to use StreamDevice in combination with this asyn Driver, to
establish communication with your I2C slave devices.
Use the `%r` format converter to send/read data from the bus und set `MaxInput`
to the number of bytes you expect from the device.

Example:

>     Terminator   = '';
>     MaxInput     = 2;
>     ExtraInput   = Error;
>     
>     rCtrl {
>       out ${1} 2; 
>       in  "%02r";
>     }

## Known problems with StreamDevice
Using this driver in combination with StreamDevice is unfortunately not that easy.
The first problem is the `writeHandler` of StreamDevice's AsynInterface. This handler
tries to flush any buffered messages before sending by reading 256 bytes until
the driver returns asynTimeout or asynError. As soon as a valid slave address is set up
in the I2C kernel module, such a read call will always succeed and thus returns asynSuccess.

The second problem is the implementation of the `readHandler` of StreamDevice's AsynInterface.
The number of bytes read by StreamDevice has to be limited by the `MaxInput` variable in the
protocol file. If this number is larger than 1, e.g. if the used slave devices have 16-bit
(or larger) registers, StreamDevice will perform at least two read calls. The first has always
a maximum length of one byte. That means for devices with 16-bit registers StreamDevice would
read two times the first byte if setting `MaxInput = 2`.

## Solution
To overcome these two problems, this package implements a new asyn interface "asynI2C".
The interface is registered by the drvAsynI2C-driver class. It has no methods, since none
are needed. It is only used to change the default behaviour of streamDevice.

The patch file in this directory can be used to make the new interface known to streamDevice.
It is recommended to use the StreamDevice version from
[github](https://github.com/epics-modules/stream)

