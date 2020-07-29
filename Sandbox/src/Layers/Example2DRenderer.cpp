#include "Example2DRenderer.h"

#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>

Example2DRenderer::Example2DRenderer()
	: Layer("Example2DRenderer")
	, _cameraController(1280.0f / 720.0f)
	, _position(0.0f, 0.0f)
	, _size(1.0f, 1.0f)
	, _color(0.25f, 0.25f, 0.5f, 1.0f)
{ }

void Example2DRenderer::OnAttach()
{
	
}

void Example2DRenderer::OnDetach()
{

}

void Example2DRenderer::OnUpdate(const FarLight::Timestep& timestamp)
{
	_cameraController.OnUpdate(timestamp);

	FarLight::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	FarLight::RenderCommand::Clear();

	FarLight::Renderer2D::BeginScene(_cameraController.GetCamera());

	FarLight::Renderer2D::DrawQuad(_position, _size, _color);

	FarLight::Renderer2D::EndScene();
}

void Example2DRenderer::OnUserInterfaceRender()
{
	ImGui::Begin("Squares color");
	ImGui::ColorEdit4("Color", glm::value_ptr(_color));
	ImGui::End();

	ImGui::Begin("Square size");
	ImGui::SliderFloat2("Width/Height", glm::value_ptr(_size), 0.0f, 10.0f);
	ImGui::End();

	ImGui::Begin("Square position");
	ImGui::InputFloat2("x/y", glm::value_ptr(_position), 3);
	ImGui::End();
}

void Example2DRenderer::OnEvent(FarLight::Event& event)
{
	_cameraController.OnEvent(event);
}