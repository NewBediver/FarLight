#pragma once

#include "Layer.h"

namespace FarLight
{
	class FARLIGHT_API LayerStack
	{
	public:
		explicit LayerStack()
			: _layerInsertIndex(0) { }

		void PushLayer(std::shared_ptr<Layer> layer);
		void PushOverlay(std::shared_ptr<Layer> overlay);
		void PopLayer(std::shared_ptr<Layer> layer);
		void PopOverlay(std::shared_ptr<Layer> overlay);

		std::vector<std::shared_ptr<Layer>>::iterator LayerStack::begin() { return _layers.begin(); }
		std::vector<std::shared_ptr<Layer>>::iterator LayerStack::end() { return _layers.end(); }
		std::vector<std::shared_ptr<Layer>>::reverse_iterator LayerStack::rbegin() { return _layers.rbegin(); }
		std::vector<std::shared_ptr<Layer>>::reverse_iterator LayerStack::rend() { return _layers.rend(); }

	private:
		void DeleteLayerByThePointer(std::shared_ptr<Layer> layer);
		void UpdateLayerInsertIndex(std::vector<std::shared_ptr<Layer>>::iterator it);

		std::vector<std::shared_ptr<Layer>> _layers;
		unsigned int _layerInsertIndex;
	};
}