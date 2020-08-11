#pragma once

#include <vector>

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"
#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"
#include "FarLight/RenderSystem/Shader/Shader.h"

namespace FarLight
{
	struct VertexData
	{
		glm::vec3 Position = { 0.0f, 0.0f, 0.0f };
		glm::vec4 Color = { 1.0f, 1.0f, 1.0f, 1.0f };
		glm::vec2 TextureCoordinates = { 0.0f, 0.0f };
		float TilingFactor = 1.0f;
	};

	struct BatchConfiguration final
	{
		BufferLayout Layout;
		std::vector<Ref<Texture2D>> Textures;
		Ref<Shader> Shad;
		unsigned StartTextureIndex;
		unsigned MaxTextureArraySize;

		explicit BatchConfiguration(const BufferLayout& layout, const std::vector<Ref<Texture2D>>& textures, const Ref<Shader>& shader) noexcept
			: Layout(layout)
			, Textures(textures)
			, Shad(shader)
			, StartTextureIndex(1)
			, MaxTextureArraySize(32)
		{ }

		explicit BatchConfiguration(const BatchConfiguration& config) noexcept
			: Layout(config.Layout)
			, Textures(config.Textures)
			, Shad(config.Shad)
			, StartTextureIndex(config.StartTextureIndex)
			, MaxTextureArraySize(config.MaxTextureArraySize)
		{ }

		BatchConfiguration& operator=(const BatchConfiguration& config) noexcept
		{
			if (config == *this) return *this;
			BatchConfiguration cfg(config.Layout, config.Textures, config.Shad);
			cfg.StartTextureIndex = config.StartTextureIndex;
			cfg.MaxTextureArraySize = config.MaxTextureArraySize;
			return cfg;
		}

		bool operator==(const BatchConfiguration& other) const noexcept
		{
			return Shad->GetID() == other.Shad->GetID()
				&& MaxTextureArraySize == other.MaxTextureArraySize
				&& Layout == other.Layout;
		}
	};

	class Batch final
	{
	public:
		Batch(const Batch&) = delete;
		Batch& operator=(const Batch&) = delete;
		Batch& operator=(Batch&&) = delete;

		Batch(Batch&&) noexcept = default;

		explicit Batch(const BatchConfiguration& config, unsigned maxVertices = 10000, unsigned maxIndies = 20000) noexcept;

		void AddData(const std::vector<VertexData>& vertices, const std::vector<unsigned>& indices, const Ref<Texture2D>& texture) noexcept;

		void Render() noexcept;
		void Clear() noexcept;

		constexpr
		bool IsEmpty() const noexcept { return m_UsedVertices == 0 && m_UsedIndices == 0; }
		constexpr
		bool HasFreeTextureSlots() const noexcept { return m_Configuration.StartTextureIndex < m_Configuration.MaxTextureArraySize; }
		constexpr
		bool HasFreeVertexSlots(unsigned numVertices) const noexcept { return m_UsedVertices + numVertices <= m_MaxVertices; }
		constexpr
		bool HasFreeIndexSlots(unsigned numIndices) const noexcept { return  m_UsedIndices + numIndices <= m_MaxIndices; }

		void SetConfiguration(const BatchConfiguration& config) noexcept { m_Configuration = config; }
		constexpr
		const BatchConfiguration& GetConfiguration() const noexcept { return m_Configuration; }

		void SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) const noexcept;

		bool operator==(const Batch& other) const noexcept
		{
			return m_Configuration == other.m_Configuration;
		}

	private:
		void AddTexture(const Ref<Texture2D>& texture) noexcept;

		unsigned m_MaxVertices;
		unsigned m_MaxIndices;
		unsigned m_UsedVertices;
		unsigned m_UsedIndices;
		Ref<VertexArray> m_VAO;
		Ref<VertexBuffer> m_VBO;
		Ref<IndexBuffer> m_EBO;
		BatchConfiguration m_Configuration;
	};
}