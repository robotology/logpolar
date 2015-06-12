# Copyright: (C) 2015 iCub Facility - Istituto Italiano di Tecnologia
# Authors: Ugo Pattacini
# CopyPolicy: Released under the terms of the GNU GPL v3.0.

include(YarpPlugin)

add_subdirectory(logpolarClient)
add_subdirectory(logpolarGrabber)

# app
if(ENABLE_logpolargrabber)
    file(GLOB scripts ${CMAKE_CURRENT_SOURCE_DIR}/app/scripts/*.template)
    yarp_install(FILES ${scripts} DESTINATION ${ICUBCONTRIB_APPLICATIONS_TEMPLATES_INSTALL_DIR})
endif()
