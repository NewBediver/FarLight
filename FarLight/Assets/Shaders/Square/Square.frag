#version 330 core

in vec3 v_Position;

uniform vec4 u_Color;

out vec4 a_Color;

void main()
{
	a_Color = u_Color;
}