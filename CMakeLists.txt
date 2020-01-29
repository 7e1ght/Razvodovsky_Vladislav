cmake_minimum_required(VERSION 3.0)
project(Pac-man)

set(EXECUTABLE_OUTPUT_PATH bin)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Curses REQUIRED)

set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets/headers)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread ")

include_directories(${HEADERS_DIR})

add_subdirectory(assets)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    GameController
    ${CURSES_LIBRARIES}
    )

target_include_directories(${PROJECT_NAME} PUBLIC ${CURSES_INCLUDE_DIR})
