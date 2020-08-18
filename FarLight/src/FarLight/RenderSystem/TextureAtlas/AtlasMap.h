#pragma once

#include <vector>

#include "FarLight/RenderSystem/TextureAtlas/AtlasTile.h"

#include "FarLight/Core/Core.h"

namespace FarLight
{
	class AtlasMap final
	{
	public:
		static Ref<AtlasMap> Create(const Ref<Texture2D>& texture, const glm::vec2& tileSize, const glm::vec2& distanceBetweenTilesInPixels = glm::vec2(1)) noexcept;

		AtlasMap(const AtlasMap&) = delete;
		AtlasMap(AtlasMap&&) = delete;
		AtlasMap& operator==(const AtlasMap&) = delete;
		AtlasMap& operator==(AtlasMap&&) = delete;

		explicit AtlasMap(const Ref<Texture2D>& texture, const glm::vec2& tileSize, const glm::vec2& distanceBetweenTilesInPixels) noexcept;

		const Ref<AtlasTile>& GetAtlasTile(const glm::vec2& offset, const glm::vec2& sizeInTileUnits = glm::vec2(1)) noexcept;

		const Ref<Texture2D>& GetTexture() const noexcept { return m_Texture; }

		const glm::vec2& GetTileSize() const noexcept { return m_TileSize; }
		float GetTileWidth() const noexcept { return m_TileSize.x; }
		float GetTileHeight() const noexcept { return m_TileSize.y; }

		const glm::vec2 GetDistanceBetweenTiles() const noexcept { return m_DistanceBetweenTilesInPixels; }
		const unsigned GetDistanceBetweenTilesX() const noexcept { return static_cast<unsigned>(m_DistanceBetweenTilesInPixels.x); }
		const unsigned GetDistanceBetweenTilesY() const noexcept { return static_cast<unsigned>(m_DistanceBetweenTilesInPixels.y); }

	private:
		Ref<Texture2D> m_Texture;

		glm::vec2 m_TileSize;
		glm::vec2 m_DistanceBetweenTilesInPixels;

		struct AtlasTileData final
		{
			Ref<AtlasTile> Tile;
			glm::vec2 Offset;
			glm::vec2 SizeInTiles;

			explicit AtlasTileData(glm::vec2&& offset) noexcept
				: Tile(nullptr)
				, SizeInTiles({ 0, 0 })
			{
				Offset = offset;
			}
		};

		std::vector<std::vector<AtlasTileData>> m_AtlasTiles;
	};
}