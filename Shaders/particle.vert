#version 450 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 velocity;
layout (location = 2) in float weight;

uniform vec4 particle_color;
uniform mat4 view;

out Vertex
{
  vec4 color;
  float weight;
} vertex;

void main()
{
  gl_Position = view * vec4( position , 1 );
  vertex.color = particle_color;
  vertex.weight = weight;
}
