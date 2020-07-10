#include "flpch.h"
#include "Application.h"

#include <glad/glad.h>

#include "Core.h"
#include "FarLight/EventSystem/EventDispatcher.h"

#include "InputSystem/Input.h"

namespace FarLight
{
	std::shared_ptr<Application> Application::_instance = nullptr;

	std::shared_ptr<Application> Application::GetInstance()
	{
		if (_instance == nullptr) _instance = std::shared_ptr<Application>(new Application());
		return _instance;
	}

	Application::Application()
		: _isRunning(true)
	{
		_window = Window::Create();
		_userInterfaceLayer = std::make_shared<ImGuiLayer>();
	}

	void Application::Run()
	{
		Init();
		while (_isRunning)
		{
			glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
			glClear(GL_COLOR_BUFFER_BIT);
			
			_shader->Bind();
			glBindVertexArray(_vertextArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			for (auto& layer : _layerStack) layer->OnUpdate();

			_userInterfaceLayer->Begin();
			for (auto& layer : _layerStack) layer->OnUserInterfaceRender();
			_userInterfaceLayer->End();

			_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowClosed));

		//FL_CORE_TRACE("{0}", e);
		for (auto it = _layerStack.rbegin(); it != _layerStack.rend(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.IsHandled()) break;
		}
	}

	void Application::Init()
	{
		_window->SetEventCallback(FL_BIND_EVENT_FUNC(Application::OnEvent));
		_layerStack.PushOverlay(_userInterfaceLayer);

		glGenVertexArrays(1, &_vertextArray);
		glBindVertexArray(_vertextArray);

		glGenBuffers(1, &_vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);

		float verticies[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f,
			0.5f, -0.5f, 0.0f
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glGenBuffers(1, &_indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);

		unsigned int indices[3] = { 0, 1, 2 };
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 a_Color;

			in vec3 v_Position;

			void main()
			{
				a_Color = vec4(v_Position + 0.5, 1.0);
			}
		)";

		_shader = std::make_unique<Shader>(vertexSrc, fragmentSrc);
	}

	bool Application::OnWindowClosed(const WindowClosedEvent& e)
	{
		_isRunning = false;
		return true;
	}
}