cmake_minimum_required(VERSION 3.0)
project(Support)

message(${PROJECT_NAME})

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Support.h Support.cpp)

