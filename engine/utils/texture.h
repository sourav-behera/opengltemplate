#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

class Texture {
    private:
        GLuint texture;
    public:
        Texture();
        Texture(const char* textureFilePath);
        void load(const char* textureFilePath);
        void use();
};

#endif