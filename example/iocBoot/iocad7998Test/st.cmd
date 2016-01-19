#!../../bin/linux-x86_64/ad7998Test

## You may have to change ad7998Test to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/ad7998Test.dbd"
ad7998Test_registerRecordDeviceDriver pdbbase

## Load gpio and I2C drivers
GpioConstConfigure( "BEAGLEBONE BLACK" )
drvAsynI2CConfigure( "I2C", "/dev/i2c-1", 1 )

## Load record instances
dbLoadRecords( "db/ad7998.db", "ID=33,CONVST=P9_22,BUSY=P9_21" )

cd "${TOP}/iocBoot/${IOC}"
iocInit

