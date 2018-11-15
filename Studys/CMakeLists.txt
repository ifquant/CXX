cmake_minimum_required(VERSION 3.10.0)
project(Xquant)

include(${CMAKE_SOURCE_DIR}/../cmake/find_all.cmake)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(../../Thirds)
add_subdirectory(BPython)

