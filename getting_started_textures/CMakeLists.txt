cmake_minimum_required(VERSION 2.8)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

project(test)

find_package(glfw3 REQUIRED)

file(GLOB project_file glad.c main.cpp)
add_executable(${PROJECT_NAME} ${project_file})

target_link_libraries(${PROJECT_NAME} glfw)