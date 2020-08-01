#include <functional>
#include <sstream>
#include <iomanip>

#include "Example2DRenderer.h"

#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>

Example2DRenderer::Example2DRenderer()
	: Layer("Example2DRenderer")
	, m_CameraController(1280.0f / 720.0f)
{ }

void Example2DRenderer::OnAttach()
{
	m_Texture = FarLight::Texture2D::Create("assets/textures/Box.png");
	m_ShovelKnightTexture = FarLight::Texture2D::Create("assets/textures/ShovelKnightDigPromo.png");
}

void Example2DRenderer::OnDetach()
{

}

void Example2DRenderer::OnUpdate(const FarLight::Timestep& timestamp)
{
	FL_PROFILE_FUNCTION();

	{
		FL_PROFILE_SCOPE("CameraController::OnUpdate");
		m_CameraController.OnUpdate(timestamp);
	}
	
	{
		FL_PROFILE_SCOPE("Renderer Prep");
		FarLight::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		FarLight::RenderCommand::Clear();
	}

	{
		FL_PROFILE_SCOPE("Renderer Draw");
		FarLight::Renderer2D::BeginScene(m_CameraController.GetCamera());

		FarLight::Renderer2D::DrawQuad({ 1.0f, 1.0f, 0.0f }, { 1.3f, 0.6f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		FarLight::Renderer2D::DrawQuad({ 0.0f, -0.5f, -0.1f }, { 10.0f, 10.0f }, m_Texture);
		FarLight::Renderer2D::DrawQuad({ -1.0f, 0.3f }, { 0.8f, 1.5f }, { 0.3f, 0.2f, 0.8f, 1.0f });
		FarLight::Renderer2D::DrawQuad({ 0.0f, -0.5f }, { 1.0f, 1.0f }, m_ShovelKnightTexture, { 0.3f, 0.8f, 0.2f, 1.0f });

		FarLight::Renderer2D::EndScene();
	}
}

void Example2DRenderer::OnUserInterfaceRender()
{
	FL_PROFILE_FUNCTION();
}

void Example2DRenderer::OnEvent(FarLight::Event& event)
{
	FL_PROFILE_FUNCTION();
	m_CameraController.OnEvent(event);
}