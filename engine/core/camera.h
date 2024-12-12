#ifndef CAMERA_H
#define CAMERA_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera{
  private:
    float near, far;
    float fov;
    float cameraMoveSpeed;
    float cameraSensitivity;
    float yaw, pitch;
    glm::vec3 worldUp;
    glm::vec3 cameraPosition;
    glm::vec3 cameraUp, cameraFront, cameraRight;
    glm::mat4 viewMatrix, projectionMatrix;
    void updateViewMatrix(); 

  public:
    Camera();
    void moveCamera(GLFWwindow *window, float &deltaTime);
    void rotateCamera(float &xoffset, float &yoffset);
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
};

#endif