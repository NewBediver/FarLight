#include "Example2DRenderer.h"

#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>

Example2DRenderer::Example2DRenderer()
	: Layer("Example2DRenderer")
	, _cameraController(1280.0f / 720.0f)
	, _color(0.25f, 0.25f, 0.5f, 1.0f)
{ }

void Example2DRenderer::OnAttach()
{
	_vertexArray = FarLight::VertexArray::Create();

	float squareVertices[3 * 4] = {
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};

	FarLight::BufferLayout squareLayout = {
		{ FarLight::ShaderDataType::Float3, "a_Position" }
	};
	_vertexArray->AddVertexBuffer(FarLight::VertexBuffer::Create(squareVertices, sizeof(squareVertices), squareLayout));

	unsigned int squareIndicies[6] = { 0, 1, 2, 2, 3, 0 };
	_vertexArray->SetIndexBuffer(FarLight::IndexBuffer::Create(squareIndicies, sizeof(squareIndicies) / sizeof(unsigned int)));

	_shader = FarLight::Shader::Create("assets/shaders/Square/Square.vert", "assets/shaders/Square/Square.frag");
}

void Example2DRenderer::OnDetach()
{

}

void Example2DRenderer::OnUpdate(const FarLight::Timestep& timestamp)
{
	_cameraController.OnUpdate(timestamp);

	FarLight::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	FarLight::RenderCommand::Clear();

	FarLight::Renderer::BeginScene(_cameraController.GetCamera());

	_shader->Bind();
	std::dynamic_pointer_cast<FarLight::OpenGLShader>(_shader)->UploadUniformFloat4("u_Color", _color.r, _color.g, _color.b, _color.a);

	FarLight::Renderer::Submit(_shader, _vertexArray);

	FarLight::Renderer::EndScene();
}

void Example2DRenderer::OnUserInterfaceRender()
{
	ImGui::Begin("Squares color");
	ImGui::ColorEdit4("Color", glm::value_ptr(_color));
	ImGui::End();
}

void Example2DRenderer::OnEvent(FarLight::Event& event)
{
	_cameraController.OnEvent(event);
}