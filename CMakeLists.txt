cmake_minimum_required(VERSION 3.0)
project(Main)

message(${PROJECT_NAME})

add_subdirectory(assets)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} GameController)