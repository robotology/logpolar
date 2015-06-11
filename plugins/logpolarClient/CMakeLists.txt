# Copyright: (C) 2015 iCub Facility - Istituto Italiano di Tecnologia
# Authors: Ugo Pattacini
# CopyPolicy: Released under the terms of the GNU GPL v3.0.

yarp_prepare_device(logpolarclient TYPE yarp::dev::ClientLogpolarFrameGrabber
                    INCLUDE yarp/dev/ClientLogpolarFrameGrabber.h)

if(ENABLE_logpolarclient)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../logpolarGrabber
                        ${logpolar_INCLUDE_DIRS}
                        ${YARP_INCLUDE_DIRS})

    yarp_add_plugin(logpolarclient ClientLogpolarFrameGrabber.cpp)

    target_link_libraries(logpolarclient logpolar ${YARP_LIBRARIES})

    yarp_install(FILES logpolarclient.ini
                 DESTINATION ${ICUBCONTRIB_PLUGIN_MANIFESTS_INSTALL_DIR})

    yarp_install(TARGETS logpolarclient
                 EXPORT logpolar
                 COMPONENT Runtime
                 LIBRARY DESTINATION ${ICUBCONTRIB_DYNAMIC_PLUGINS_INSTALL_DIR}
                 ARCHIVE DESTINATION ${ICUBCONTRIB_STATIC_PLUGINS_INSTALL_DIR})
endif()
