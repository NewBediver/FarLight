#pragma once

#include "Layer.h"

#include "FarLight/Core/Core.h"

namespace FarLight
{
	class LayerStack final
	{
	public:
		explicit LayerStack()
			: m_LayerInsertIndex(0)
		{ }

		void PushLayer(const Ref<Layer>& layer);
		void PushOverlay(const Ref<Layer>& overlay);
		void PopLayer(const Ref<Layer>& layer);
		void PopOverlay(const Ref<Layer>& overlay);

		std::vector<Ref<Layer>>::const_iterator cbegin() const { return m_Layers.cbegin(); }
		std::vector<Ref<Layer>>::const_iterator cend() const { return m_Layers.cend(); }
		std::vector<Ref<Layer>>::const_reverse_iterator crbegin() const { return m_Layers.crbegin(); }
		std::vector<Ref<Layer>>::const_reverse_iterator crend() const { return m_Layers.crend(); }

	private:
		std::vector<Ref<Layer>> m_Layers;
		unsigned m_LayerInsertIndex;
	};
}