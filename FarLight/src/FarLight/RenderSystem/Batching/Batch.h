#pragma once

#include <vector>

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"
#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"

namespace FarLight
{
	struct BatchConfiguration
	{
		unsigned RenderType;
		int Priority;
		Ref<Texture2D> Texture;
		glm::mat4 Model;
		glm::mat4 View;
		glm::mat4 Projection;

		BatchConfiguration(unsigned renderType, int priority, const Ref<Texture2D>& texture)
			: RenderType(renderType)
			, Priority(priority)
			, Texture(texture)
			, Model(glm::mat4(1.0f))
			, View(glm::mat4(1.0f))
			, Projection(glm::mat4(1.0f))
		{ }

		bool operator==(const BatchConfiguration& other) const
		{
			return RenderType == other.RenderType
				&& Priority == other.Priority
				&& Texture->GetID() == other.Texture->GetID()
				&& Model == other.Model
				&& View == other.View
				&& Projection == other.Projection;
		}

		bool operator!=(const BatchConfiguration& other) const
		{
			return !(*this == other);
		}
	};

	struct GuiVertex
	{
		glm::vec3 Position;
		glm::vec4 Color;
		glm::vec2 Texture;

		GuiVertex(glm::vec3 position, glm::vec4 color, glm::vec2 texture)
			: Position(position)
			, Color(color)
			, Texture(texture)
		{ }
	};

	class Batch
	{
	public:
		Batch(unsigned maxVertices, unsigned maxIndices);

		bool IsBatchConfiguration(const BatchConfiguration& config) const { return config == m_Configuration; }
		bool IsEmpty() const { return m_UsedVertices == 0; }
		bool IsEnoughSlots(unsigned numVertices, unsigned numIndices) const { return m_UsedVertices + numVertices <= m_MaxVertices && numIndices + m_UsedIndices <= m_MaxIndices; }

		void SetConfiguration(const BatchConfiguration& config) { m_Configuration = config; }
		const BatchConfiguration& GetConfiguration() const { return m_Configuration; }

		void AddData(unsigned numVertices, const float* verticesData, unsigned numIndices, const unsigned* indicesData);
		void Render();

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