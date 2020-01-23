cmake_minimum_required(VERSION 3.0)
project(BlinkyChase)

add_library(${PROJECT_NAME} ${HEADERS_DIR}/BlinkyChase.h BlinkyChase.cpp)

target_link_libraries(${PROJECT_NAME} Mode)
