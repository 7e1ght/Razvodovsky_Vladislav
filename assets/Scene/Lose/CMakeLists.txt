cmake_minimum_required(VERSION 3.0)
project(Lose)

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Lose.h Lose.cpp)

target_link_libraries(${PROJECT_NAME} Scene)
