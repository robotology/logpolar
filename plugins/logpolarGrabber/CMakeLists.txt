# Copyright: (C) 2015 iCub Facility - Istituto Italiano di Tecnologia
# Authors: Ugo Pattacini
# CopyPolicy: Released under the terms of the GNU GPL v3.0.

yarp_prepare_plugin(logpolargrabber TYPE yarp::dev::ServerLogpolarFrameGrabber
                    INCLUDE yarp/dev/ServerLogpolarFrameGrabber.h CATEGORY device
                    WRAPPER logpolargrabber)

if(ENABLE_logpolargrabber)
    include_directories(${logpolar_INCLUDE_DIRS} ${YARP_INCLUDE_DIRS})

    yarp_add_plugin(logpolargrabber ServerLogpolarFrameGrabber.cpp
                    yarp/dev/ServerLogpolarFrameGrabber.h)

    target_link_libraries(logpolargrabber logpolar ${YARP_LIBRARIES})

    yarp_install(FILES logpolargrabber.ini
                 DESTINATION ${ICUBCONTRIB_PLUGIN_MANIFESTS_INSTALL_DIR})

    yarp_install(TARGETS logpolargrabber
                 EXPORT logpolar
                 COMPONENT Runtime
                 LIBRARY DESTINATION ${ICUBCONTRIB_DYNAMIC_PLUGINS_INSTALL_DIR}
                 ARCHIVE DESTINATION ${ICUBCONTRIB_STATIC_PLUGINS_INSTALL_DIR})
endif()
