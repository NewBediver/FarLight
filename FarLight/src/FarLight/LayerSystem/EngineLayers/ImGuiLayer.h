#pragma once

#include "FarLight/LayerSystem/Layer.h"

namespace FarLight
{
	class ImGuiLayer
		: public Layer
	{
	public:
		explicit ImGuiLayer()
			: Layer("ImGuiLayer")
		{ }

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(const Timestep& timestamp) override { };
		virtual void OnUserInterfaceRender() override { };
		virtual void OnEvent(Event& event) override { }

		void Begin() const;
		void End() const;
	};
}