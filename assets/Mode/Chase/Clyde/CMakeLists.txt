cmake_minimum_required(VERSION 3.0)
project(ClydeChase)

add_library(${PROJECT_NAME} ClydeChase.h ClydeChase.cpp)

target_link_libraries(${PROJECT_NAME} Mode)