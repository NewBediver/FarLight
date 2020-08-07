// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Batch.h"

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

#include <glad/glad.h>

namespace FarLight
{
	Batch::Batch(unsigned maxVertices, unsigned maxIndices, const BufferLayout& layout, const Ref<Shader>& shader, const Ref<Texture2D> texture)
		: m_MaxVertices(maxVertices)
		, m_UsedVertices(0)
		, m_MaxIndices(maxIndices)
		, m_UsedIndices(0)
		, m_VAO(nullptr)
		, m_VBO(nullptr)
		, m_EBO(nullptr)
		, m_Configuration(layout, shader, texture)
	{
		FL_CORE_ASSERT(m_MaxVertices >= 1000 && m_MaxIndices >= 1000, "Batch is too small. Choose a number >= 1000.");

		m_VAO = VertexArray::Create();
		m_VAO->Bind();

		m_VBO = VertexBuffer::Create(m_MaxVertices * m_Configuration.Layout.GetStride(), layout);
		m_EBO = IndexBuffer::Create(maxIndices);

		m_VAO->AddVertexBuffer(m_VBO);
		m_VAO->SetIndexBuffer(m_EBO);
	}

	void Batch::AddData(unsigned numVertices, const float* verticesData, unsigned numIndices, unsigned* indicesData)
	{
		FL_CORE_ASSERT(IsEnoughSlots(numVertices, numIndices), "Current batch doesn't have enought slots for current data!");

		m_VAO->Bind();

		int offset = m_UsedVertices;
		for (unsigned i = 0; i < numIndices; ++i) indicesData[i] += offset;

		m_VBO->AddSubData(verticesData, numVertices * m_Configuration.Layout.GetStride());
		m_UsedVertices += numVertices;

		m_EBO->AddSubData(indicesData, numIndices);
		m_UsedIndices += numIndices;
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