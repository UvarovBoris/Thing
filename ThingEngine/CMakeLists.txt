cmake_minimum_required(VERSION 2.6)

project (ThingEngine)

set (CMAKE_CXX_STANDARD 11)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# The version number.
set (ThingEngine_VERSION_MAJOR 0)
set (ThingEngine_VERSION_MINOR 0)
set (ThingEngine_VERSION_PATCH 1)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/EngineConfig.h.in"
	"${PROJECT_SOURCE_DIR}/EngineConfig.h"
)

set(THING_ENGINE_SRC
	Application.cpp
)

find_package(OpenGL)

add_library(${PROJECT_NAME} ${THING_ENGINE_SRC})

include_directories ("${PROJECT_SOURCE_DIR}/libs/windows/glew-2.1.0/include")
include_directories ("${PROJECT_SOURCE_DIR}/libs/windows/sdl2-2.0.6/include")

target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libs/windows/glew-2.1.0/x86/glew32.lib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libs/windows/sdl2-2.0.6/x86/SDL2.lib)
if (OPENGL_FOUND)
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
endif (OPENGL_FOUND)