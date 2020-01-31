cmake_minimum_required(VERSION 3.0)
project(GameController)

message(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC ${HEADERS_DIR}/GameController.h GameController.cpp)

target_link_libraries(${PROJECT_NAME} MainMenu Game Lose)
