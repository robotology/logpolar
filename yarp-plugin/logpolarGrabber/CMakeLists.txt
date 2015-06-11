# Copyright: (C) 2015 iCub Facility - Istituto Italiano di Tecnologia
# Authors: Ugo Pattacini
# CopyPolicy: Released under the terms of the GNU GPL v3.0.

yarp_prepare_device(logpolargrabber TYPE yarp::dev::ServerLogpolarFrameGrabber
                    INCLUDE yarp/dev/ServerLogpolarFrameGrabber.h
                    WRAPPER logpolargrabber)

include_directories(${logpolar_INCLUDE_DIRS} ${YARP_INCLUDE_DIRS})

yarp_add_plugin(logpolargrabber ServerLogpolarFrameGrabber.cpp
                yarp/dev/ServerLogpolarFrameGrabber.h)

target_link_libraries(logpolargrabber logpolar ${YARP_LIBRARIES})

yarp_install(FILES logpolargrabber.ini
             COMPONENT runtime
             DESTINATION ${ICUBCONTRIB_PLUGIN_MANIFESTS_INSTALL_DIR})
