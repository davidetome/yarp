/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#include <yarp/companion/impl/Companion.h>

#include <yarp/conf/version.h>

using yarp::companion::impl::Companion;


std::string Companion::version()
{
    return YARP_VERSION;
}

int Companion::cmdVersion(int argc, char *argv[])
{
    YARP_UNUSED(argc);
    YARP_UNUSED(argv);
    yCInfo(COMPANION, "YARP version %s", version().c_str());
    return 0;
}
