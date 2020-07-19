#include "ExampleLayer.h"

#include <memory>

#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>

FarLight::ExampleLayer::ExampleLayer()
	: Layer("ExampleLayer")
	, _camera(-1.5f, 1.5f, -1.0f, 1.0f)
	, _cameraMovementSpeed(5.0f)
	, _cameraPosition(0.0f)
	, _cameraRotationSpeed(90.0f)
	, _cameraRotation(0.0f)
	, _squareMovementSpeed(2.5f)
	, _squarePosition(0.0f)
	, _squareColor(0.0f, 0.5f, 0.5f)
{
	_vertexArray = VertexArray::Create();

	float verticies[3 * 7] = {
		-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
		 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
		 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
	};

	std::shared_ptr<VertexBuffer> vertexBuffer = VertexBuffer::Create(verticies, sizeof(verticies));
	BufferLayout layout = {
		{ ShaderDataType::Float3, "a_Position" },
		{ ShaderDataType::Float4, "a_Color" }
	};
	vertexBuffer->SetLayout(layout);
	_vertexArray->AddVertexBuffer(vertexBuffer);

	unsigned int indices[3] = { 0, 1, 2 };
	std::shared_ptr<IndexBuffer> indexBuffer = IndexBuffer::Create(indices, sizeof(indices) / sizeof(unsigned int));
	_vertexArray->SetIndexBuffer(indexBuffer);

	_squareVertexArray = VertexArray::Create();

	float squareVertices[3 * 4] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	std::shared_ptr<VertexBuffer> squareVertexBuffer = VertexBuffer::Create(squareVertices, sizeof(squareVertices));
	squareVertexBuffer->SetLayout({
		{ShaderDataType::Float3, "a_Position"}
	});
	_squareVertexArray->AddVertexBuffer(squareVertexBuffer);

	unsigned int squareIndicies[6] = { 0, 1, 2, 2, 3, 0 };
	std::shared_ptr<IndexBuffer> squareIndexBuffer = IndexBuffer::Create(squareIndicies, sizeof(squareIndicies) / sizeof(unsigned int));
	_squareVertexArray->SetIndexBuffer(squareIndexBuffer);

	std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
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


	std::string blueVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transformation;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transformation * vec4(a_Position, 1.0);
			}
		)";

	std::string blueFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 a_Color;

			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				a_Color = vec4(u_Color, 1.0);
			}
		)";

	_blueShader = Shader::Create(blueVertexSrc, blueFragmentSrc);
}

void FarLight::ExampleLayer::OnAttach() const
{
}

void FarLight::ExampleLayer::OnDetach() const
{
}

void FarLight::ExampleLayer::OnUpdate(const Timestep& timestamp)
{
	HandleInput(timestamp);

	_camera.SetPosition(_cameraPosition);
	_camera.SetZRotation(_cameraRotation);	

	FarLight::Renderer::BeginScene(_camera);

	_blueShader->Bind();
	std::dynamic_pointer_cast<OpenGLShader>(_blueShader)->UploadUniformFloat3("u_Color", _squareColor.r, _squareColor.g, _squareColor.b);

	for (int y = -5; y < 5; ++y) {
		for (int x = -5; x < 5; ++x) {
			glm::mat4 squareTrans = glm::mat4(1.0f);
			squareTrans = glm::translate(squareTrans, glm::vec3(x * 0.11f + _squarePosition.x, y * 0.11f + _squarePosition.y, 0.0f));
			squareTrans = glm::scale(squareTrans, glm::vec3(0.1f));
			FarLight::Renderer::Submit(_blueShader, _squareVertexArray, squareTrans);
		}
	}
	
	FarLight::Renderer::Submit(_shader, _vertexArray);

	FarLight::Renderer::EndScene();
}

void FarLight::ExampleLayer::OnUserInterfaceRender()
{
	ImGui::Begin("Squares color");
	ImGui::ColorEdit3("Color", glm::value_ptr(_squareColor));
	ImGui::End();
}

void FarLight::ExampleLayer::OnEvent(Event& event)
{
}

void FarLight::ExampleLayer::HandleInput(const Timestep& timestamp)
{
	//FL_TRACE("Delta time: {0} s. ({1} ms.)", timestamp.GetSeconds(), timestamp.GetMilliseconds());

	if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_LEFT))
		_cameraPosition.x -= _cameraMovementSpeed * timestamp;
	else if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_RIGHT))
		_cameraPosition.x += _cameraMovementSpeed * timestamp;

	if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_DOWN))
		_cameraPosition.y -= _cameraMovementSpeed * timestamp;
	else if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_UP))
		_cameraPosition.y += _cameraMovementSpeed * timestamp;

	if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_Q))
		_cameraRotation += _cameraRotationSpeed * timestamp;
	else if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_E))
		_cameraRotation -= _cameraRotationSpeed * timestamp;

	if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_D))
		_squarePosition.x += _squareMovementSpeed * timestamp;
	else if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_A))
		_squarePosition.x -= _squareMovementSpeed * timestamp;

	if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_W))
		_squarePosition.y += _squareMovementSpeed * timestamp;
	else if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_S))
		_squarePosition.y -= _squareMovementSpeed * timestamp;
}
