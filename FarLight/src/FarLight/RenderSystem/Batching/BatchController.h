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

		void AddData(const BatchConfiguration& config, const std::vector<VertexData>& vertices, const std::vector<unsigned>& indices, const Ref<Texture2D>& texture) noexcept;
		void SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) noexcept;

		void RenderAll() noexcept;
		void ClearAll() noexcept;

	private:
		std::vector<Batch> m_Batches;
	};
}