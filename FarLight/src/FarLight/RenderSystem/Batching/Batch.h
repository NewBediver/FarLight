#pragma once

#include <vector>

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"
#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"
#include "FarLight/RenderSystem/Shader/Shader.h"

namespace FarLight
{
	struct BatchStatistic final
	{
		struct RenderStatistic
		{
			unsigned UsedVertexNumber;
			unsigned UsedIndexNumber;
			unsigned UsedTextureSlots;
		};

		unsigned MaxVertexNumber;
		unsigned UsedVertexNumber;

		unsigned MaxIndexNumber;
		unsigned UsedIndexNumber;

		unsigned MaxTextureSlots;
		unsigned UsedTextureSlots;

		Ref<Shader> UsedShader;
		std::vector<Ref<Texture2D>> UsedTextures;
		BufferLayout UsedLayout;

		explicit BatchStatistic(const BufferLayout& layout, const Ref<Texture2D>& defaultTexture, const Ref<Shader>& shader, unsigned vertexNumber = 10000, unsigned indexNumber = 20000, unsigned textureSlots = 32) noexcept
			: MaxVertexNumber(vertexNumber)
			, UsedVertexNumber(0)
			, MaxIndexNumber(indexNumber)
			, UsedIndexNumber(0)
			, MaxTextureSlots(textureSlots)
			, UsedTextureSlots(1)
			, UsedLayout(layout)
			, UsedShader(shader)
		{
			UsedTextures.resize(MaxTextureSlots);
			UsedTextures[0] = defaultTexture;
		}

		bool operator==(const BatchStatistic& other) const noexcept
		{
			return UsedShader->GetID() == other.UsedShader->GetID()
				&& UsedLayout == other.UsedLayout
				&& UsedTextures[0]->GetID() == other.UsedTextures[0]->GetID();
		}

		const std::vector<RenderStatistic>& GetRenderStatistic() const noexcept { return m_RenderCalls; }

	private:
		std::vector<RenderStatistic> m_RenderCalls;

		friend class Batch;
	};

	class Batch final
	{
	public:
		/*Batch(const Batch&) = delete;
		Batch& operator=(const Batch&) = delete;
		Batch& operator=(Batch&&) = delete;*/

		//Batch(Batch&&) noexcept = default;

		explicit Batch(const BatchStatistic& stats) noexcept;

		void Render() noexcept;
		void Clear() noexcept;

		void AddData(unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices) noexcept;
		void AddData(unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices, const Ref<Texture2D>& texture, unsigned textureIndexDataOffset) noexcept;

		constexpr
		bool IsEmpty() const noexcept { return m_Statistic.UsedVertexNumber == 0 && m_Statistic.UsedIndexNumber == 0; }
		constexpr
		bool HasFreeTextureSlots(unsigned numSlots = 0) const noexcept { return m_Statistic.UsedTextureSlots + numSlots < m_Statistic.MaxTextureSlots; }
		constexpr
		bool HasFreeVertexSlots(unsigned numVertices = 0) const noexcept { return m_Statistic.UsedVertexNumber + numVertices <= m_Statistic.MaxVertexNumber; }
		constexpr
		bool HasFreeIndexSlots(unsigned numIndices = 0) const noexcept { return  m_Statistic.UsedIndexNumber + numIndices <= m_Statistic.MaxIndexNumber; }
		constexpr
		const BatchStatistic& GetStatistic() const noexcept { return m_Statistic; }
		void ResetRenderCalls() noexcept { m_Statistic.m_RenderCalls.clear(); }

		void SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) const noexcept;

		bool operator==(const Batch& other) const noexcept
		{
			return m_Statistic == other.m_Statistic;
		}

	private:
		void AddTexture(const Ref<Texture2D>& texture) noexcept;

		BatchStatistic m_Statistic;
		Ref<VertexArray> m_VAO;
		Ref<VertexBuffer> m_VBO;
		Ref<IndexBuffer> m_EBO;
	};
}