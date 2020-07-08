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
		layer->OnDetach();
		DeleteLayerByThePointer(layer);
	}

	void LayerStack::PopOverlay(std::shared_ptr<Layer> overlay)
	{
		overlay->OnDetach();
		DeleteLayerByThePointer(overlay);
	}

	void LayerStack::DeleteLayerByThePointer(std::shared_ptr<Layer> layer)
	{
		auto it = std::find(_layers.begin(), _layers.end(), layer);
		if (it != _layers.end())
		{
			UpdateLayerInsertIndex(it);
			_layers.erase(it);
		}
	}

	void LayerStack::UpdateLayerInsertIndex(std::vector<std::shared_ptr<Layer>>::iterator it)
	{
		if (std::distance(_layers.begin(), it) < _layerInsertIndex) --_layerInsertIndex;
	}
}