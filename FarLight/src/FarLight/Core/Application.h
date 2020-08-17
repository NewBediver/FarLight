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
	class Application final
	{
	public:
		static Application& GetInstance() noexcept
		{
			static Application s_Instance;
			return s_Instance;
		}

		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;

		~Application() noexcept;

		void Run() noexcept;
		void OnEvent(Event& e) noexcept;

		void Close() noexcept;

		void PushLayer(const Ref<Layer>& layer) noexcept { m_LayerStack.PushLayer(layer); }
		void PushOverlay(const Ref<Layer>& overlay) noexcept { m_LayerStack.PushOverlay(overlay); }

		constexpr
		const Ref<Window>& GetWindow() const noexcept { return m_Window; }

	private:
		explicit Application() noexcept;

		bool OnWindowClosed(const WindowClosedEvent& e) noexcept;
		bool OnWindowResized(const WindowResizedEvent& e) noexcept;

		Ref<Window> m_Window;
		Ref<ImGuiLayer> m_UserInterfaceLayer;

		bool m_IsRunning;
		bool m_IsMinimized;

		LayerStack m_LayerStack;

		float m_LastFrameTime;
	};

	// To be defined in CLIENT
	Application& CreateApplication() noexcept;
}