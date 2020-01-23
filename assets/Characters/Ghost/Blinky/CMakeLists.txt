cmake_minimum_required(VERSION 3.0)
project(Blinky)

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Blinky.h Blinky.cpp)
target_link_libraries(${PROJECT_NAME} 
    Ghost
    BlinkyChase
    )

