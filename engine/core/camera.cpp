#include "glm/fwd.hpp"
#include <camera.h>

Camera::Camera() {
  near = 0.1f;
  far = 100.0f;
  fov = 60.0f;

  cameraMoveSpeed = 2.5f;
  cameraSensitivity = 0.1f;

  yaw = -90.0f;
  pitch = 0.0f;
  
  worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
  cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
  cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);
  cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
  cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);

  projectionMatrix = glm::perspective(glm::radians(fov), 800.0f/600.0f, near, far);
  viewMatrix = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}

void Camera::moveCamera(GLFWwindow *window, float &deltaTime) {
  glm::vec3 direction = glm::vec3(0.0f);
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) direction = cameraFront;
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) direction = -cameraFront;
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) direction = -cameraRight;
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) direction = cameraRight;
  if(direction != glm::vec3(0.0f)) direction = glm::normalize(direction);
  cameraPosition += cameraMoveSpeed * deltaTime * direction;
  updateViewMatrix();
}

void Camera::rotateCamera(float &xoffset, float &yoffset) {
  xoffset *= cameraSensitivity;
  yoffset *= cameraSensitivity;
  
  yaw += xoffset;
  pitch += yoffset;
  
  if (pitch > 89.0f) pitch = 89.0f;
  if (pitch < -89.0f) pitch = -89.0f;
  
  glm::vec3 front;
  front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  front.y = sin(glm::radians(pitch));
  front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  cameraFront = glm::normalize(front);
  cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
  cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
}

void Camera::updateViewMatrix() {
  viewMatrix = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}

glm::mat4 Camera::getViewMatrix() {
  return viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix() {
  return projectionMatrix;
}
