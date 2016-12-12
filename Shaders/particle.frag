#version 450 core
uniform sampler2D tex0;
uniform vec3 bloom_color_exposure;

in vec2 tex_coords;
in vec4 color;

layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;

const vec4 particle_color = vec4( 0.0 ,0.545, 0.545 , 1.0); //dark cyan

void main (void)
{
  vec4 t = texture(tex0, tex_coords); //alpha teture
  FragColor =  t * particle_color;
  // Bloom check
  float brightness = dot(FragColor.rgb, bloom_color_exposure );
 if(brightness > 1.0)
        BrightColor = vec4(FragColor.rgb, 1.0);
}
