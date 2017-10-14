cmake_minimum_required(VERSION 2.6)
project (ThingEngine)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# The version number.
set (ThingEngine_VERSION_MAJOR 0)
set (ThingEngine_VERSION_MINOR 0)
set (ThingEngine_VERSION_PATCH 1)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/ThingEngineConfig.h.in"
	"${PROJECT_SOURCE_DIR}/ThingEngineConfig.h"
)

set(THING_ENGINE_SRC 
	ThingEngine.cpp
)

add_library(ThingEngine ${THING_ENGINE_SRC})