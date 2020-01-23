cmake_minimum_required(VERSION 3.0)
project(Game)

add_library(${PROJECT_NAME} Game.h Game.cpp)

target_link_libraries(${PROJECT_NAME} Scene)
