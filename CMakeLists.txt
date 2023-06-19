cmake_minimum_required(VERSION 3.10) #运行此配置文件所需的 CMake 的最低版本
project (demo) #设置项目名

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET(CMAKE_CXX_FLAGS "-Wall -std=c++17")

# 查找目录下所有源文件名，并将其存储存在dir_main
aux_source_directory(src dir_main)
aux_source_directory(unit-test dir_test)

# message(STATUS "dir_main: " ${dir_main})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main ${dir_main})
