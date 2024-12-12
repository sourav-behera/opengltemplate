#include <shader.h>

void Shader::checkShaderCompileStatus(GLuint& shader) {
  char infoLog[1024];
  int length;
  
  GLint success;
  if (glIsShader(shader) == GL_TRUE) {
    GLint shaderType;

    glGetShaderiv(shader, GL_SHADER_TYPE, &shaderType);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
      glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
      if (shaderType == GL_VERTEX_SHADER) {
        std::cerr << "ERROR::VERTEX_SHADER: Failed to compile vertex shader.\n" << infoLog << std::endl;
      }
      if (shaderType == GL_FRAGMENT_SHADER) {
        std::cerr << "ERROR::FRAGMENT_SHADER: Failed to compile fragment shader.\n" << infoLog << std::endl;
      }

      char shaderSource[1024]; 
      glGetShaderSource(shader, 1024, nullptr, shaderSource);
      std::cout << shaderSource << std::endl;
    } 
  }
  if (glIsProgram(shader) == GL_TRUE) {
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(shader, 1024, &length, infoLog);
      std::cerr << "ERROR::SHADER_PROGRAM: Failed to link shader program.\n" << infoLog << std::endl;
    }
  }
}

Shader::Shader() {}

Shader::Shader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath) {
  load(vertexShaderFilePath, fragmentShaderFilePath);
}

void Shader::load(std::string vertexShaderFilePath, std::string fragmentShaderFilePath) {

  std::ifstream vertexShaderifstream(vertexShaderFilePath);
  std::ifstream fragmentShaderifstream(fragmentShaderFilePath);

  if (!vertexShaderifstream.is_open()) {
    std::cerr << "ERROR::IO: Failed to open vertex shader file.\n";
    return;
  }

  if (!fragmentShaderifstream.is_open()) {
    std::cerr << "ERROR::IO: Failed to open fragment shader file.\n";
    return;
  }

  std::stringstream vertexShaderStream, fragmentShaderStream;
  std::string vertexShaderSource, fragmentShaderSource;
  
  vertexShaderStream << vertexShaderifstream.rdbuf();
  fragmentShaderStream << fragmentShaderifstream.rdbuf();

  vertexShaderSource = vertexShaderStream.str();
  fragmentShaderSource = fragmentShaderStream.str();

  const char* vertexShaderSourceCStr = vertexShaderSource.c_str();
  const char* fragmentShaderSourceCStr = fragmentShaderSource.c_str();

  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, nullptr);
  glCompileShader(vertexShader);
  checkShaderCompileStatus(vertexShader);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSourceCStr, nullptr);
  glCompileShader(fragmentShader);
  checkShaderCompileStatus(fragmentShader);

  this->shaderProgram = glCreateProgram();
  glAttachShader(this->shaderProgram, vertexShader);
  glAttachShader(this->shaderProgram, fragmentShader);
  glLinkProgram(this->shaderProgram);
  checkShaderCompileStatus(this->shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shader::use() {
  glUseProgram(this->shaderProgram);
}

GLuint Shader::getShaderProgram() {
  return this->shaderProgram;
}