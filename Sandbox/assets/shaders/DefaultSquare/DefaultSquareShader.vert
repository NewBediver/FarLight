#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TextureCoordinates;

out vec2 v_TextureCoordinates;
out vec4 v_Color;

struct Transformation
{
	mat4 View;
	mat4 Projection;
};

uniform Transformation u_Transformation;

void main()
{
	v_TextureCoordinates = a_TextureCoordinates;
	v_Color = a_Color;
	gl_Position = u_Transformation.Projection * u_Transformation.View * vec4(a_Position, 1.0);
}