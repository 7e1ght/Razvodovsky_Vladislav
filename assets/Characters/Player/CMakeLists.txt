cmake_minimum_required(VERSION 3.0)
project(Player)

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Player.h Player.cpp)
target_link_libraries(${PROJECT_NAME} Characters)