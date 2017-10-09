cmake_minimum_required(VERSION 3.8)
project(AuDEx01)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Task1.cpp Task1.h Task2.cpp Task2.h)
add_executable(AuDEx01 ${SOURCE_FILES})