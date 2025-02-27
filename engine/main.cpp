#include <iostream>

#include <window.hpp>
#include <shader.hpp>
#include <texture.hpp>
#include <camera.hpp>
#include <cube.hpp>
#include <scene.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

const float width = 800.0f, height = 600.0f;
const char *title = "opengl";

Camera *camera = new Camera();

int main() {
  Assimp::Importer imoprter;
  
  Window *gameWindow = new Window(width, height, title);
  gameWindow->init();
  
  uint major, minor;
  glGetIntegerv(GL_MAJOR_VERSION, (int *)&major);
  glGetIntegerv(GL_MINOR_VERSION, (int *)&minor);

  printf("OpenGL version: %d.%d\n", major, minor);
  const char *renderer = (const char *)glGetString(GL_RENDERER);
  const char *vendor = (const char *)glGetString(GL_VENDOR);
  const char *version = (const char *)glGetString(GL_VERSION);
  const char *glslVersion = (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION);
  printf("Renderer: %s\n", renderer);
  printf("Vendor: %s\n", vendor);
  printf("Version: %s\n", version);
  printf("GLSL Version: %s\n", glslVersion);
  
  Scene *scene = new Scene();
  
  Cube *cube2 = new Cube();
  glm::vec3 lightpos = glm::vec3(1.2f, 1.0f, 2.0f);
  cube2->setShader("../assets/shaders/vertex/light.vert", "../assets/shaders/fragment/light.frag");
  cube2->setPosition(lightpos);
  cube2->setScale(glm::vec3(0.3f, 0.3f, 0.3f));
  scene->add(cube2);
  
  for (int i = 0; i < 9; i++) {
    Cube *cube1 = new Cube();
    scene->setCamera(camera);
    cube1->setPosition(glm::vec3(i%3 + 1.0f, 0.0f, i/3.0f + 1.0f));
    cube1->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
    scene->add(cube1);
  }


  gameWindow->update(scene);

  gameWindow->close();
  return 0;
}
