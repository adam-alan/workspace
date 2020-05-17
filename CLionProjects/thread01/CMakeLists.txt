cmake_minimum_required(VERSION 3.14)
project(thread01)

set(CMAKE_CXX_STANDARD 14)

add_executable(thread01 main.cpp threadsafe_quene.h)