#pragma once

#include <vector>

#include "FarLight/RenderSystem/TextureAtlas/AtlasTile.h"

#include "FarLight/Core/Core.h"

namespace FarLight
{
	class AtlasMap final
	{
	public:
		AtlasMap(const AtlasMap&) = delete;
		AtlasMap(AtlasMap&&) = delete;
		AtlasMap& operator==(const AtlasMap&) = delete;
		AtlasMap& operator==(AtlasMap&&) = delete;

		AtlasMap(const Ref<Texture2D>& texture, const glm::vec2 tileSize, const glm::vec2& distanceBetweenTilesInPixels = glm::vec2(1)) noexcept;

		const Ref<AtlasTile> GetAtlasTile(const glm::vec2& offset, const glm::vec2& sizeInTileUnits = glm::vec2(1)) noexcept;

	private:
		Ref<Texture2D> m_Texture;

		glm::vec2 m_TileSize;
		glm::vec2 m_DistanceBetweenTilesInPixels;

		struct AtlasTileData final
		{
			glm::vec2 Offset;
			glm::vec2 SizeInTiles = glm::vec2(0);
			std::array<glm::vec2, 4> TextureCoords =
			{
					glm::vec2(-1),
					glm::vec2(-1),
					glm::vec2(-1),
					glm::vec2(-1),
			};
		};

		std::vector<std::vector<AtlasTileData>> m_AtlasTiles;
	};
}