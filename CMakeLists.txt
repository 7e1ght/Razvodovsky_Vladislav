cmake_minimum_required(VERSION 3.0)
project(Pac-man)

set(EXECUTABLE_OUTPUT_PATH bin)

message(${PROJECT_NAME})

set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets/headers)

include_directories(${HEADERS_DIR})

add_subdirectory(assets)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} GameController)