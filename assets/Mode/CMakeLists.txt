cmake_minimum_required(VERSION 3.0)
project(Mode)

message(${PROJECT_NAME})

add_library(${PROJECT_NAME} Mode.h Mode.cpp)
add_library(Init Initializing.h Initializing.cpp)
add_library(Scatter Scatter.h Scatter.cpp)

target_link_libraries(Init ${PROJECT_NAME})
target_link_libraries(Scatter ${PROJECT_NAME})

add_subdirectory(Chase)