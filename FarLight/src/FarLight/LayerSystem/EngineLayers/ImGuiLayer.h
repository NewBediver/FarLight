#pragma once

#include "FarLight/LayerSystem/Layer.h"

namespace FarLight
{
	class ImGuiLayer final
		: public Layer
	{
	public:
		ImGuiLayer(const ImGuiLayer&) = delete;
		ImGuiLayer(ImGuiLayer&&) = delete;
		ImGuiLayer& operator=(const ImGuiLayer&) = delete;
		ImGuiLayer& operator=(ImGuiLayer&&) = delete;

		explicit ImGuiLayer() noexcept
			: Layer("ImGuiLayer")
		{ }

		virtual void OnAttach() noexcept override;
		virtual void OnDetach() noexcept override;
		virtual void OnUpdate(const Timestep& timestamp) noexcept override { };
		virtual void OnUserInterfaceRender() noexcept override { };
		virtual void OnEvent(Event& event) noexcept override;

		void Begin() const noexcept;
		void End() const noexcept;
	};
}