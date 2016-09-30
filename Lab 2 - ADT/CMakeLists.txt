cmake_minimum_required(VERSION 3.6)
project(Lab_2___ADT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ModifiedListInterface.h ModifiedArrayList.h)
add_executable(Lab_2___ADT ${SOURCE_FILES})