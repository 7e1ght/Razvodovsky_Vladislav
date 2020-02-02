cmake_minimum_required(VERSION 3.0)
project(Inky)

set(EXECUTABLE_OUTPUT_PATH ${PROC_DIR})

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Inky.h Inky.cpp)

add_executable(InkyMain main.cpp)

target_link_libraries(${PROJECT_NAME}
    Ghost
    InkyChase
    )

target_link_libraries(InkyMain
    Support
    ${PROJECT_NAME}
    )
