#include "flpch.h"

#include "BatchController.h"

namespace FarLight
{
	void BatchController::AddData(const BatchConfiguration& config, unsigned numVertices, const float* vertices, unsigned numIndices, const unsigned* indices)
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

	void BatchController::RenderAll()
	{
		for (auto& batch : m_Batches) batch.Render();
	}

	void BatchController::ClearAll()
	{
		for (auto& batch : m_Batches) batch.Clear();
	}

	void BatchController::SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix)
	{
		for (auto& batch : m_Batches) batch.SetViewProjection(viewMatrix, projectionMatrix);
	}
}


