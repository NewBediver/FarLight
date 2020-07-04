#pragma once

#include "flpch.h"

#include "FarLight/Core.h"
#include "Layer.h"

namespace FarLight
{
	class FARLIGHT_API LayerStack
	{
	public:
		explicit LayerStack();

		void PushLayer(std::shared_ptr<Layer> layer);
		void PushOverlay(std::shared_ptr<Layer> overlay);
		void PopLayer(std::shared_ptr<Layer> layer);
		void PopOverlay(std::shared_ptr<Layer> overlay);

		std::vector<std::shared_ptr<Layer>>::iterator LayerStack::begin();
		std::vector<std::shared_ptr<Layer>>::iterator LayerStack::end();
		std::vector<std::shared_ptr<Layer>>::reverse_iterator LayerStack::rbegin();
		std::vector<std::shared_ptr<Layer>>::reverse_iterator LayerStack::rend();

	private:
		void DeleteLayerByThePointer(std::shared_ptr<Layer> layer);
		void UpdateLayerInsertIndex(std::vector<std::shared_ptr<Layer>>::iterator it);

		std::vector<std::shared_ptr<Layer>> _layers;
		int _layerInsertIndex;
	};
}