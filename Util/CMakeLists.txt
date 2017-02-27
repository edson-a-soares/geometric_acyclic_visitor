cmake_minimum_required(VERSION 3.6)
project(Util)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#########################################################
# Including source code
#########################################################
set(PROJECT_INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/Util/include)
set(PROJECT_SOURCE_DIR ${CMAKE_HOME_DIRECTORY}/Util/src)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/Util/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/Util/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/Util/bin)

file(GLOB_RECURSE UTIL_SOURCE_FILES "${PROJECT_SOURCE_DIR}/*.cpp")

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_library(Util SHARED ${UTIL_SOURCE_FILES})
target_include_directories(Util PUBLIC ${PROJECT_INCLUDE_DIR})
