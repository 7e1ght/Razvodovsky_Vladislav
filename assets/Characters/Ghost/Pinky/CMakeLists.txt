cmake_minimum_required(VERSION 3.0)
project(Pinky)

set(EXECUTABLE_OUTPUT_PATH ${PROC_DIR})

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Pinky.h Pinky.cpp)

add_executable(PinkyMain main.cpp)

target_link_libraries(${PROJECT_NAME}
    Ghost
    PinkyChase
    )

target_link_libraries(PinkyMain
    Support
    ${PROJECT_NAME}
    )
