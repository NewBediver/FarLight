#include "flpch.h"

#include "LayerStack.h"

namespace FarLight
{
	void LayerStack::PushLayer(std::shared_ptr<Layer> layer)
	{
		_layers.emplace(_layers.begin() + _layerInsertIndex, layer);
		++_layerInsertIndex;
		layer->OnAttach();
	}

	void LayerStack::PushOverlay(std::shared_ptr<Layer> overlay)
	{
		_layers.emplace_back(overlay);
		overlay->OnAttach();
	}
	
	void LayerStack::PopLayer(std::shared_ptr<Layer> layer)
	{
		auto it = std::find(_layers.begin(), _layers.begin() + _layerInsertIndex, layer);
		if (it != _layers.begin() + _layerInsertIndex)
		{
			(*it)->OnDetach();
			_layers.erase(it);
			--_layerInsertIndex;
		}
	}

	void LayerStack::PopOverlay(std::shared_ptr<Layer> overlay)
	{
		auto it = std::find(_layers.begin() + _layerInsertIndex, _layers.end(), overlay);
		if (it != _layers.end())
		{
			(*it)->OnDetach();
			_layers.erase(it);
		}
	}
}