#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TextureCoordinates;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

out vec2 v_TextureCoordinates;

void main()
{
	v_TextureCoordinates = a_TextureCoordinates;
	gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1.0);
}