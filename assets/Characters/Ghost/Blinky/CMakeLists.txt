cmake_minimum_required(VERSION 3.0)
project(Blinky)

set(EXECUTABLE_OUTPUT_PATH ${PROC_DIR})

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Blinky.h Blinky.cpp)

add_executable(BlinkyMain main.cpp)

target_link_libraries(${PROJECT_NAME} 
    Ghost
    BlinkyChase
    )

target_link_libraries(BlinkyMain
    Support
    ${PROJECT_NAME}
    )

