//******************************************************************************
// Copyright (C) 2015 Florian Feldbauer <florian@ep1.ruhr-uni-bochum.de>
//                    - University Mainz, Institute for nucular physics
//
// This file is part of drvAsynI2C
//
// drvAsynI2C is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// drvAsynI2C is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
// version 1.0.0; Nov. 17, 2015
//******************************************************************************

#ifndef __ASYN_I2C_H__
#define __ASYN_I2C_H__

//_____ I N C L U D E S _______________________________________________________

// ANSI C includes

// EPICS includes
//#include <epicsTimer.h>

// local includes
#include "asynPortDriver.h"

//_____ D E F I N I T I O N S __________________________________________________

// #define SLAVEADDRESS_STRING "SLAVEADDRESS"

//! @brief   asynPortDriver for I2C
//!
class drvAsynI2C : public asynPortDriver {
 public:
  drvAsynI2C( const char *portName, const char *ttyName );

  // These are the methods that we override from asynPortDriver
  virtual asynStatus readOctet( asynUser *pasynUser, char *value, size_t maxChars,
                                size_t *nActual, int *eomReason );
  virtual asynStatus writeOctet( asynUser *pasynUser, char const *value, size_t maxChars,
                                 size_t *nActual );
//  virtual asynStatus readOption( asynUser *pasynUser, char const *key, char *value, int maxChars );
//  virtual asynStatus writeOption( asynUser *pasynUser, char const *key, char const *value );

  virtual asynStatus connect( asynUser *pasynUser );
  virtual asynStatus disconnect( asynUser *pasynUser );

//  inline void timeout() { _timeout = true; }

 protected:
//  int _paramSlaveAddress;

 private:

  // Our data
  char* _deviceName;
  int   _fd;
//  bool  _timeout;
  unsigned long  _i2cfuncs;
  int   _slaveAddress;
//  epicsTimerId       _timer;
//  epicsTimerQueueId  _timerQueue;
    
};


#endif

