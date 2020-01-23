cmake_minimum_required(VERSION 3.0)
project(Inky)

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Inky.h Inky.cpp)
target_link_libraries(${PROJECT_NAME} Ghost)

