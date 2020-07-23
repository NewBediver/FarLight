#version 330 core

in vec3 v_Position;
in vec4 v_Color;

out vec4 a_Color;

void main()
{
	a_Color = vec4(v_Position + 0.5, 1.0);
	a_Color = v_Color;
}