#pragma once

#include "FarLight/Core/Core.h"
#include "FarLight/Profiling/Instrumentor.h"

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

		explicit AtlasTile(const Ref<Texture2D>& texture, const std::array<glm::vec2, 4>& textureCoords) noexcept
			: m_Texture(texture)
			, m_TextureCoords(textureCoords)
		{ }

		const std::array<glm::vec2, 4>& GetCoordinates() const noexcept { return m_TextureCoords; }
		const glm::vec2& GetLowerLeftCoordinate() const noexcept { return m_TextureCoords[0]; }
		const glm::vec2& GetLowerRightCoordinate() const noexcept { return m_TextureCoords[1]; }
		const glm::vec2& GetUpperRightCoordinate() const noexcept { return m_TextureCoords[2]; }
		const glm::vec2& GetUpperLeftCoordinate() const noexcept { return m_TextureCoords[3]; }

		const Ref<Texture2D>& GetTexture() const noexcept { return m_Texture; }

	private:
		// LowerLeft -> LowerRight -> UpperRight -> UpperLeft
		std::array<glm::vec2, 4> m_TextureCoords;

		Ref<Texture2D> m_Texture;
	};
}