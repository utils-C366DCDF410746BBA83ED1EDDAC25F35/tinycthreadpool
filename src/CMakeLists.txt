cmake_minimum_required(VERSION 2.8)
project(threadpool C)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()

add_library(threadpool threadpool.c tinycthread.c)
