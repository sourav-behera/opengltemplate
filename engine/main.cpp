#include <iostream>

#include <window.h>
#include <shader.h>
#include <texture.h>
#include <camera.h>
#include <cube.h>

const float width = 800.0f, height = 600.0f;
const char *title = "OpenGL";

int main() {

  Window *gameWindow = new Window(width, height, title);
  gameWindow->init();
  GLFWwindow *window = gameWindow->getWindow();
  
  float lastFrameTime = glfwGetTime();

  //Scene init
  Camera camera;
  Cube *cube = new Cube();

  //window update
  while(!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    float currentTime = glfwGetTime();
    float deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    float xoffset, yoffset;
    std::vector<float> offset = gameWindow->getMouseOffset();
    xoffset = offset[0];
    yoffset = offset[1];
    camera.rotateCamera(xoffset, yoffset);
    camera.moveCamera(window, deltaTime);

    cube->setMatrix(camera.getViewMatrix(), camera.getProjectionMatrix());
    cube->draw();
  
    glfwSwapBuffers(window);
  }

  gameWindow->close();
  return 0;
}