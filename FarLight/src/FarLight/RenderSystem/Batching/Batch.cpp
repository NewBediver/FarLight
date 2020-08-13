// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Batch.h"

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

#include <glad/glad.h>

namespace FarLight
{
	Batch::Batch(const BatchStatistic& stats) noexcept
		: m_Statistic(stats)
		, m_VAO(VertexArray::Create())
		, m_VBO(VertexBuffer::Create(stats.MaxVertexNumber * stats.UsedLayout.GetStride(), stats.UsedLayout))
		, m_EBO(IndexBuffer::Create(stats.MaxIndexNumber))
	{
		FL_PROFILE_FUNCTION();

		m_VAO->Bind();

		m_VAO->AddVertexBuffer(m_VBO);
		m_VAO->SetIndexBuffer(m_EBO);

		FL_CORE_INFO("==================== Created Batch Info ====================");
		FL_CORE_INFO("   Maximum Vertex Count: {0}", m_Statistic.MaxVertexNumber);
		FL_CORE_INFO("   Maximum Index Count: {0}", m_Statistic.MaxIndexNumber);
		FL_CORE_INFO("   Maximum Texture Slots: {0}", m_Statistic.MaxTextureSlots);
		FL_CORE_INFO("   Used Shader ID: {0}", m_Statistic.UsedShader->GetID());
		FL_CORE_INFO("   Used Default Texture ID: {0}", m_Statistic.UsedTextures[0]->GetID());
		FL_CORE_INFO("   Used Layout Size and Stride: {0} / {1}", m_Statistic.UsedLayout.GetElements().size(), m_Statistic.UsedLayout.GetStride());
		FL_CORE_INFO("============================================================");
	}

	void Batch::AddData(unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices) noexcept
	{
		FL_PROFILE_FUNCTION();

		std::vector<unsigned> inds(indexNumber);
		unsigned offset = m_Statistic.UsedVertexNumber;
		for (unsigned i = 0; i < indexNumber; ++i)
			inds[i] = indices[i] + offset;

		m_VAO->Bind();

		m_VBO->AddSubData(&vertexData.front(), vertexNumber * m_Statistic.UsedLayout.GetStride());
		m_Statistic.UsedVertexNumber += vertexNumber;

		m_EBO->AddSubData(&inds.front(), indexNumber);
		m_Statistic.UsedIndexNumber += indexNumber;
	}

	void Batch::AddData(unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices, const Ref<Texture2D>& texture, unsigned textureIndexDataOffset) noexcept
	{
		FL_PROFILE_FUNCTION();

		std::vector<float> tmp = vertexData;

		unsigned textureId = 0;
		for (unsigned i = 1; i < m_Statistic.UsedTextureSlots; ++i)
		{
			if (m_Statistic.UsedTextures[i]->GetID() == texture->GetID())
			{
				textureId = i;
				break;
			}
		}

		if (textureId == 0)
		{
			textureId = m_Statistic.UsedTextureSlots;
			AddTexture(texture);
		}

		for (unsigned long long i = 0; i < vertexNumber; ++i)
		{
			unsigned long long index = i * static_cast<unsigned long long>(m_Statistic.UsedLayout.GetCount());
			tmp[index + static_cast<unsigned long long>(textureIndexDataOffset)] = static_cast<float>(textureId);
		}

		AddData(vertexNumber, tmp, indexNumber, indices);
	}

	void Batch::SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) const noexcept
	{
		FL_PROFILE_FUNCTION();

		m_Statistic.UsedShader->Bind();
		m_Statistic.UsedShader->SetMat4("u_Transformation.View", viewMatrix);
		m_Statistic.UsedShader->SetMat4("u_Transformation.Projection", projectionMatrix);
	}
	
	void Batch::Render() noexcept
	{
		FL_PROFILE_FUNCTION();

		if (IsEmpty()) return;

		std::vector<int> samples(m_Statistic.MaxTextureSlots);
		std::iota(samples.begin(), samples.end(), 0);

		m_Statistic.UsedShader->Bind();
		m_Statistic.UsedShader->SetIntArray("u_Textures", &samples.front(), m_Statistic.MaxTextureSlots);

		for (unsigned i = 0; i < m_Statistic.UsedTextureSlots; ++i)
		{
			m_Statistic.UsedTextures[i]->Bind(i);
		}

		m_VAO->Bind();
		RenderCommand::DrawIndexed(m_VAO);

		m_Statistic.m_RenderCalls.push_back({m_Statistic.UsedVertexNumber, m_Statistic.UsedIndexNumber, m_Statistic.UsedTextureSlots});
	}

	void Batch::Clear() noexcept
	{
		FL_PROFILE_FUNCTION();

		m_Statistic.UsedIndexNumber = 0;
		m_EBO->SetCount(0);

		m_Statistic.UsedVertexNumber = 0;
		m_VBO->SetOffset(0);
		
		m_Statistic.UsedTextureSlots = 1;
	}

	void Batch::AddTexture(const Ref<Texture2D>& texture) noexcept
	{
		FL_CORE_ASSERT(HasFreeTextureSlots(1), "Current batch doesn't have free texture slots!");

		FL_PROFILE_FUNCTION();

		m_Statistic.UsedTextures[m_Statistic.UsedTextureSlots] = texture;
		++m_Statistic.UsedTextureSlots;
	}
}