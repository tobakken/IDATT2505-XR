cmake_minimum_required(VERSION 3.1)

project(Exercise2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})

add_executable(Exercise2 main.cpp)

target_link_libraries(Exercise2 ${OPENGL_LIBRARIES})
target_link_libraries(Exercise2 ${GLUT_LIBRARIES})
