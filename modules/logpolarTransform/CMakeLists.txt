# Copyright: (C) 2009 RobotCub Consortium, European Commission FP6 Project IST-004370
# Authors: David Vernon, Lorenzo Natale
# CopyPolicy: Released under the terms of the GNU GPL v2.0.
#

set(PROJECTNAME logpolarTransform)
project(${PROJECTNAME})

file(GLOB headers src/*.h)
file(GLOB sources src/*.cpp)

source_group("Header Files" FILES ${headers})
source_group("Source Files" FILES ${sources})

include_directories(${PROJECT_SOURCE_DIR}/src
                    ${logpolar_INCLUDE_DIRS}
                    ${YARP_INCLUDE_DIRS})

add_executable(${PROJECTNAME} ${headers} ${sources})
target_link_libraries(${PROJECTNAME} logpolar ${YARP_LIBRARIES})
install(TARGETS ${PROJECTNAME} DESTINATION bin)

# app
file(GLOB conf ${CMAKE_CURRENT_SOURCE_DIR}/app/conf/*.ini)
file(GLOB scripts ${CMAKE_CURRENT_SOURCE_DIR}/app/scripts/*.template)

yarp_install(FILES ${conf} DESTINATION ${ICUBCONTRIB_CONTEXTS_INSTALL_DIR}/${PROJECTNAME})
yarp_install(FILES ${scripts} DESTINATION ${ICUBCONTRIB_APPLICATIONS_TEMPLATES_INSTALL_DIR})
