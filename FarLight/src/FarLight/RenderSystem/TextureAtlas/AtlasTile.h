#pragma once

#include "AtlasMap.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class AtlasTile final
	{
	public:
		explicit AtlasTile(AtlasMap* atlasMap, std::array<glm::vec2, 4>&& textureCoords) noexcept
			: m_AtlasMap(atlasMap)
			, m_TextureCoords(textureCoords)
		{
			FL_CORE_ASSERT(textureCoords[0].x >= 0.0f && textureCoords[0].x <= 1.0f && textureCoords[0].y >= 0.0f && textureCoords[0].y <= 1.0f
				&& textureCoords[1].x >= 0.0f && textureCoords[1].x <= 1.0f && textureCoords[1].x > textureCoords[0].x && textureCoords[1].y >= 0.0f && textureCoords[1].y <= 1.0f && textureCoords[1].y == textureCoords[0].y
				&& textureCoords[2].x >= 0.0f && textureCoords[2].x <= 1.0f && textureCoords[2].x == textureCoords[1].x && textureCoords[2].y >= 0.0f && textureCoords[2].y <= 1.0f && textureCoords[2].y > textureCoords[1].y
				&& textureCoords[3].x >= 0.0f && textureCoords[3].x <= 1.0f && textureCoords[3].x == textureCoords[0].x && textureCoords[3].y >= 0.0f && textureCoords[3].y <= 1.0f && textureCoords[3].y == textureCoords[2].y
				, "Problems with texture coordinates!");
		}

		const std::array<glm::vec2, 4>& GetCoordinates() const noexcept { return m_TextureCoords; }
		const glm::vec2& GetLowerLeftCoordinate() const noexcept { return m_TextureCoords[0]; }
		const glm::vec2& GetLowerRightCoordinate() const noexcept { return m_TextureCoords[1]; }
		const glm::vec2& GetUpperRightCoordinate() const noexcept { return m_TextureCoords[2]; }
		const glm::vec2& GetUpperLeftCoordinate() const noexcept { return m_TextureCoords[3]; }

		const Ref<Texture2D>& GetTexture() const noexcept { return m_AtlasMap->m_Texture; }

	private:
		AtlasMap* m_AtlasMap;

		// LowerLeft -> LowerRight -> UpperRight -> UpperLeft
		std::array<glm::vec2, 4> m_TextureCoords;
	};
}