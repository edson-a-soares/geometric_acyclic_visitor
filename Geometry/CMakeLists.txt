cmake_minimum_required(VERSION 3.6)
project(Geometry)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(PROJECT_INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/Geometry/include)
set(PROJECT_SOURCE_DIR ${CMAKE_HOME_DIRECTORY}/Geometry/src)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/Geometry/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/Geometry/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/Geometry/bin)

file(GLOB GEOMETRY_SOURCE_FILES_TOP "${PROJECT_SOURCE_DIR}/Geometry/*.cpp")
file(GLOB_RECURSE GEOMETRY_SOURCE_FILES_NESTED
        ${PROJECT_SOURCE_DIR}/Geometry/Measure/*.cpp
        ${PROJECT_SOURCE_DIR}/Geometry/Polygon/*.cpp
        ${PROJECT_SOURCE_DIR}/Geometry/Calculation/*.cpp)
set(GEOMETRY_SOURCE_FILES ${GEOMETRY_SOURCE_FILES_TOP} ${GEOMETRY_SOURCE_FILES_NESTED})

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_library(Geometry SHARED ${GEOMETRY_SOURCE_FILES})
target_link_libraries(Geometry Util)
target_include_directories(Geometry PUBLIC ${PROJECT_INCLUDE_DIR})

add_executable(AcyclicVisitor ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(AcyclicVisitor Geometry)

file(GLOB TEST_GEOMETRY_SOURCE_FILES_TOP ${CMAKE_HOME_DIRECTORY}/Geometry/test/*.cpp)
file(GLOB_RECURSE TEST_GEOMETRY_SOURCE_FILES_NESTED
        ${CMAKE_HOME_DIRECTORY}/Geometry/test/Geometry/Calculation/*.cpp)
set(TEST_GEOMETRY_SOURCE_FILES ${TEST_GEOMETRY_SOURCE_FILES_TOP} ${TEST_GEOMETRY_SOURCE_FILES_NESTED})

add_executable(GeometryTests ${TEST_GEOMETRY_SOURCE_FILES})
target_link_libraries(GeometryTests Geometry gtest gtest_main pthread)

add_test(
    NAME GeometryTests
    COMMAND GeometryTests
)
