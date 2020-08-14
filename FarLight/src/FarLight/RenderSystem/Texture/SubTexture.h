#pragma once

#include "FarLight/Core/Core.h"
#include "FarLight/Profiling/Instrumentor.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class SubTexture
	{
	public:
		static Ref<SubTexture> Create(const Ref<Texture2D>& texture, const glm::vec2& tileSize, const glm::vec2& offset, const glm::vec2& sizeInTileUnits = { 1, 1 }) noexcept;

		SubTexture(const SubTexture&) = delete;
		SubTexture(SubTexture&&) = delete;
		SubTexture& operator=(const SubTexture&) = delete;
		SubTexture& operator=(SubTexture&&) = delete;

		explicit SubTexture(const Ref<Texture2D>& texture, const glm::vec2& tileSize, const glm::vec2& offset, const glm::vec2& sizeInTileUnits) noexcept;

		float GetWidth() const noexcept { return m_Size.x; }
		float GetHeight() const noexcept { return m_Size.y; }

		const glm::vec2& GetUnitSize() const noexcept { return m_SizeInTileUnits; }
		const glm::vec2& GetTileSize() const noexcept { return m_TileSize; }
		const glm::vec2& GetTextureOffset() const noexcept { return m_Offset; }

		const std::array<glm::vec2, 4>& GetCoordinates() const noexcept { return m_TextureCoords; }
		const glm::vec2& GetLowerLeftCoordinate() const noexcept { return m_TextureCoords[0]; }
		const glm::vec2& GetLowerRightCoordinate() const noexcept { return m_TextureCoords[1]; }
		const glm::vec2& GetUpperRightCoordinate() const noexcept { return m_TextureCoords[2]; }
		const glm::vec2& GetUpperLeftCoordinate() const noexcept { return m_TextureCoords[3]; }

		const Ref<Texture2D>& GetTexture() const noexcept { return m_Texture; }

	private:

		glm::vec2 m_TileSize;
		glm::vec2 m_SizeInTileUnits;
		glm::vec2 m_Size;

		glm::vec2 m_Offset;

		// LowerLeft -> LowerRight -> UpperRight -> UpperLeft
		std::array<glm::vec2, 4> m_TextureCoords;

		Ref<Texture2D> m_Texture;
	};
}