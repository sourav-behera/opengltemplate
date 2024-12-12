#version 430 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec2 texCoord;

out vec2 otexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(Position, 1.0);
    // gl_Position = model * vec4(Position, 1.0);
    // gl_Position = vec4(Position, 1.0);
    otexCoord = texCoord;
}

