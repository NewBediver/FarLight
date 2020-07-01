#pragma once

#include "flpch.h"

#include "EventSystem/Event.h"
#include "EventSystem/WindowEvents/WindowClosedEvent.h"
#include "WindowSystem/Window.h"

#include "LayerSystem/Layer.h"
#include "LayerSystem/LayerStack.h"

namespace FarLight
{
	class FARLIGHT_API Application
	{
	public:
		explicit Application();
		virtual ~Application() = default;

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClosed(const WindowClosedEvent& e);

		std::unique_ptr<Window> _window;
		bool _isRunning;
		LayerStack _layerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}