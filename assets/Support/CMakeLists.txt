cmake_minimum_required(VERSION 3.0)
project(Support)

add_library(${PROJECT_NAME}
    ${HEADERS_DIR}/Support.h
    Support.cpp
    )

target_link_libraries(${PROJECT_NAME}
    ${CURSES_LIBRARIES}
    rt
    )
