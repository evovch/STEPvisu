#version 400

layout(points) in;
layout(points, max_vertices=1) out;

in vec4 vertex_Color[];
out vec3 geom_Color;


void main()
{
	gl_Position = gl_in[0].gl_Position;
	EmitVertex();
	EndPrimitive();
}
