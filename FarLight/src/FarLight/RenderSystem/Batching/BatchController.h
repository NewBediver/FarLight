#pragma once

#include <vector>

#include "Batch.h"

namespace FarLight
{
	class BatchController
	{
	public:
		void AddBatch(const Batch& batch);


		void Render();

	private:
		std::vector<Batch> m_Batches;
		bool m_IsSorted = false;
	};
}