cmake_minimum_required(VERSION 3.7)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ConnectFour.cpp ConnectFour.hpp Board.cpp Board.hpp)
add_executable(ConnectFour ${SOURCE_FILES})