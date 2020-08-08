#pragma once

#include <vector>

#include "Batch.h"

namespace FarLight
{
	class BatchController final
	{
	public:
		void AddData(const BatchConfiguration& config, unsigned numVertices, const float* vertices, unsigned numIndices, const unsigned* indices);
		void SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);

		void RenderAll();
		void ClearAll();

	private:
		std::vector<Batch> m_Batches;
	};
}