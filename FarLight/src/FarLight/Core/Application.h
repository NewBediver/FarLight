#pragma once

#include "FarLight/EventSystem/WindowEvents/WindowClosedEvent.h"
#include "FarLight/EventSystem/WindowEvents/WindowResizedEvent.h"
#include "FarLight/WindowSystem/Window.h"

#include "FarLight/LayerSystem/LayerStack.h"
#include "FarLight/LayerSystem/EngineLayers/ImGuiLayer.h"

namespace FarLight
{
	class FARLIGHT_API Application
	{
	public:
		void Run();
		void OnEvent(Event& e);

		void PushLayer(const Ref<Layer>& layer) { _layerStack.PushLayer(layer); }
		void PushOverlay(const Ref<Layer>& overlay) { _layerStack.PushOverlay(overlay); }

		static const Scope<Application>& GetInstance();

		Ref<Window> GetWindow() { return _window; }

	private:
		explicit Application();
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;

		const bool OnWindowClosed(const WindowClosedEvent& e);
		const bool OnWindowResized(const WindowResizedEvent& e);

		static Scope<Application> _instance;

		Ref<Window> _window;
		Ref<ImGuiLayer> _userInterfaceLayer;

		bool _isRunning;
		bool _isMinimized;

		LayerStack _layerStack;

		float _lastFrameTime;
	};

	// To be defined in CLIENT
	const Scope<Application>& CreateApplication();
}