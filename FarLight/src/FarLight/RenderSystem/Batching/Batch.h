#pragma once

#include <vector>

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"
#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"
#include "FarLight/RenderSystem/Shader/Shader.h"

namespace FarLight
{
	struct BatchConfiguration final
	{
		BufferLayout Layout;
		Ref<Texture2D> Texture;
		Ref<Shader> Shad;
		unsigned TextureSlot;

		BatchConfiguration(const BufferLayout& layout, const Ref<Shader>& shader, const Ref<Texture2D>& texture, unsigned textureSlot) noexcept
			: Layout(layout)
			, Texture(texture)
			, Shad(shader)
			, TextureSlot(textureSlot)
		{ }

		bool operator==(const BatchConfiguration& other) const noexcept
		{
			return Texture->GetID() == other.Texture->GetID()
				&& Shad->GetID() == other.Shad->GetID()
				&& Layout == other.Layout
				&& TextureSlot == other.TextureSlot;
		}
	};

	class Batch final
	{
	public:
		Batch(const Batch&) = delete;
		Batch& operator=(const Batch&) = delete;
		Batch& operator=(Batch&&) = delete;

		Batch(Batch&&) noexcept = default;

		explicit Batch(const BufferLayout& layout, const Ref<Shader>& shader, const Ref<Texture2D> texture, unsigned maxVertices = 10000, unsigned maxIndies = 20000) noexcept;

		constexpr
		bool IsEmpty() const noexcept { return m_UsedVertices == 0 && m_UsedIndices == 0; }
		constexpr
		bool IsEnoughSlots(unsigned numVertices, unsigned numIndices) const noexcept { return m_UsedVertices + numVertices <= m_MaxVertices && numIndices + m_UsedIndices <= m_MaxIndices; }

		void SetConfiguration(const BatchConfiguration& config) noexcept { m_Configuration = config; }
		constexpr
		const BatchConfiguration& GetConfiguration() const noexcept { return m_Configuration; }

		void AddData(unsigned numVertices, const float* verticesData, unsigned numIndices, const unsigned* indicesData) noexcept;

		void SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) noexcept;
		void SetTextureSlot(int slot) noexcept;

		void Render() noexcept;
		void Clear() noexcept;

	private:
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