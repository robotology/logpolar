# Copyright: (C) 2010 RobotCub Consortium
# Authors: Giorgio Metta
# CopyPolicy: Released under the terms of the GNU GPL v2.0.
# Based on code by Paul Fitzpatrick & Lorenzo Natale

# Cmake code for adding a module to the iCub main build.
# You can assume yarp has been already found and is
# available.

set(PROJECTNAME logpolarConvertExample)
project(${PROJECTNAME})

set(sources src/main.cpp)
source_group("Source Files" FILES ${sources})

include_directories(${logpolar_INCLUDE_DIRS} ${YARP_INCLUDE_DIRS})
add_executable(${PROJECTNAME} ${sources})
target_link_libraries(${PROJECTNAME} logpolar ${YARP_LIBRARIES})
install(TARGETS ${PROJECTNAME} DESTINATION bin)

# app
file(GLOB conf ${CMAKE_CURRENT_SOURCE_DIR}/app/conf/*.ppm)
yarp_install(FILES ${conf} DESTINATION ${ICUBCONTRIB_CONTEXTS_INSTALL_DIR}/${PROJECTNAME})
