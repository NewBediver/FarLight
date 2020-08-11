// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "BatchController.h"

namespace FarLight
{
	void BatchController::AddData(const BatchConfiguration& config, const std::vector<VertexData>& vertices, const std::vector<unsigned>& indices, const Ref<Texture2D>& texture) noexcept
	{
		bool found = false;
		for (auto& elm : m_Batches)
		{
			if (config == elm.GetConfiguration())
			{
				found = true;
				if (!elm.HasFreeTextureSlots() || !elm.HasFreeIndexSlots(indices.size()) || !elm.HasFreeVertexSlots(vertices.size()))
				{
					elm.Render();
					elm.Clear();
				}
				elm.AddData(vertices, indices, texture);
				break;
			}
		}

		if (!found)
		{
			m_Batches.emplace_back(config);
			m_Batches.back().AddData(vertices, indices, texture);
		}
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