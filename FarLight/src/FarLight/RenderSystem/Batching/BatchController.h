#pragma once

#include <vector>

#include "Batch.h"

namespace FarLight
{
	class BatchController final
	{
	public:
		BatchController(const BatchController&) = delete;
		BatchController(BatchController&&) = delete;
		BatchController& operator=(const BatchController&) = delete;
		BatchController& operator=(BatchController&&) = delete;

		explicit BatchController() noexcept = default;

		void AddData(const BatchConfiguration& config, unsigned numVertices, const float* vertices, unsigned numIndices, const unsigned* indices) noexcept;
		void SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) noexcept;

		void RenderAll() noexcept;
		void ClearAll() noexcept;

	private:
		std::vector<Batch> m_Batches;
	};
}