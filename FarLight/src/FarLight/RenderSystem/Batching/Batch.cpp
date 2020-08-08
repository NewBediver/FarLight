// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Batch.h"

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

#include <glad/glad.h>

namespace FarLight
{
	Batch::Batch(const BufferLayout& layout, const Ref<Shader>& shader, const Ref<Texture2D> texture, unsigned maxVertices, unsigned maxIndies)
		: m_MaxVertices(maxVertices)
		, m_UsedVertices(0)
		, m_MaxIndices(maxIndies)
		, m_UsedIndices(0)
		, m_VAO(VertexArray::Create())
		, m_VBO(VertexBuffer::Create(maxVertices * layout.GetStride(), layout))
		, m_EBO(IndexBuffer::Create(maxIndies))
		, m_Configuration(layout, shader, texture, 0)
	{
		FL_CORE_ASSERT(m_MaxVertices >= 1000 && m_MaxIndices >= 1000, "Batch is too small. Choose a number >= 1000.");

		m_VAO->Bind();

		m_VAO->AddVertexBuffer(m_VBO);
		m_VAO->SetIndexBuffer(m_EBO);
	}

	void Batch::AddData(unsigned numVertices, const float* verticesData, unsigned numIndices, const unsigned* indicesData)
	{
		FL_CORE_ASSERT(IsEnoughSlots(numVertices, numIndices), "Current batch doesn't have enought slots for current data!");

		// MUST BE DELETED
		unsigned* indices = new unsigned[numIndices];

		int offset = m_UsedVertices;
		for (unsigned i = 0; i < numIndices; ++i)
			indices[i] = indicesData[i] + offset;

		m_VAO->Bind();

		m_VBO->AddSubData(verticesData, numVertices * m_Configuration.Layout.GetStride());
		m_UsedVertices += numVertices;

		m_EBO->AddSubData(indices, numIndices);
		m_UsedIndices += numIndices;

		delete[] indices;
	}

	void Batch::SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix)
	{
		m_Configuration.Shad->Bind();
		m_Configuration.Shad->SetMat4("u_Transformation.View", viewMatrix);
		m_Configuration.Shad->SetMat4("u_Transformation.Projection", projectionMatrix);
	}

	void Batch::SetTextureSlot(int slot)
	{
		m_Configuration.Shad->Bind();
		m_Configuration.Shad->SetInt("u_Texture", slot);
	}

	void Batch::Render()
	{
		if (m_UsedIndices == 0 || m_UsedVertices == 0) return;

		m_Configuration.Shad->Bind();
		m_Configuration.Texture->Bind(0);
		m_VAO->Bind();

		RenderCommand::DrawIndexed(m_VAO);
	}

	void Batch::Clear()
	{
		m_EBO->SetCount(0);
		m_VBO->SetOffset(0);
		m_UsedIndices = 0;
		m_UsedVertices = 0;
	}
}