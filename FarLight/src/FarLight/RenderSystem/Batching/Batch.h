#pragma once

#include <vector>

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"
#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"
#include "FarLight/RenderSystem/Shader/Shader.h"

namespace FarLight
{
	struct BatchConfiguration
	{
		BufferLayout Layout;
		Ref<Texture2D> Texture;
		Ref<Shader> Shad;

		BatchConfiguration(const BufferLayout& layout, const Ref<Shader>& shader, const Ref<Texture2D>& texture)
			: Layout(layout)
			, Texture(texture)
			, Shad(shader)
		{ }
	};

	class Batch
	{
	public:
		Batch(unsigned maxVertices, unsigned maxIndices, const BufferLayout& layout, const Ref<Shader>& shader, const Ref<Texture2D> texture);

		bool IsEmpty() const { return m_UsedVertices == 0 && m_UsedIndices == 0; }
		bool IsEnoughSlots(unsigned numVertices, unsigned numIndices) const { return m_UsedVertices + numVertices <= m_MaxVertices && numIndices + m_UsedIndices <= m_MaxIndices; }

		void SetConfiguration(const BatchConfiguration& config) { m_Configuration = config; }
		const BatchConfiguration& GetConfiguration() const { return m_Configuration; }

		void AddData(unsigned numVertices, const float* verticesData, unsigned numIndices, unsigned* indicesData);

		void SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);
		void SetTextureSlot(int slot);

		void Render();
		void Clear();

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