cmake_minimum_required(VERSION 3.10)
project(tombVM)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(tombVM
    src/main.cpp
    src/vm.cpp
)