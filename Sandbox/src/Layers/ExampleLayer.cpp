#include "ExampleLayer.h"

#include <memory>

#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>

ExampleLayer::ExampleLayer()
	: Layer("ExampleLayer")
	, _camera(-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 100.0f)
	, _squareMovementSpeed(2.5f)
	, _squarePosition(0.0f)
	, _squareColor(0.0f, 0.5f, 0.5f)
{
	_vertexArray = FarLight::VertexArray::Create();

	float verticies[3 * 7] = {
		-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
		 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
		 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
	};

	FarLight::BufferLayout layout = {
		{ FarLight::ShaderDataType::Float3, "a_Position" },
		{ FarLight::ShaderDataType::Float4, "a_Color" }
	};
	std::shared_ptr<FarLight::VertexBuffer> vertexBuffer = FarLight::VertexBuffer::Create(verticies, sizeof(verticies), layout);
	_vertexArray->AddVertexBuffer(vertexBuffer);

	unsigned int indices[3] = { 0, 1, 2 };
	std::shared_ptr<FarLight::IndexBuffer> indexBuffer = FarLight::IndexBuffer::Create(indices, sizeof(indices) / sizeof(unsigned int));
	_vertexArray->SetIndexBuffer(indexBuffer);

	_squareVertexArray = FarLight::VertexArray::Create();

	float squareVertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,   1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f,   0.0f, 1.0f
	};

	FarLight::BufferLayout squareLayout = {
		{ FarLight::ShaderDataType::Float3, "a_Position" },
		{ FarLight::ShaderDataType::Float2, "a_TexCoord" }
	};
	std::shared_ptr<FarLight::VertexBuffer> squareVertexBuffer = FarLight::VertexBuffer::Create(squareVertices, sizeof(squareVertices), squareLayout);
	_squareVertexArray->AddVertexBuffer(squareVertexBuffer);

	unsigned int squareIndicies[6] = { 0, 1, 2, 2, 3, 0 };
	std::shared_ptr<FarLight::IndexBuffer> squareIndexBuffer = FarLight::IndexBuffer::Create(squareIndicies, sizeof(squareIndicies) / sizeof(unsigned int));
	_squareVertexArray->SetIndexBuffer(squareIndexBuffer);

	_shaderLib.Add("ColorTriangle", FarLight::Shader::Create("assets/shaders/ColorTriangle/ColorTriangle.vert", "assets/shaders/ColorTriangle/ColorTriangle.frag"));
	_shaderLib.Add("Square", FarLight::Shader::Create("assets/shaders/Square/Square.vert", "assets/shaders/Square/Square.frag"));
	_shaderLib.Add("Texture", FarLight::Shader::Create("assets/shaders/Texture/Texture.vert", "assets/shaders/Texture/Texture.frag"));

	_textureLib.Add("Box", FarLight::Texture2D::Create("assets/textures/Box.png"));
	_textureLib.Add("ShovelKnight", FarLight::Texture2D::Create("assets/textures/ShovelKnightDigPromo.png"));

	std::dynamic_pointer_cast<FarLight::OpenGLShader>(_shaderLib.Get("Texture"))->Bind();
	std::dynamic_pointer_cast<FarLight::OpenGLShader>(_shaderLib.Get("Texture"))->UploadUniformInt("u_Texture", 0);
}

void ExampleLayer::OnAttach() const
{
}

void ExampleLayer::OnDetach() const
{
}

