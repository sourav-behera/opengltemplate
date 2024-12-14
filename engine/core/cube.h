#ifndef CUBE_H
#define CUBE_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <camera.h>
#include <shader.h>
#include <texture.h>
#include <gameObject.h>

extern Camera *camera;

class Cube : public GameObject{
  private:
    GLuint vao, vbo, ebo;
    glm::vec3 position, rotation, scale;
    glm::mat4 modelMatrix;
    glm::mat4 view, projection;
    Shader *shader;
    Texture *texture;

  public:
    Cube() {
      // float vertices[] = {
      //   -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
      //    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
      //    0.5f,  0.5f, 0.5f, 0.0f, 1.0f,
      //   -0.5f,  0.5f, 0.5f, 1.0f, 1.0f,

      //   -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
      //    0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
      //    0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
      //   -0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
      // };

      float vertices[] = {
          -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
          0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
          0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
          0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
          -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
          -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 

          -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
          0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
          0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
          0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
          -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
          -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

          -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
          -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
          -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
          -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
          -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
          -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

          0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
          0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
          0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
          0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
          0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
          0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

          -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
          0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
          0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
          0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
          -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
          -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

          -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
          0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
          0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
          0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
          -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
          -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
      };

      unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0,

        4, 7, 6,
        6, 5, 4,

        1, 5, 6,
        6, 2, 1,

        0, 4, 7,
        7, 3, 0,

        3, 7, 6,
        6, 2, 3,

        0, 4, 5,
        5, 1, 0
      };

      glGenVertexArrays(1, &vao);
      glBindVertexArray(vao);

      glGenBuffers(1, &vbo);
      glBindBuffer(GL_ARRAY_BUFFER, vbo);
      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

      glGenBuffers(1, &ebo);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

      //position attribute
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0); 
      glEnableVertexAttribArray(0);
      
      // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
      
      // normal attributes
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
      glEnableVertexAttribArray(1);

      shader = nullptr;
      texture = nullptr;

      shader = new Shader("../assets/shaders/vertex/sample.vert", "../assets/shaders/fragment/sample.frag");
      texture = new Texture("../assets/textures/container.jpg");

      position = glm::vec3(0.0f, 0.0f, 0.0f);
      rotation = glm::vec3(0.0f, 0.0f, 0.0f);
      scale = glm::vec3(1.0f, 1.0f, 1.0f);

      modelMatrix = glm::mat4(1.0f);
    };
    
    void setMatrix(glm::mat4 view, glm::mat4 projection) {
      this->view = view;
      this->projection = projection;
    };
    
    void draw() {
      if (!shader) return;
      shader->use();
      GLuint shaderProgram = shader->getShaderProgram();

      glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
      glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
      glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
      if (glGetUniformLocation(shaderProgram, "lightPos") != -1) {
        glUniform3f(glGetUniformLocation(shaderProgram, "lightPos"), 1.2f, 1.0f, 2.0f);
      }
      if (glGetUniformLocation(shaderProgram, "viewPos") != -1) {
        glUniform3f(glGetUniformLocation(shaderProgram, "viewPos"), camera->getPosition().x, camera->getPosition().y, camera->getPosition().z);
      }
      glBindVertexArray(vao);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
      glBindBuffer(GL_ARRAY_BUFFER, vbo);
      // glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
      glDrawArrays(GL_TRIANGLES, 0, 36);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindVertexArray(0);
    };
    
    void setPosition(glm::vec3 position) {
      this->position = position;
      updateTransform();
    }

    void setRotation(glm::vec3 rotation) {
      this->rotation = rotation;
      updateTransform();
    }

    void setScale(glm::vec3 scale) {
      this->scale = scale;
      updateTransform();
    }

    void updateTransform() {
      modelMatrix = glm::scale(modelMatrix, scale);
      modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
      modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
      modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
      modelMatrix = glm::translate(modelMatrix, position);
    }

    void update() override {
      if (camera) setMatrix(camera->getViewMatrix(), camera->getProjectionMatrix());
      else {
        std::cerr << "ERROR::CAMERA: Camera not set.\n";
        return;
      }
      draw();
    };

    void setShader(const char *vertexShaderPath, const char *fragmentShaderPath) {
      glDeleteProgram(shader->getShaderProgram());
      shader = new Shader(vertexShaderPath, fragmentShaderPath);
    }

    Shader *getShader() {
      return shader;
    }
};
#endif
