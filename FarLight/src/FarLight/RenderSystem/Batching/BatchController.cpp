#include "flpch.h"

#include "BatchController.h"

namespace FarLight
{
	void BatchController::AddBatch(const Batch& batch)
	{
		m_Batches.push_back(batch);
		m_IsSorted = false;
	}

	void BatchController::Render()
	{
		for (auto& batch : m_Batches) batch.Render();
	}
}


