cmake_minimum_required(VERSION 3.0)
project(InkyChase)

add_library(${PROJECT_NAME} ${HEADERS_DIR}/InkyChase.h InkyChase.cpp)

target_link_libraries(${PROJECT_NAME} Mode)