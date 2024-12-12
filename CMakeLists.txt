cmake_minimum_required(VERSION 3.30.4)

project(opengltemplate)

add_executable(opengltemplate
  engine/main.cpp
  engine/utils/shader.cpp
  engine/utils/texture.cpp
  engine/utils/stb_image.cpp
  engine/core/camera.cpp
  engine/core/cube.cpp
  engine/core/window.cpp
  vendor/glad/src/glad.c
)

include_directories(
  vendor/glfw/include
  vendor/glad/include
  vendor/freetype2/include
  vendor/stb
  vendor/glm
  engine/utils
  engine/core
)

target_link_libraries(opengltemplate
  ${CMAKE_SOURCE_DIR}/vendor/glfw/build/src/libglfw3.a
  ${CMAKE_SOURCE_DIR}/vendor/freetype2/build/libfreetype.a
  GL
)

