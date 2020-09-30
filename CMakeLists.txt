cmake_minimum_required(VERSION 2.8)
project(tinycthreadpool C)

add_subdirectory(src)

add_subdirectory(test_package)

add_executable(test main.c)

target_link_libraries(test tinycthreadpool)