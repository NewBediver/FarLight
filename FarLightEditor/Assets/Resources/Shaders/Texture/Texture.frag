#version 330 core

in vec2 v_TexCoord;

uniform sampler2D u_Texture;

out vec4 a_color;

void main()
{
	a_color = texture(u_Texture, v_TexCoord);
}