#version 430 core

out vec4 fragColor;
in vec3 vnormal;

uniform vec3 lightPos;
uniform vec3 viewPos;
in vec3 vfragPos;

// in vec2 otexCoord;
// uniform sampler2D Texture;

void main() {
    vec3 materialColor = vec3(1.0, 0.5, 0.31);
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    float ambientStrength = 0.1;
    float specularStrength = 0.5;

    vec3 norm = normalize(vnormal);
    vec3 lightDir = normalize(lightPos - vfragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 viewDir = normalize(viewPos - vfragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 ambient = ambientStrength * lightColor;

    vec3 resultColor = (ambient + diffuse + specular) * materialColor;
    fragColor = vec4(resultColor, 1.0);

    // fragColor = texture(Texture, otexCoord);
}
