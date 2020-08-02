#pragma once

#include "Core.h"

#include "FarLight/EventSystem/Event.h"
#include "FarLight/EventSystem/WindowEvents/WindowClosedEvent.h"
#include "FarLight/EventSystem/WindowEvents/WindowResizedEvent.h"

#include "FarLight/WindowSystem/Window.h"

#include "FarLight/LayerSystem/Layer.h"
#include "FarLight/LayerSystem/LayerStack.h"
#include "FarLight/LayerSystem/EngineLayers/ImGuiLayer.h"

namespace FarLight
{
	class Application
	{
	public:
		void Run();
		void OnEvent(Event& e);

		void PushLayer(const Ref<Layer>& layer) { m_LayerStack.PushLayer(layer); }
		void PushOverlay(const Ref<Layer>& overlay) { m_LayerStack.PushOverlay(overlay); }

		const Ref<Window>& GetWindow() const { return m_Window; }

		Application::~Application();

		static Application* GetInstance();

	private:
		explicit Application();
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;

		bool OnWindowClosed(const WindowClosedEvent& e);
		bool OnWindowResized(const WindowResizedEvent& e);

		Ref<Window> m_Window;
		Ref<ImGuiLayer> m_UserInterfaceLayer;

		bool m_IsRunning;
		bool m_IsMinimized;

		LayerStack m_LayerStack;

		float m_LastFrameTime;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}