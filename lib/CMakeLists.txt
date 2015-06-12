# Copyright: (C) 2010 RobotCub Consortium
# Authors: Giorgio Metta, Lorenzo Natale
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

set(sources src/RC_DIST_FB_logpolar_mapper.cpp)
set(headers include/iCub/logpolar/LogpolarInterfaces.h
            include/iCub/logpolar/RC_DIST_FB_logpolar_mapper.h)

source_group("Header Files" FILES ${headers})
source_group("Source Files" FILES ${sources})

if(UNIX)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fPIC)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${YARP_INCLUDE_DIRS})
add_library(logpolar ${headers} ${sources})
target_link_libraries(logpolar ${YARP_LIBRARIES})

icubcontrib_export_library(logpolar INTERNAL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
                                    EXTERNAL_INCLUDE_DIRS ${YARP_INCLUDE_DIRS}
                                    DESTINATION include/iCub/logpolar
                                    FILES ${headers})
