cmake_minimum_required(VERSION 3.0)
project(Pac-man)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets/headers)
set(PROC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ghosts_proc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lrt")

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})
include_directories(${HEADERS_DIR})

add_subdirectory(assets)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    GameController
    ${CURSES_LIBRARIES}
    )

