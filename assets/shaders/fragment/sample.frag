#version 430 core

out vec4 fragColor;
in vec2 otexCoord;

uniform sampler2D Texture;

void main() {
    // fragColor = vec4(1.0, 1.0, 1.0, 1.0);
    fragColor = texture(Texture, otexCoord);
}
