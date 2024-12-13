#include <iostream>

#include <window.h>
#include <shader.h>
#include <texture.h>
#include <camera.h>
#include <cube.h>
#include <scene.h>

const float width = 800.0f, height = 600.0f;
const char *title = "OpenGL";

Camera *camera = new Camera();

int main() {

  Window *gameWindow = new Window(width, height, title);
  gameWindow->init();
  
  Cube *cube = new Cube();

  Scene *scene = new Scene();
  scene->setCamera(camera);
  scene->add(cube);

  gameWindow->update(scene);

  gameWindow->close();
  return 0;
}