// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "AtlasMap.h"

namespace FarLight
{
	AtlasMap::AtlasMap(const Ref<Texture2D>& texture, const glm::vec2 tileSize, const glm::vec2& distanceBetweenTilesInPixels) noexcept
		: m_Texture(texture)
		, m_TileSize(tileSize)
		, m_DistanceBetweenTilesInPixels(distanceBetweenTilesInPixels)
	{
		for (unsigned y = 0; y * (distanceBetweenTilesInPixels.y + tileSize.y) < m_Texture->GetHeight(); ++y)
		{
			m_AtlasTiles.emplace_back();
			for (unsigned x = 0; x * (distanceBetweenTilesInPixels.x + tileSize.x) < m_Texture->GetWidth(); ++x)
			{
				AtlasTileData data;
				data.Offset = { x, y };
				m_AtlasTiles.back().push_back(data);
			}
		}
	}

	const Ref<AtlasTile> AtlasMap::GetAtlasTile(const glm::vec2& offset, const glm::vec2& sizeInTileUnits) noexcept
	{
		FL_CORE_ASSERT(offset.y < m_AtlasTiles.size() && offset.x < m_AtlasTiles.front().size(), "Texture with this coordinate doesn't exist!");

		if (m_AtlasTiles[offset.y][offset.x].SizeInTiles != sizeInTileUnits)
		{
			m_AtlasTiles[offset.y][offset.x].SizeInTiles = sizeInTileUnits;

			unsigned leftOffset = offset.x * m_DistanceBetweenTilesInPixels.x;
			unsigned upOffset = offset.y * m_DistanceBetweenTilesInPixels.y;

			// Lower left
			m_AtlasTiles[offset.y][offset.x].TextureCoords[0] = { (leftOffset + offset.x * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + offset.y * m_TileSize.y) / m_Texture->GetHeight() };
			// Lower right
			m_AtlasTiles[offset.y][offset.x].TextureCoords[1] = { (leftOffset + (offset.x + sizeInTileUnits.x) * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + offset.y * m_TileSize.y) / m_Texture->GetHeight() };
			// UpperRight
			m_AtlasTiles[offset.y][offset.x].TextureCoords[2] = { (leftOffset + (offset.x + sizeInTileUnits.x) * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + (offset.y + sizeInTileUnits.y) * m_TileSize.y) / m_Texture->GetHeight() };
			// UpperLeft
			m_AtlasTiles[offset.y][offset.x].TextureCoords[3] = { (leftOffset + offset.x * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + (offset.y + sizeInTileUnits.y) * m_TileSize.y) / m_Texture->GetHeight() };
		}

		return CreateRef<AtlasTile>(m_Texture, m_AtlasTiles[offset.y][offset.x].TextureCoords);
	}
}
