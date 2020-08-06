#version 330 core

in vec2 v_TextureCoordinates;
in vec4 v_Color;

uniform float u_TilingFactor;
uniform sampler2D u_Texture;

out vec4 f_Color;

void main()
{
	f_Color = texture(u_Texture, v_TextureCoordinates * u_TilingFactor) * v_Color;
}

