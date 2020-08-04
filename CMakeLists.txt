cmake_minimum_required(VERSION 3.1)
project(SM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_BUILD_TYPE "Debug")  

include_directories(./)

aux_source_directory(./ all_source)

add_executable(Main ${all_source})