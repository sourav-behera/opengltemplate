#version 430 core

layout (location = 0) in vec3 Position;
// layout (location = 1) in vec2 texCoord;
layout (location = 1) in vec3 normal;

// out vec2 otexCoord;
out vec3 vnormal;
out vec3 vfragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(Position, 1.0);
    vnormal = mat3(transpose(inverse(model))) * normal;
    vfragPos = vec3(model * vec4(Position, 1.0));
    // otexCoord = texCoord;
}

