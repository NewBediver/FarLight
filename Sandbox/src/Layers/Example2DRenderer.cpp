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
	, m_Timer("Example2DRenderer", std::bind(&Example2DRenderer::LogTimerData, this, std::placeholders::_1, std::placeholders::_2))
	, m_TotalTimer("Total time", std::bind(&Example2DRenderer::LogTimerData, this, std::placeholders::_1, std::placeholders::_2))
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
	m_TotalTimer.Start();
	m_Timer.Start("CameraController::OnUpdate");
	m_CameraController.OnUpdate(timestamp);
	m_Timer.Stop();

	m_Timer.Start("RenderCommand usage");
	FarLight::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	FarLight::RenderCommand::Clear();
	m_Timer.Stop();

	m_Timer.Start("Renderer2D::BeginScene");
	FarLight::Renderer2D::BeginScene(m_CameraController.GetCamera());
	m_Timer.Stop();

	m_Timer.Start("Renderer2D::DrawQuad (4 times)");
	FarLight::Renderer2D::DrawQuad({1.0f, 1.0f, 0.0f}, {1.3f, 0.6f}, {0.8f, 0.2f, 0.3f, 1.0f});
	FarLight::Renderer2D::DrawQuad({ 0.0f, -0.5f, -0.1f }, { 10.0f, 10.0f }, m_Texture);
	FarLight::Renderer2D::DrawQuad({ -1.0f, 0.3f}, { 0.8f, 1.5f }, { 0.3f, 0.2f, 0.8f, 1.0f });
	FarLight::Renderer2D::DrawQuad({ 0.0f, -0.5f }, { 1.0f, 1.0f }, m_ShovelKnightTexture, {0.3f, 0.8f, 0.2f, 1.0f});
	m_Timer.Stop();

	m_Timer.Start("Renderer2D::EndScene");
	FarLight::Renderer2D::EndScene();
	m_Timer.Stop();
	m_TotalTimer.Stop();
}

void Example2DRenderer::OnUserInterfaceRender()
{
	ImGui::Begin("Example2DRenderer layer CPU profiler");
	for (const auto& p : m_CPUProfilerData)
	{
		std::stringstream ss;
		ss << p.first << ": " << std::setprecision(3) << std::fixed << p.second << " ms.";
		ImGui::Text(ss.str().c_str());
	}
	ImGui::End();
}

void Example2DRenderer::OnEvent(FarLight::Event& event)
{
	m_CameraController.OnEvent(event);
}

void Example2DRenderer::LogTimerData(const std::string& name, float duration)
{
	m_CPUProfilerData[name] = duration;
}
