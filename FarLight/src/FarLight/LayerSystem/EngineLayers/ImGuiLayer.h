#pragma once

#include "FarLight/LayerSystem/Layer.h"

namespace FarLight
{
	class FARLIGHT_API ImGuiLayer
		: public Layer
	{
	public:
		ImGuiLayer()
			: Layer("ImGuiLayer"), _time(0.0) { }

		virtual void OnAttach() const override;
		virtual void OnDetach() const override;
		virtual void OnUpdate() override;
		virtual void OnUserInterfaceRender() override;
		virtual void OnEvent(Event& event) override { }

		void Begin() const;
		void End() const;

	private:
		float _time;
	};
}