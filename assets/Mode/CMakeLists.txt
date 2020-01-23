cmake_minimum_required(VERSION 3.0)
project(Mode)

message(${PROJECT_NAME})

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Mode.h Mode.cpp)
add_library(Init ${HEADERS_DIR}/Initializing.h Initializing.cpp)
add_library(Scatter ${HEADERS_DIR}/Scatter.h Scatter.cpp)

target_link_libraries(Init ${PROJECT_NAME})
target_link_libraries(Scatter ${PROJECT_NAME})

add_subdirectory(Chase)