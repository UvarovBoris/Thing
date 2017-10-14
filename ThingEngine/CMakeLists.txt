cmake_minimum_required(VERSION 2.6)
project (ThingEngine)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

set(THING_ENGINE_SRC 
	ThingEngine.cpp
)

add_library(ThingEngine ${THING_ENGINE_SRC})