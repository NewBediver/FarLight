// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Batch.h"

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

#include <glad/glad.h>

namespace FarLight
{
	Batch::Batch(unsigned maxVertices, unsigned maxIndices, const BufferLayout& layout)
		: m_MaxVertices(maxVertices)
		, m_UsedVertices(0)
		, m_MaxIndices(maxIndices)
		, m_UsedIndices(0)
		, m_VAO(nullptr)
		, m_VBO(nullptr)
		, m_EBO(nullptr)
		, m_Configuration(GL_TRIANGLES, 0, Texture2D::Create(1, 1), layout)
	{
		FL_CORE_ASSERT(m_MaxVertices >= 1000 && m_MaxIndices >= 1000, "Batch is too small. Choose a number >= 1000.");

		m_VAO = VertexArray::Create();

		m_VBO = VertexBuffer::Create(m_MaxVertices * m_Configuration.Layout.GetSize(), layout);
		m_EBO = IndexBuffer::Create(maxIndices);

		m_VAO->AddVertexBuffer(m_VBO);
		m_VAO->SetIndexBuffer(m_EBO);
	}

	void Batch::AddData(unsigned numVertices, const float* verticesData, unsigned numIndices, const unsigned* indicesData)
	{
		FL_CORE_ASSERT(IsEnoughSlots(numVertices, numIndices), "Current batch doesn't have enought slots for current data!");

		m_VBO->AddSubData(verticesData, numVertices * m_Configuration.Layout.GetSize(), m_UsedVertices);
		m_UsedVertices += numVertices;

		m_EBO->AddSubData(indicesData, numIndices, m_UsedIndices);
		m_UsedIndices += numIndices;
	}

	void Batch::Render()
	{
		if (m_UsedIndices == 0 || m_UsedVertices == 0) return;
		RenderCommand::DrawIndexed(m_VAO);
	}

	void Batch::Clear()
	{
		m_EBO->SetCount(0);
		m_UsedIndices = 0;
		m_UsedVertices = 0;
	}
}