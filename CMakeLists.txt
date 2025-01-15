cmake_minimum_required(VERSION 3.30.4)

project(opengltemplate)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/assimp)

add_executable(opengltemplate
  vendor/glad/src/glad.c
  engine/main.cpp
  engine/utils/stb_image.cpp
)

include_directories(
  vendor/glfw/include
  vendor/glad/include
  vendor/freetype2/include
  vendor/assimp/include/
  vendor/stb
  vendor/glm
  engine/utils
  engine/core
)

target_link_libraries(opengltemplate
  ${CMAKE_SOURCE_DIR}/vendor/glfw/build/src/libglfw3.a
  ${CMAKE_SOURCE_DIR}/vendor/freetype2/build/libfreetype.a
  ${CMAKE_SOURCE_DIR}/vendor/assimp/bin/libassimp.so
  GL
)

