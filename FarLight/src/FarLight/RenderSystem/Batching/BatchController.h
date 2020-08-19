#pragma once

#include "Batch.h"

namespace FarLight
{
	class BatchController final
	{
	public:
		/*BatchController(const BatchController&) = delete;
		BatchController(BatchController&&) = delete;
		BatchController& operator=(const BatchController&) = delete;
		BatchController& operator=(BatchController&&) = delete;*/

		explicit BatchController() noexcept = default;

		void RenderAll() noexcept;
		void ClearAll() noexcept;
		void ResetRenderCalls() noexcept;

		void AddData(const BatchStatistic& stat, unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices, const Ref<Texture2D>& texture, unsigned textureIndexDataOffset) noexcept;
		void AddData(const BatchStatistic& stat, unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices) noexcept;

		void SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) noexcept;

		const std::vector<Batch>& GetBatches() const noexcept { return m_Batches; }

	private:
		std::vector<Batch> m_Batches;
	};
}