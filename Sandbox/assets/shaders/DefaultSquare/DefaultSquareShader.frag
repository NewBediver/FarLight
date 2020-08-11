#version 330 core

in vec4 v_Color;
in vec2 v_TextureCoordinates;
in float v_TextureId;
in float v_TilingFactor;

uniform sampler2D u_Textures[32];

out vec4 f_Color;

void main()
{
	f_Color = texture(u_Textures[int(v_TextureId)], v_TextureCoordinates * v_TilingFactor) * v_Color;
}