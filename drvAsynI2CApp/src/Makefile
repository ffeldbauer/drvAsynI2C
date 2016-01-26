TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# build a support library

LIBRARY_IOC += drvAsynI2C

ifdef STREAM_WORKAROUND
USR_CXXFLAGS += -DSTREAM_WORKAROUND
endif

INC += asynI2C.h

# xxxRecord.h will be created from xxxRecord.dbd
#DBDINC += xxxRecord

# install drvAsynI2C.dbd into <top>/dbd
DBD += drvAsynI2C.dbd

# specify all source files to be compiled and added to the library
drvAsynI2C_SRCS += drvAsynI2C.cpp

drvAsynI2C_LIBS += $(EPICS_BASE_IOC_LIBS) asyn

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

