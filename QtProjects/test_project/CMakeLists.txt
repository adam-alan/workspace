cmake_minimum_required(VERSION 2.8)

project(test_project)
set(log
    test_project/log_manger.h
    test_project/log_manger.cpp)
add_executable(${PROJECT_NAME} "main.cpp" ${log})
