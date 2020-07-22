#pragma once

#include "Layer.h"

namespace FarLight
{
	class FARLIGHT_API LayerStack
	{
	public:
		explicit LayerStack()
			: _layerInsertIndex(0) { }

		void PushLayer(const Ref<Layer>& layer);
		void PushOverlay(const Ref<Layer>& overlay);
		void PopLayer(const Ref<Layer>& layer);
		void PopOverlay(const Ref<Layer>& overlay);

		std::vector<Ref<Layer>>::const_iterator cbegin() const { return _layers.cbegin(); }
		std::vector<Ref<Layer>>::const_iterator cend() const { return _layers.cend(); }
		std::vector<Ref<Layer>>::const_reverse_iterator crbegin() const { return _layers.crbegin(); }
		std::vector<Ref<Layer>>::const_reverse_iterator crend() const { return _layers.crend(); }

	private:
		std::vector<Ref<Layer>> _layers;
		unsigned int _layerInsertIndex;
	};
}