#include "flpch.h"
#include "LayerStack.h"

namespace FarLight
{
	LayerStack::LayerStack()
		: _layerInsertIndex(0) { }

	inline void LayerStack::PushLayer(std::shared_ptr<Layer> layer)
	{
		_layers.emplace(_layers.begin() + _layerInsertIndex, layer);
		++_layerInsertIndex;
		layer->OnAttach();
	}

	inline void LayerStack::PushOverlay(std::shared_ptr<Layer> overlay)
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

	inline void LayerStack::UpdateLayerInsertIndex(std::vector<std::shared_ptr<Layer>>::iterator it)
	{
		if (std::distance(_layers.begin(), it) < _layerInsertIndex) --_layerInsertIndex;
	}

	inline std::vector<std::shared_ptr<Layer>>::iterator LayerStack::begin() { return _layers.begin(); }
	inline std::vector<std::shared_ptr<Layer>>::iterator LayerStack::end() { return _layers.end(); }
	inline std::vector<std::shared_ptr<Layer>>::reverse_iterator LayerStack::rbegin() { return _layers.rbegin(); }
	inline std::vector<std::shared_ptr<Layer>>::reverse_iterator LayerStack::rend() { return _layers.rend(); }
}