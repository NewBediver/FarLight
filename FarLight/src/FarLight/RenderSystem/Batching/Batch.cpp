// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Batch.h"

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

#include <glad/glad.h>

namespace FarLight
{
	Batch::Batch(const BatchConfiguration& stats) noexcept
		: m_Configuration(stats)
		, m_VAO(VertexArray::Create())
		, m_VBO(VertexBuffer::Create(stats.MaxVertexNumber * stats.UsedLayout.GetStride(), stats.UsedLayout))
		, m_EBO(IndexBuffer::Create(stats.MaxIndexNumber))
	{
		FL_PROFILE_FUNCTION();

		m_VAO->Bind();

		m_VAO->AddVertexBuffer(m_VBO);
		m_VAO->SetIndexBuffer(m_EBO);

		FL_CORE_INFO("==================== Created Batch Info ====================");
		FL_CORE_INFO("   Maximum Vertex Count: {0}", m_Configuration.MaxVertexNumber);
		FL_CORE_INFO("   Maximum Index Count: {0}", m_Configuration.MaxIndexNumber);
		FL_CORE_INFO("   Maximum Texture Slots: {0}", m_Configuration.MaxTextureSlots);
		FL_CORE_INFO("   Used Shader ID: {0}", m_Configuration.UsedShader->GetID());
		FL_CORE_INFO("   Used Default Texture ID: {0}", m_Configuration.UsedTextures[0]->GetID());
		FL_CORE_INFO("   Used Layout Size and Stride: {0} / {1}", m_Configuration.UsedLayout.GetElements().size(), m_Configuration.UsedLayout.GetStride());
		FL_CORE_INFO("============================================================");
	}

	Batch::Batch(Batch&& other) noexcept
		: m_Configuration(std::move(other.m_Configuration))
		, m_VertexData(std::move(other.m_VertexData))
		, m_IndexData(std::move(other.m_IndexData))
		, m_VAO(std::move(other.m_VAO))
		, m_VBO(std::move(other.m_VBO))
		, m_EBO(std::move(other.m_EBO))
	{ }

	void Batch::AddData(unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices) noexcept
	{
		FL_PROFILE_FUNCTION();

		std::vector<unsigned> inds(indexNumber);
		unsigned offset = m_Configuration.UsedVertexNumber;
		for (unsigned i = 0; i < indexNumber; ++i)
			inds[i] = indices[i] + offset;

		m_VertexData.insert(m_VertexData.end(), vertexData.begin(), vertexData.end());
		m_Configuration.UsedVertexNumber += vertexNumber;

		m_IndexData.insert(m_IndexData.end(), inds.begin(), inds.end());
		m_Configuration.UsedIndexNumber += indexNumber;
	}

	void Batch::AddData(unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices, const Ref<Texture2D>& texture, unsigned textureIndexDataOffset) noexcept
	{
		FL_PROFILE_FUNCTION();

		std::vector<float> tmp = vertexData;

		unsigned textureId = 0;
		for (unsigned i = 1; i < m_Configuration.UsedTextureSlots; ++i)
		{
			if (m_Configuration.UsedTextures[i]->GetID() == texture->GetID())
			{
				textureId = i;
				break;
			}
		}

		if (textureId == 0)
		{
			textureId = m_Configuration.UsedTextureSlots;
			AddTexture(texture);
		}

		for (unsigned long long i = 0; i < vertexNumber; ++i)
		{
			unsigned long long index = i * static_cast<unsigned long long>(m_Configuration.UsedLayout.GetCount());
			tmp[index + static_cast<unsigned long long>(textureIndexDataOffset)] = static_cast<float>(textureId);
		}

		AddData(vertexNumber, tmp, indexNumber, indices);
	}

	void Batch::SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) const noexcept
	{
		FL_PROFILE_FUNCTION();

		m_Configuration.UsedShader->Bind();
		m_Configuration.UsedShader->SetMat4("u_Transformation.View", viewMatrix);
		m_Configuration.UsedShader->SetMat4("u_Transformation.Projection", projectionMatrix);
	}
	
	void Batch::Render() noexcept
	{
		FL_PROFILE_FUNCTION();

		if (IsEmpty()) return;

		std::vector<int> samples(m_Configuration.MaxTextureSlots);
		std::iota(samples.begin(), samples.end(), 0);

		m_Configuration.UsedShader->Bind();
		m_Configuration.UsedShader->SetIntArray("u_Textures", &samples.front(), m_Configuration.MaxTextureSlots);

		for (unsigned i = 0; i < m_Configuration.UsedTextureSlots; ++i)
			m_Configuration.UsedTextures[i]->Bind(i);

		m_VAO->Bind();

		m_VBO->AddSubData(&m_VertexData.front(), m_Configuration.UsedVertexNumber * m_Configuration.UsedLayout.GetStride());
		m_EBO->AddSubData(&m_IndexData.front(), m_Configuration.UsedIndexNumber);

		RenderCommand::DrawIndexed(m_VAO);

		ClearBufferedData();
	}

	void Batch::Clear() noexcept
	{
		FL_PROFILE_FUNCTION();

		m_Configuration.UsedIndexNumber = 0;
		m_IndexData.clear();

		m_Configuration.UsedVertexNumber = 0;
		m_VertexData.clear();
		
		m_Configuration.UsedTextureSlots = 1;

		ClearBufferedData();
	}

	void Batch::AddTexture(const Ref<Texture2D>& texture) noexcept
	{
		FL_CORE_ASSERT(HasFreeTextureSlots(1), "Current batch doesn't have free texture slots!");

		FL_PROFILE_FUNCTION();

		m_Configuration.UsedTextures[m_Configuration.UsedTextureSlots] = texture;
		++m_Configuration.UsedTextureSlots;
	}

	void Batch::ClearBufferedData() noexcept
	{
		m_EBO->SetCount(0);
		m_VBO->SetOffset(0);
	}
}