void ExampleLayer::OnUpdate(const FarLight::Timestep& timestamp)
{
	HandleInput(timestamp);

	FarLight::Renderer::BeginScene(_camera);

	_shaderLib.Get("Square")->Bind();
	std::dynamic_pointer_cast<FarLight::OpenGLShader>(_shaderLib.Get("Square"))->UploadUniformFloat3("u_Color", _squareColor.r, _squareColor.g, _squareColor.b);

	/*for (int y = -5; y < 5; ++y) {
		for (int x = -5; x < 5; ++x) {
			glm::mat4 squareModelMatrix = glm::mat4(1.0f);
			squareModelMatrix = glm::translate(squareModelMatrix, glm::vec3(x * 0.11f + _squarePosition.x, y * 0.11f + _squarePosition.y, 0.0f));
			squareModelMatrix = glm::scale(squareModelMatrix, glm::vec3(0.1f));
			FarLight::Renderer::Submit(_shaderLib.Get("Square"), _squareVertexArray, squareModelMatrix);
		}
	}*/
	
	_textureLib.Get("Box")->Bind(0);
	FarLight::Renderer::Submit(_shaderLib.Get("Texture"), _squareVertexArray);
	_textureLib.Get("ShovelKnight")->Bind(0);
	FarLight::Renderer::Submit(_shaderLib.Get("Texture"), _squareVertexArray);

	//FL_TRACE("Camera position: {0} {1} {2}", _camera.GetPosition().x, _camera.GetPosition().y, _camera.GetPosition().z);

	//FarLight::Renderer::Submit(_shaderLib.Get("ColorTriangle"), _vertexArray);

	FarLight::Renderer::EndScene();
}

void ExampleLayer::OnUserInterfaceRender()
{
	ImGui::Begin("Squares color");
	ImGui::ColorEdit3("Color", glm::value_ptr(_squareColor));
	ImGui::End();
}

void ExampleLayer::OnEvent(FarLight::Event& event)
{
}

void ExampleLayer::HandleInput(const FarLight::Timestep& timestamp)
{
	//FL_TRACE("Delta time: {0} s. ({1} ms.)", timestamp.GetSeconds(), timestamp.GetMilliseconds());

	if (FarLight::Input::IsKeyPressed(FarLight::KeyboardKeyCodes::FL_KEY_LEFT))
		_camera.ProcessCameraMovement(FarLight::OrthographicCamera::MovementDirection::Left, static_cast<float>(timestamp));
	else if (FarLight::Input::IsKeyPressed(FarLight::KeyboardKeyCodes::FL_KEY_RIGHT))
		_camera.ProcessCameraMovement(FarLight::OrthographicCamera::MovementDirection::Right, static_cast<float>(timestamp));

	if (FarLight::Input::IsKeyPressed(FarLight::KeyboardKeyCodes::FL_KEY_DOWN))
		_camera.ProcessCameraMovement(FarLight::OrthographicCamera::MovementDirection::Down, static_cast<float>(timestamp));
	else if (FarLight::Input::IsKeyPressed(FarLight::KeyboardKeyCodes::FL_KEY_UP))
		_camera.ProcessCameraMovement(FarLight::OrthographicCamera::MovementDirection::Up, static_cast<float>(timestamp));

	if (FarLight::Input::IsKeyPressed(FarLight::KeyboardKeyCodes::FL_KEY_Q))
		_camera.ProcessCameraRotation(static_cast<float>(timestamp));
	else if (FarLight::Input::IsKeyPressed(FarLight::KeyboardKeyCodes::FL_KEY_E))
		_camera.ProcessCameraRotation(-static_cast<float>(timestamp));

	if (FarLight::Input::IsKeyPressed(FarLight::KeyboardKeyCodes::FL_KEY_D))
		_squarePosition.x += _squareMovementSpeed * static_cast<float>(timestamp);
	else if (FarLight::Input::IsKeyPressed(FarLight::KeyboardKeyCodes::FL_KEY_A))
		_squarePosition.x -= _squareMovementSpeed * static_cast<float>(timestamp);

	if (FarLight::Input::IsKeyPressed(FarLight::KeyboardKeyCodes::FL_KEY_W))
		_squarePosition.y += _squareMovementSpeed * static_cast<float>(timestamp);
	else if (FarLight::Input::IsKeyPressed(FarLight::KeyboardKeyCodes::FL_KEY_S))
		_squarePosition.y -= _squareMovementSpeed * static_cast<float>(timestamp);
}
