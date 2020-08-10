#include "flpch.h"

#include "BatchController.h"

namespace FarLight
{
	void BatchController::AddData(const BatchConfiguration& config, unsigned numVertices, const float* vertices, unsigned numIndices, const unsigned* indices) noexcept
	{
		for (auto& elm : m_Batches)
		{
			if (config == elm.GetConfiguration())
			{
				elm.AddData(numVertices, vertices, numIndices, indices);
				return;
			}
		}
		m_Batches.emplace_back(config.Layout, config.Shad, config.Texture);
		m_Batches.back().AddData(numVertices, vertices, numIndices, indices);
	}

	void BatchController::RenderAll() noexcept
	{
		for (auto& batch : m_Batches) batch.Render();
	}

	void BatchController::ClearAll() noexcept
	{
		for (auto& batch : m_Batches) batch.Clear();
	}

	void BatchController::SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) noexcept
	{
		for (auto& batch : m_Batches) batch.SetViewProjection(viewMatrix, projectionMatrix);
	}
}


