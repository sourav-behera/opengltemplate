#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>

#include <glad/glad.h>

class Shader {
  private:
    GLuint shaderProgram;

  public:
    Shader();
    Shader(std::string vertexShaderFilePath, std::string fragementShaderFilePath);
    void load(std::string vertexShaderFilePath, std::string fragmentShaderFilePath);
    void checkShaderCompileStatus(GLuint& shader);
    void use();
    GLuint getShaderProgram();
};

#endif
