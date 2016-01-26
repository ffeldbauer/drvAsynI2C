//******************************************************************************
// Copyright (C) 2015 Florian Feldbauer <florian@ep1.ruhr-uni-bochum.de>
//                    - University Mainz, Institute for nuclear physics
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
#include <shareLib.h>

// local includes

//_____ D E F I N I T I O N S __________________________________________________

#define asynI2cType "asynI2C"

// define asynI2C interface
typedef struct asynI2C asynI2C;
struct asynI2C {
  // no methods needed for this interface.
  // it's just used to change the behaviour
  // of streamDevice when accessing the
  // asynOctet interface...
};
epicsShareExtern asynI2C *pasynI2C;

#endif
