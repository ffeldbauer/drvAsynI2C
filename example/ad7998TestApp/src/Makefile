TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = ad7998Test
# ad7998Test.dbd will be created and installed
DBD += ad7998Test.dbd

# ad7998Test.dbd will be made up from these files:
ad7998Test_DBD += base.dbd

# Include dbd files from all support applications:
#ad7998Test_DBD += xxx.dbd
ad7998Test_DBD += asyn.dbd
ad7998Test_DBD += stream.dbd
ad7998Test_DBD += devgpio.dbd
ad7998Test_DBD += drvAsynI2C.dbd


# Add all the support libraries needed by this IOC
#ad7998Test_LIBS += xxx
ad7998Test_LIBS += asyn
ad7998Test_LIBS += stream
ad7998Test_LIBS += devgpio
ad7998Test_LIBS += drvAsynI2C

# ad7998Test_registerRecordDeviceDriver.cpp derives from ad7998Test.dbd
ad7998Test_SRCS += ad7998Test_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
ad7998Test_SRCS_DEFAULT += ad7998TestMain.cpp
ad7998Test_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#ad7998Test_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
ad7998Test_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

