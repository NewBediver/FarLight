#version 330 core

layout(location = 0) out vec4 a_Color;

in vec3 v_Position;
in vec4 v_Color;

void main()
{
	a_Color = vec4(v_Position + 0.5, 1.0);
	a_Color = v_Color;
}