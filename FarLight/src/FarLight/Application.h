#pragma once

#include "flpch.h"

#include "EventSystem/Event.h"
#include "EventSystem/WindowEvents/WindowClosedEvent.h"
#include "WindowSystem/Window.h"

#include "LayerSystem/Layer.h"
#include "LayerSystem/LayerStack.h"
#include "FarLight/LayerSystem/EngineLayers/ImGuiLayer.h"

namespace FarLight
{
	class FARLIGHT_API Application
	{
	public:
		void Run();
		void OnEvent(Event& e);

		void PushLayer(std::shared_ptr<Layer> layer);
		void PushOverlay(std::shared_ptr<Layer> layer);

		static Application* GetInstance();

		std::unique_ptr<Window>& GetWindow();

	private:
		static Application* _instance;

		explicit Application();
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;

		void Init();

		bool OnWindowClosed(const WindowClosedEvent& e);

		std::unique_ptr<Window> _window;
		std::shared_ptr<ImGuiLayer> _userInterfaceLayer;
		bool _isRunning;
		LayerStack _layerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}