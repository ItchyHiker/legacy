#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 FragColor;

// Texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;
void main()
{
    // Linearly interpolate between both textures (second texture is only slightly combined)
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.5);
}
