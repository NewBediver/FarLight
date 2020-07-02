#pragma once

#include "FarLight/LayerSystem/Layer.h"
#include "FarLight/Application.h"

namespace FarLight
{
	class FARLIGHT_API ImGuiLayer
		: public Layer
	{
	public:
		ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& event) override;

	private:
		double _time;
	};
}