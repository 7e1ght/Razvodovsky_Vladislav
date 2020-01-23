cmake_minimum_required(VERSION 3.0)
project(Characters)

add_library(${PROJECT_NAME} Characters.h Characters.cpp)

add_subdirectory(Player)
add_subdirectory(Ghost)
