cmake_minimum_required(VERSION 3.0)
project(PinkyChase)

add_library(${PROJECT_NAME} ${HEADERS_DIR}/PinkyChase.h PinkyChase.cpp)

target_link_libraries(${PROJECT_NAME} Mode)