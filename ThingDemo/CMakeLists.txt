cmake_minimum_required (VERSION 3.1)
project (ThingDemo)

set (CMAKE_CXX_STANDARD 11)

include_directories ("../ThingEngine")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

set (THING_DEMO_CPP
	ThingDemo.cpp 
)

add_executable (ThingDemo ${THING_DEMO_CPP})

target_link_libraries (ThingDemo ThingEngine)