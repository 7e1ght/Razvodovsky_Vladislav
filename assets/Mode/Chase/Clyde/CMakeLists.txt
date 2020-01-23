cmake_minimum_required(VERSION 3.0)
project(ClydeChase)

add_library(${PROJECT_NAME} ${HEADERS_DIR}/ClydeChase.h ClydeChase.cpp)

target_link_libraries(${PROJECT_NAME} Mode)