TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# build a support library

LIBRARY_IOC += drvAsynI2C

# xxxRecord.h will be created from xxxRecord.dbd
#DBDINC += xxxRecord
# install drvAsynI2C.dbd into <top>/dbd
DBD += drvAsynI2C.dbd

# specify all source files to be compiled and added to the library
#drvAsynI2C_SRCS += xxx

drvAsynI2C_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

