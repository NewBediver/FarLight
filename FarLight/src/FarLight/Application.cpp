#include "flpch.h"
#include "Application.h"

#include <glad/glad.h>

#include "Core.h"
#include "FarLight/EventSystem/EventDispatcher.h"

#include "FarLight/RenderSystem/BufferLayout/BufferLayout.h"

#include "InputSystem/Input.h"

namespace FarLight
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case FarLight::ShaderDataType::Float:    return GL_FLOAT;
		case FarLight::ShaderDataType::Float2:   return GL_FLOAT;
		case FarLight::ShaderDataType::Float3:   return GL_FLOAT;
		case FarLight::ShaderDataType::Float4:   return GL_FLOAT;
		case FarLight::ShaderDataType::Mat3:     return GL_FLOAT;
		case FarLight::ShaderDataType::Mat4:     return GL_FLOAT;
		case FarLight::ShaderDataType::Int:      return GL_INT;
		case FarLight::ShaderDataType::Int2:     return GL_INT;
		case FarLight::ShaderDataType::Int3:     return GL_INT;
		case FarLight::ShaderDataType::Int4:     return GL_INT;
		case FarLight::ShaderDataType::Bool:     return GL_BOOL;
		}

		FL_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

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
			glDrawElements(GL_TRIANGLES, _indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

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

		float verticies[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		_vertexBuffer = VertexBuffer::Create(verticies, sizeof(verticies));

		{
			BufferLayout layout = {
				{ ShaderDataType::Float3, "a_Position" },
				{ ShaderDataType::Float4, "a_Color" }
			};

			_vertexBuffer->SetLayout(layout);
		}

		unsigned int index = 0;
		const auto& layout = _vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				ShaderDataTypeCount(element.Type),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			++index;
		}

		unsigned int indices[3] = { 0, 1, 2 };
		_indexBuffer = IndexBuffer::Create(indices, sizeof(indices) / sizeof(unsigned int));

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 a_Color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				a_Color = vec4(v_Position + 0.5, 1.0);
				a_Color = v_Color;
			}
		)";

		_shader = Shader::Create(vertexSrc, fragmentSrc);
	}

	bool Application::OnWindowClosed(const WindowClosedEvent& e)
	{
		_isRunning = false;
		return true;
	}
}