#include "flpch.h"
#include "LayerStack.h"

namespace FarLight
{
	LayerStack::LayerStack()
		: _layerInsertIndex(0) { }

	LayerStack::~LayerStack()
	{
		for (auto layer : _layers)
		{
			delete layer;
		}
	}

	inline void LayerStack::PushLayer(Layer* layer)
	{
		_layers.emplace(_layers.begin() + _layerInsertIndex, layer);
		++_layerInsertIndex;
	}

	inline void LayerStack::PushOverlay(Layer* overlay) { _layers.emplace_back(overlay); }
	
	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(_layers.begin(), _layers.end(), layer);
		if (it != _layers.end())
		{
			_layers.erase(it);
			if (_layerInsertIndex > 0) --_layerInsertIndex;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(_layers.begin(), _layers.end(), overlay);
		if (it != _layers.end())
		{
			if (std::distance(_layers.begin(), it) < _layerInsertIndex) --_layerInsertIndex;
			_layers.erase(it);
		}
	}

	inline std::vector<Layer*>::iterator LayerStack::begin() { return _layers.begin(); }
	inline std::vector<Layer*>::iterator LayerStack::end() { return _layers.end(); }
	inline std::vector<Layer*>::reverse_iterator LayerStack::rbegin() { return _layers.rbegin(); }
	inline std::vector<Layer*>::reverse_iterator LayerStack::rend() { return _layers.rend(); }
}
