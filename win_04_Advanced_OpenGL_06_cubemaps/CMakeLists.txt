cmake_minimum_required(VERSION 3.9)
project(OpenGL_3)
set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D FREEGLUT_STATIC")

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(OpenGL src/main.cpp src/glad.c)

target_link_libraries(OpenGL freeglut_static opengl32 winmm gdi32 glu32.lib glfw3)

