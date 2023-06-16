#CMakeLists.txt
project (demo)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET (CMAKE_CXX_FLAGS                "-Wall -std=c++17")

set(SRC_LIST src/main.cpp)

message(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})
message(STATUS "This is SOURCE dir "${HELLO_SOURCE_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main ${SRC_LIST})
