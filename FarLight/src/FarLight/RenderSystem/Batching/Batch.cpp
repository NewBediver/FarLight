// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Batch.h"

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

#include <glad/glad.h>

namespace FarLight
{
	Batch::Batch(const BatchConfiguration& config, unsigned maxVertices, unsigned maxIndies) noexcept
		: m_MaxVertices(maxVertices)
		, m_UsedVertices(0)
		, m_MaxIndices(maxIndies)
		, m_UsedIndices(0)
		, m_VAO(VertexArray::Create())
		, m_VBO(VertexBuffer::Create(maxVertices * config.Layout.GetStride(), config.Layout))
		, m_EBO(IndexBuffer::Create(maxIndies))
		, m_Configuration(config)
	{
		FL_CORE_ASSERT(m_MaxVertices >= 1000 && m_MaxIndices >= 1000, "Batch is too small. Choose a number >= 1000.");

		m_VAO->Bind();

		m_VAO->AddVertexBuffer(m_VBO);
		m_VAO->SetIndexBuffer(m_EBO);
	}

	void Batch::AddData(const std::vector<VertexData>& vertices, const std::vector<unsigned>& indices, const Ref<Texture2D>& texture) noexcept
	{
		FL_CORE_ASSERT(HasFreeTextureSlots() && HasFreeVertexSlots(vertices.size()) && HasFreeIndexSlots(indices.size()), "Current batch doesn't have enought slots for current data!");

		// MUST BE DELETED
		std::vector<unsigned> inds(indices.size());
		std::vector<float> verts(vertices.size() * m_Configuration.Layout.GetStride());

		unsigned offset = m_UsedVertices;
		for (unsigned i = 0; i < indices.size(); ++i)
			inds[i] = indices[i] + offset;

		int textureId = -1;
		if (texture == nullptr) textureId = 0;
		else
		{
			for (unsigned i = 0; i < m_Configuration.StartTextureIndex; ++i)
			{
				if (m_Configuration.Textures[i]->GetID() == texture->GetID())
				{
					textureId = i;
					break;
				}
			}
		}

		if (textureId == -1)
		{
			textureId = m_Configuration.StartTextureIndex;
			AddTexture(texture);
		}

		for (unsigned i = 0; i < vertices.size(); ++i)
		{
			verts[i * m_Configuration.Layout.GetCount()] = vertices[i].Position.x;
			verts[i * m_Configuration.Layout.GetCount() + 1] = vertices[i].Position.y;
			verts[i * m_Configuration.Layout.GetCount() + 2] = vertices[i].Position.z;
			verts[i * m_Configuration.Layout.GetCount() + 3] = vertices[i].Color.r;
			verts[i * m_Configuration.Layout.GetCount() + 4] = vertices[i].Color.g;
			verts[i * m_Configuration.Layout.GetCount() + 5] = vertices[i].Color.b;
			verts[i * m_Configuration.Layout.GetCount() + 6] = vertices[i].Color.a;
			verts[i * m_Configuration.Layout.GetCount() + 7] = vertices[i].TextureCoordinates.x;
			verts[i * m_Configuration.Layout.GetCount() + 8] = vertices[i].TextureCoordinates.y;
			verts[i * m_Configuration.Layout.GetCount() + 9] = static_cast<float>(textureId);
			verts[i * m_Configuration.Layout.GetCount() + 10] = vertices[i].TilingFactor;
		}

		m_VAO->Bind();

		m_VBO->AddSubData(&verts.front(), vertices.size() * m_Configuration.Layout.GetStride());
		m_UsedVertices += vertices.size();

		m_EBO->AddSubData(&inds.front(), indices.size());
		m_UsedIndices += indices.size();
	}

	void Batch::SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) const noexcept
	{
		m_Configuration.Shad->Bind();
		m_Configuration.Shad->SetMat4("u_Transformation.View", viewMatrix);
		m_Configuration.Shad->SetMat4("u_Transformation.Projection", projectionMatrix);
	}
	
	void Batch::Render() noexcept
	{
		if (IsEmpty()) return;

		// MUST BE DELETED
		std::vector<int> samples(m_Configuration.MaxTextureArraySize);

		for (unsigned i = 0; i < m_Configuration.MaxTextureArraySize; ++i)
		{
			samples[i] = i;
		}

		m_Configuration.Shad->Bind();
		m_Configuration.Shad->SetIntArray("u_Textures", &samples.front(), m_Configuration.MaxTextureArraySize);

		for (unsigned i = 0; i < m_Configuration.StartTextureIndex; ++i)
		{
			m_Configuration.Textures[i]->Bind(i);
		}

		m_VAO->Bind();
		RenderCommand::DrawIndexed(m_VAO);
	}

	void Batch::Clear() noexcept
	{
		m_EBO->SetCount(0);
		m_VBO->SetOffset(0);
		m_UsedIndices = 0;
		m_UsedVertices = 0;
		m_Configuration.StartTextureIndex = 1;
	}

	void Batch::AddTexture(const Ref<Texture2D>& texture) noexcept
	{
		m_Configuration.Textures.push_back(texture);
		++m_Configuration.StartTextureIndex;
	}
}