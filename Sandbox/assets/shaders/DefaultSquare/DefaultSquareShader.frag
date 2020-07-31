#version 330 core

in vec2 v_TextureCoordinates;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

out vec4 f_Color;

void main()
{
	f_Color = texture(u_Texture, v_TextureCoordinates) * u_Color;
}