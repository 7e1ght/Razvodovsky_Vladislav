cmake_minimum_required(VERSION 3.0)
project(MainMenu)

add_library(${PROJECT_NAME} ${HEADERS_DIR}/MainMenu.h MainMenu.cpp)

target_link_libraries(${PROJECT_NAME}
    ${CURSES_LIBRARIES}
    Scene
    Support
    )
