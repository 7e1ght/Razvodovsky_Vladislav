cmake_minimum_required(VERSION 3.0)
project(Support)

message(${PROJECT_NAME})

set(SUPPORT_HEADER Support.h)
include_directories(./)

add_subdirectory(Drawer)
add_subdirectory(GameController)
add_subdirectory(Characters)
add_subdirectory(Mode)
add_subdirectory(Scene)