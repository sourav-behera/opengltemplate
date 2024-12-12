#include <window.h>

namespace win {
    float xoffset = 0, yoffset = 0;
    bool firstMouse = true;
    float lastX = 400.0f, lastY = 300.0f;
    
    void cursorPositionCallback(GLFWwindow *window, double xpos, double ypos);
    void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    void framebufferSizeCallback(GLFWwindow *window, int width, int height);
}


Window::Window(float width, float height, const char *title) {
    this->width = width;
    this->height = height;
    this->title = title;
}

void Window::init() {
    if (!glfwInit()) {
        std::cout << "ERROR::GLFW: Failed to create window\n";
        exit(-1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_API, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!window) {
        std::cout << "ERROR::GLFW: Failed to create window\n";
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "ERROR::GLAD: Failed to initialize GLAD\n";
        exit(-1);
    }
    glfwSwapInterval(1);
    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, win::cursorPositionCallback);
    glfwSetKeyCallback(window, win::keyCallback);
    glfwSetFramebufferSizeCallback(window, win::framebufferSizeCallback);
}

void Window::update() {
    glfwPollEvents();
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::close() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow *Window::getWindow() {
    return window;
}

std::vector<float> Window::getMouseOffset() {
    std::vector<float> offset = {win::xoffset, win::yoffset};
    win::xoffset = 0;
    win::yoffset = 0;
    return offset;
}

void win::cursorPositionCallback(GLFWwindow *window, double xpos, double ypos) {
  if (firstMouse) {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }
  xoffset = xpos - lastX;
  yoffset = lastY - ypos;
  lastX = xpos;
  lastY = ypos;
}

void win::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }
}

void win::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}