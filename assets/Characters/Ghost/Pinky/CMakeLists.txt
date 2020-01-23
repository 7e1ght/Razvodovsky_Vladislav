cmake_minimum_required(VERSION 3.0)
project(Pinky)

add_library(${PROJECT_NAME} Pinky.h Pinky.cpp)
target_link_libraries(${PROJECT_NAME} Ghost)

