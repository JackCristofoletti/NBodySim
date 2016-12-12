#version 450

layout (points) in;
layout (triangle_strip) out;
layout (max_vertices = 4) out;

uniform mat4 projection;
uniform float size; // Particle size


out Vertex
{
  vec4 color;
  float weight;
} vertex[];

out vec2 tex_coords;
out vec4 color;

void main (void)
{
  const vec4 position = gl_in[0].gl_Position;
  const float width =  size;
  const float height = size;

  gl_Position = projection *  (position + vec4(-width, -height, 0, 0));
  tex_coords = vec2(0.0, 0.0);
  color = vertex[0].color;
  EmitVertex();

  gl_Position = projection * (position + vec4(-width, height, 0, 0));
  tex_coords = vec2(0.0, 1.0);
  color = vertex[0].color;
  EmitVertex();

  gl_Position = projection *  (position + vec4(width, -height, 0, 0));
  tex_coords = vec2(1.0, 0.0);
  color = vertex[0].color;
  EmitVertex();

  gl_Position = projection *  (position + vec4(width, height, 0, 0));
  tex_coords = vec2(1.0, 1.0);
  color = vertex[0].color;
  EmitVertex();

  EndPrimitive();
}
