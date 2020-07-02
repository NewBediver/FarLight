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
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator LayerStack::begin();
		std::vector<Layer*>::iterator LayerStack::end();
		std::vector<Layer*>::reverse_iterator LayerStack::rbegin();
		std::vector<Layer*>::reverse_iterator LayerStack::rend();

	private:
		void DeleteLayerByThePointer(Layer* layer);
		void UpdateLayerInsertIndex(std::vector<Layer*>::iterator it);

		std::vector<Layer*> _layers;
		int _layerInsertIndex;
	};
}