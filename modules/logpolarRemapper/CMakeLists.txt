# Copyright: (C) 2010 RobotCub Consortium, European Commission FP6 Project IST-004370
# Authors: Giorgio Metta
# CopyPolicy: Released under the terms of the GNU GPL v2.0.
#

set(PROJECTNAME logpolarRemapper)
project(${PROJECTNAME})

set(sources src/logpolarRemapper.cpp)
source_group("Source Files" FILES ${sources})

include_directories(${logpolar_INCLUDE_DIRS} ${YARP_INCLUDE_DIRS})
add_executable(${PROJECTNAME} ${sources})
target_link_libraries(${PROJECTNAME} logpolar ${YARP_LIBRARIES})
install(TARGETS ${PROJECTNAME} DESTINATION bin)

# app
file(GLOB conf ${CMAKE_CURRENT_SOURCE_DIR}/app/conf/*.ini)
file(GLOB scripts ${CMAKE_CURRENT_SOURCE_DIR}/app/scripts/*.template)

yarp_install(FILES ${conf} DESTINATION ${ICUBCONTRIB_CONTEXTS_INSTALL_DIR}/${PROJECTNAME})
yarp_install(FILES ${scripts} DESTINATION ${ICUBCONTRIB_APPLICATIONS_TEMPLATES_INSTALL_DIR})
