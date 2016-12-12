#version 450 core

layout (location = 0) uniform sampler2D scene;
layout (location = 1) uniform sampler2D bloom_blur_texture;

uniform bool bloom;
uniform float exposure;

out vec4 FragColor;
in vec2 v_tex_coords;

void main()
{
    const float gamma = 2.2;
    vec3 hdrColor = texture(scene, v_tex_coords).rgb;
    vec3 bloomColor = texture(bloom_blur_texture, v_tex_coords).rgb;
    if(bloom)
        hdrColor += bloomColor; // additive blending
    // tone mapping
    vec3 result = vec3(1.0) - exp(-hdrColor * exposure);
    // also gamma correct while we're at it
    result = pow(result, vec3(1.0 / gamma));
    FragColor = vec4(result, 1.0f);
}
