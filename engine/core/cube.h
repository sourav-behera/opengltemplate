#ifndef CUBE_H
#define CUBE_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <camera.h>
#include <shader.h>
#include <texture.h>

class Cube{
  private:
    GLuint vao, vbo, ebo;
    glm::vec3 position, rotation, scale;
    glm::mat4 modelMatrix;
    glm::mat4 view, projection;
    Shader *shader;
    Texture *texture;

  public:
    Cube();
    void setMatrix(glm::mat4 view, glm::mat4 projection);
    void draw();
};
#endif
