#include <iostream>

#include <window.h>
#include <shader.h>
#include <texture.h>
#include <camera.h>
#include <cube.h>
#include <scene.h>

const float width = 800.0f, height = 600.0f;
const char *title = "opengl";

Camera *camera = new Camera();

int main() {

  Window *gameWindow = new Window(width, height, title);
  gameWindow->init();
  
  Cube *cube1 = new Cube();
  Cube *cube2 = new Cube();
  cube2->setShader("../assets/shaders/vertex/light.vert", "../assets/shaders/fragment/light.frag");
  glm::vec3 lightpos = glm::vec3(1.2f, 1.0f, 2.0f);
  cube2->setPosition(lightpos);
  cube2->setScale(glm::vec3(0.3f, 0.3f, 0.3f));
  Scene *scene = new Scene();
  scene->setCamera(camera);
  cube1->setScale(glm::vec3(3.0f, 3.0f, 3.0f));

  scene->add(cube2);
  scene->add(cube1);

  gameWindow->update(scene);

  gameWindow->close();
  return 0;
}