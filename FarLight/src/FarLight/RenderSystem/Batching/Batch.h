#pragma once

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"
#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"
#include "FarLight/RenderSystem/Shader/Shader.h"

namespace FarLight
{
	enum class BatchType
	{
		Static,
		Dynamic
	};

	struct BatchConfiguration final
	{
		BatchType Type;

		unsigned MaxVertexNumber;
		unsigned UsedVertexNumber;

		unsigned MaxIndexNumber;
		unsigned UsedIndexNumber;

		unsigned MaxTextureSlots;
		unsigned UsedTextureSlots;

		Ref<Shader> UsedShader;
		std::vector<Ref<Texture2D>> UsedTextures;
		BufferLayout UsedLayout;

		explicit BatchConfiguration(BatchType type, const BufferLayout& layout, const Ref<Texture2D>& defaultTexture, const Ref<Shader>& shader, unsigned vertexNumber = 10000, unsigned indexNumber = 20000, unsigned textureSlots = 32) noexcept
			: Type(type)
			, MaxVertexNumber(vertexNumber)
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

		bool operator==(const BatchConfiguration& other) const noexcept
		{
			return Type == other.Type
				&& UsedShader->GetID() == other.UsedShader->GetID()
				&& UsedLayout == other.UsedLayout
				&& UsedTextures[0]->GetID() == other.UsedTextures[0]->GetID();
		}
	};

	class Batch final
	{
	public:
		Batch(const Batch&) = delete;
		Batch& operator=(const Batch&) = delete;
		Batch& operator=(Batch&&) = delete;

		struct RenderCall
		{
			unsigned UsedVertexNumber;
			unsigned UsedIndexNumber;
			unsigned UsedTextureSlots;
		};

		explicit Batch(const BatchConfiguration& stats) noexcept;
		explicit Batch(Batch&& other) noexcept;

		void Render() noexcept;
		void Clear() noexcept;

		void AddData(unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices) noexcept;
		void AddData(unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices, const Ref<Texture2D>& texture, unsigned textureIndexDataOffset) noexcept;

		constexpr
		bool IsEmpty() const noexcept { return m_Configuration.UsedVertexNumber == 0 && m_Configuration.UsedIndexNumber == 0; }
		constexpr
		bool HasFreeTextureSlots(unsigned numSlots = 0) const noexcept { return m_Configuration.UsedTextureSlots + numSlots < m_Configuration.MaxTextureSlots; }
		constexpr
		bool HasFreeVertexSlots(unsigned numVertices = 0) const noexcept { return m_Configuration.UsedVertexNumber + numVertices <= m_Configuration.MaxVertexNumber; }
		constexpr
		bool HasFreeIndexSlots(unsigned numIndices = 0) const noexcept { return  m_Configuration.UsedIndexNumber + numIndices <= m_Configuration.MaxIndexNumber; }
		constexpr
		const BatchConfiguration& GetConfiguration() const noexcept { return m_Configuration; }
		constexpr
		const std::vector<RenderCall>& GetRenderCalls() const noexcept { return m_RenderCalls; }
		void ResetRenderCalls() noexcept { m_RenderCalls.clear(); }

		void SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) const noexcept;

		bool operator==(const Batch& other) const noexcept
		{
			return m_Configuration == other.m_Configuration;
		}

	private:
		void AddTexture(const Ref<Texture2D>& texture) noexcept;

		std::vector<RenderCall> m_RenderCalls;

		BatchConfiguration m_Configuration;
		Ref<VertexArray> m_VAO;
		Ref<VertexBuffer> m_VBO;
		Ref<IndexBuffer> m_EBO;
	};
}