cmake_minimum_required(VERSION 3.0)
project(Drawer)

message(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC ${HEADERS_DIR}/Drawer.h Drawer.cpp)
target_link_libraries(${PROJECT_NAME}
    ${CURSES_LIBRARIES}
    )
