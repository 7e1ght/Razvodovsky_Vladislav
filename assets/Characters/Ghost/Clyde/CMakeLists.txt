cmake_minimum_required(VERSION 3.0)
project(Clyde)

set(EXECUTABLE_OUTPUT_PATH ${PROC_DIR})

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Clyde.h Clyde.cpp)

add_executable(ClydeMain main.cpp)

target_link_libraries(${PROJECT_NAME} 
    Ghost
    ClydeChase
    )

target_link_libraries(ClydeMain
    Support
    ${PROJECT_NAME}
    )
