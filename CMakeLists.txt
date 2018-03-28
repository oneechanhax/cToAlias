
#
#
# Welcome to the cmake lists file, this controls how nekohook will build for your system
#
# TODO, make wasy way to do "touch ../src/CMakeLists.txt" to make things easy
#
#

cmake_minimum_required (VERSION 2.6)
project (libnekohook)

## Defaults
# User options can be set with cmake -D"NAME OF OPTION HERE"="VARIABLE", e.g. "cmake -DCGAME=csgo"
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE RELEASE)
endif(NOT CMAKE_BUILD_TYPE)

# Add cathooks source files except the modules, we add those selectivly
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.c*")

# Flags we use for every build type
set(CMAKE_CXX_STANDARD 17)

# Default compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "${CCOMMON_FLAGS} -g3 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CCOMMON_FLAGS} -s -mtune=native -O3")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

add_executable(nekohook ${SOURCE_FILES})

target_link_libraries(nekohook c stdc++)
