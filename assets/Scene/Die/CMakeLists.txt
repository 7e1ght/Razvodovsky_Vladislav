cmake_minimum_required(VERSION 3.0)
project(Die)

add_library(${PROJECT_NAME} Die.h Die.cpp)

target_link_libraries(${PROJECT_NAME} Scene)
