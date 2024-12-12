#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window{
    private:
        float height, width;
        const char *title;
        float aspectRatio;
        GLFWwindow *window;
        bool firstMouse;
        float xoffset, yoffset;
        

    public:
        Window(float width, float height, const char *title);
        void init();
        void update();
        void close();
        GLFWwindow *getWindow();
        std::vector<float> getMouseOffset();
};

#endif