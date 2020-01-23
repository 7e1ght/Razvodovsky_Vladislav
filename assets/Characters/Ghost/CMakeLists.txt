cmake_minimum_required(VERSION 3.0)
project(Ghost)

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Ghost.h Ghost.cpp)
target_link_libraries(${PROJECT_NAME} Characters)

add_subdirectory(Blinky)
add_subdirectory(Clyde)
add_subdirectory(Inky)
add_subdirectory(Pinky)