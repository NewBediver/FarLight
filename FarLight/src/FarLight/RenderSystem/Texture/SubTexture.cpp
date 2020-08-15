// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "flpch.h"

#include "SubTexture.h"

namespace FarLight
{
	Ref<SubTexture> SubTexture::Create(const Ref<Texture2D>& texture, const glm::vec2& tileSize, const glm::vec2& offset, const glm::vec2& sizeInTileUnits) noexcept
	{
		return CreateRef<SubTexture>(texture, tileSize, offset, sizeInTileUnits);
	}
	SubTexture::SubTexture(const Ref<Texture2D>& texture, const glm::vec2& tileSize, const glm::vec2& offset, const glm::vec2& sizeInTileUnits) noexcept
		: m_Texture(texture)
		, m_TileSize(tileSize)
		, m_SizeInTileUnits(sizeInTileUnits)
		, m_Size(glm::vec2(tileSize.x * sizeInTileUnits.x, tileSize.y * sizeInTileUnits.y))
		, m_Offset(offset)
	{
		FL_PROFILE_FUNCTION();

		float leftOffset = offset.x;
		float upOffset = offset.y;

		// Lower Left
		m_TextureCoords[0] = { (leftOffset + m_Offset.x * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + m_Offset.y * m_TileSize.y) / m_Texture->GetHeight() };
		// Lower right
		m_TextureCoords[1] = { (leftOffset + (m_Offset.x + m_SizeInTileUnits.x) * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + m_Offset.y * m_TileSize.y) / m_Texture->GetHeight() };
		// UpperRight
		m_TextureCoords[2] = { (leftOffset + (m_Offset.x + m_SizeInTileUnits.x) * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + (m_Offset.y + m_SizeInTileUnits.y) * m_TileSize.y) / m_Texture->GetHeight() };
		// UpperLeft
		m_TextureCoords[3] = { (leftOffset + m_Offset.x * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + (m_Offset.y + m_SizeInTileUnits.y) * m_TileSize.y) / m_Texture->GetHeight() };
	}
}