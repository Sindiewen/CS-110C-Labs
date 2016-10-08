cmake_minimum_required(VERSION 3.6)
project(Lab_3___Pointer_Based_ADT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ModifedLinkedList.h Node.h)
add_executable(Lab_3___Pointer_Based_ADT ${SOURCE_FILES})