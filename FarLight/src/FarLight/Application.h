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
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		static Application& GetInstance();

		Window& GetWindow();

	private:
		explicit Application();
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;

		static Application* _instance;

		bool OnWindowClosed(const WindowClosedEvent& e);

		std::unique_ptr<Window> _window;
		bool _isRunning;
		LayerStack _layerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}