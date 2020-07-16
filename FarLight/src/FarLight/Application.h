#pragma once

#include "EventSystem/WindowEvents/WindowClosedEvent.h"
#include "WindowSystem/Window.h"

#include "FarLight/LayerSystem/LayerStack.h"
#include "FarLight/LayerSystem/EngineLayers/ImGuiLayer.h"

#include "FarLight/RenderSystem/Shader/Shader.h"
#include "FarLight/RenderSystem/VertexArray/VertexArray.h"

#include "FarLight/RenderSystem/Camera/OrthographicCamera.h"

namespace FarLight
{
	class FARLIGHT_API Application
	{
	public:
		void Run();
		void OnEvent(Event& e);

		void PushLayer(std::shared_ptr<Layer> layer) { _layerStack.PushLayer(layer); }
		void PushOverlay(std::shared_ptr<Layer> overlay) { _layerStack.PushOverlay(overlay); }

		static std::shared_ptr<Application> GetInstance();

		std::shared_ptr<Window> GetWindow() { return _window; }

	private:
		explicit Application();
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;

		void Init();
		bool OnWindowClosed(const WindowClosedEvent& e);

		static std::shared_ptr<Application> _instance;

		unsigned int _vertextArray;

		std::shared_ptr<Shader> _shader;
		std::shared_ptr<VertexArray> _vertexArray;

		std::shared_ptr<Shader> _blueShader;
		std::shared_ptr<VertexArray> _squareVertexArray;

		std::shared_ptr<Window> _window;
		std::shared_ptr<ImGuiLayer> _userInterfaceLayer;

		bool _isRunning;
		LayerStack _layerStack;
		OrthographicCamera _camera;
	};

	// To be defined in CLIENT
	std::shared_ptr<Application> CreateApplication();
}