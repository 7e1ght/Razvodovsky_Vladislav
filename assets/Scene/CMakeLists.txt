cmake_minimum_required(VERSION 3.0)
project(Scene)

add_library(${PROJECT_NAME} ${HEADERS_DIR}/Scene.h Scene.cpp)

add_subdirectory(Die)
add_subdirectory(Game)
add_subdirectory(Lose)
add_subdirectory(MainMenu)
