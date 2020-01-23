cmake_minimum_required(VERSION 3.0)
project(GameController)

message(${PROJECT_NAME})

include_directories(${PROJECT_NAME} PUBLIC ../*)
add_library(${PROJECT_NAME} STATIC GameController.h GameController.cpp)
