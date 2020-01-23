cmake_minimum_required(VERSION 3.0)
project(Clyde)

add_library(${PROJECT_NAME} Clyde.h Clyde.cpp)
target_link_libraries(${PROJECT_NAME} Ghost)

