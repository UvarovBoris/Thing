cmake_minimum_required (VERSION 2.6)
project (ThingDemo)

# The version number.
set (ThingDemo_VERSION_MAJOR 0)
set (ThingDemo_VERSION_MINOR 0)
set (ThingDemo_VERSION_PATCH 1)

# configure a header file to pass some of the CMake settings
# to the source code
#configure_file (
#  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
#  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
#  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
#include_directories("${PROJECT_BINARY_DIR}")

include_directories ("${PROJECT_SOURCE_DIR}/../ThingEngine")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

set (THING_DEMO_CPP
	ThingDemo.cpp 
)

add_executable (ThingDemo ${THING_DEMO_CPP})

target_link_libraries (ThingDemo ThingEngine)