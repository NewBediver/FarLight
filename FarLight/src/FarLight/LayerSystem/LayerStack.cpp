// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "LayerStack.h"

namespace FarLight
{
	void LayerStack::PushLayer(const Ref<Layer>& layer)
	{
		_layers.emplace(_layers.begin() + _layerInsertIndex, layer);
		++_layerInsertIndex;
		layer->OnAttach();
	}

	void LayerStack::PushOverlay(const Ref<Layer>& overlay)
	{
		_layers.emplace_back(overlay);
		overlay->OnAttach();
	}
	
	void LayerStack::PopLayer(const Ref<Layer>& layer)
	{
		auto it = std::find(_layers.begin(), _layers.begin() + _layerInsertIndex, layer);
		if (it != _layers.begin() + _layerInsertIndex)
		{
			(*it)->OnDetach();
			_layers.erase(it);
			--_layerInsertIndex;
		}
	}

	void LayerStack::PopOverlay(const Ref<Layer>& overlay)
	{
		auto it = std::find(_layers.begin() + _layerInsertIndex, _layers.end(), overlay);
		if (it != _layers.end())
		{
			(*it)->OnDetach();
			_layers.erase(it);
		}
	}
}