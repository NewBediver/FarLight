#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class AtlasTile final
	{
	public:
		AtlasTile(const AtlasTile&) = delete;
		AtlasTile(AtlasTile&&) = delete;
		AtlasTile& operator=(const AtlasTile&) = delete;
		AtlasTile& operator=(AtlasTile&&) = delete;

		explicit AtlasTile(const Ref<Texture2D>& texture, std::array<glm::vec2, 4>&& textureCoords) noexcept
			: m_Texture(texture)
			, m_TextureCoords(textureCoords)
		{
			FL_CORE_ASSERT(texture != nullptr, "Texture should be instanciated!");
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

		const Ref<Texture2D>& GetTexture() const noexcept { return m_Texture; }

	private:
		Ref<Texture2D> m_Texture;

		// LowerLeft -> LowerRight -> UpperRight -> UpperLeft
		std::array<glm::vec2, 4> m_TextureCoords;
	};
}