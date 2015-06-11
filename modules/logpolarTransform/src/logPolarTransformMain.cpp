// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/* 
 * Copyright (C) 2009 RobotCub Consortium, European Commission FP6 Project IST-004370
 * Authors: David Vernon
 * email:   david@vernon.eu
 * website: www.robotcub.org 
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
 */


/*
 * Audit Trail
 * -----------
 * 20/09/09  Began development   DV
 * 18/08/10  Rewrite by GM, removed dependencies from unnecessary libraries.
 * 19/08/10  Moved to the new logpolar library.
 */ 

/**
 * @file logPolarTransformMain.cpp
 * @brief main of the logpolar transform standalone module.
 */

#include "logPolarTransform.h"

using namespace yarp::os;

int main(int argc, char * argv[])
{
    Network yarp;
    LogPolarTransform logPolarTransform; 

    ResourceFinder rf;
    rf.setVerbose(true);
    rf.setDefaultConfigFile("logpolarTransform.ini");   //overridden by --from parameter
    rf.setDefaultContext("logpolarTransform");          //overridden by --context parameter
    rf.configure(argc, argv);
 
    logPolarTransform.runModule(rf);
    return 0;
}
