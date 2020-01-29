cmake_minimum_required(VERSION 3.0)
project(ASSETS)

message(${PROJECT_NAME})

#set(SUPPORT_HEADER ${HEADERS_DIR}/Support.h)

add_subdirectory(Support)
add_subdirectory(Drawer)
add_subdirectory(GameController)
add_subdirectory(Characters)
add_subdirectory(Mode)
add_subdirectory(Scene)
