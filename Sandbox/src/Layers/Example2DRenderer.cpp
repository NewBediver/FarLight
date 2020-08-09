#include <functional>
#include <sstream>
#include <iomanip>

#include "Example2DRenderer.h"

#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>

Example2DRenderer::Example2DRenderer() noexcept
	: Layer("Example2DRenderer")
	, m_CameraController(1280.0f / 720.0f)
	, m_Rotation(0.0f)
{ }

void Example2DRenderer::OnAttach() noexcept
{
	m_Texture = FarLight::Texture2D::Create("assets/textures/Box.png");
	m_ShovelKnightTexture = FarLight::Texture2D::Create("assets/textures/ShovelKnightDigPromo.png");
}

void Example2DRenderer::OnDetach() noexcept
{

}

void Example2DRenderer::OnUpdate(const FarLight::Timestep& timestamp) noexcept
{
	m_CameraController.OnUpdate(timestamp);
	
	m_Rotation += static_cast<float>(timestamp);

	FarLight::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	FarLight::RenderCommand::Clear();

	FarLight::Renderer2D::BeginScene(m_CameraController.GetCamera());

	FarLight::Renderer2D::DrawRotatedQuad({ 1.0f, 1.0f, 0.0f }, { 1.3f, 0.6f }, m_Rotation, { 0.8f, 0.2f, 0.3f, 1.0f });
	FarLight::Renderer2D::DrawQuad({ 0.0f, -0.5f, -0.1f }, { 10.0f, 10.0f }, m_Texture, 1.5f);
	FarLight::Renderer2D::DrawQuad({ -1.0f, 0.3f }, { 0.8f, 1.5f }, { 0.3f, 0.2f, 0.8f, 1.0f });
	FarLight::Renderer2D::DrawRotatedQuad({ 0.0f, -0.5f }, { 1.0f, 1.0f }, -m_Rotation, m_ShovelKnightTexture, 2.0f, { 0.3f, 0.8f, 0.2f, 1.0f });

	FarLight::Renderer2D::EndScene();
}

void Example2DRenderer::OnUserInterfaceRender() noexcept
{
}

void Example2DRenderer::OnEvent(FarLight::Event& event) noexcept
{
	m_CameraController.OnEvent(event);
}