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

	FarLight::Renderer2D::DrawQuad({ 0.0f, -0.5f, -0.1f }, { 10.0f, 10.0f }, m_Texture, 1.5f);
	FarLight::Renderer2D::DrawRotatedQuad({ 1.0f, 1.0f, 0.0f }, { 1.3f, 0.6f }, m_Rotation, { 0.8f, 0.2f, 0.3f, 1.0f });
	FarLight::Renderer2D::DrawQuad({ -1.0f, 0.3f }, { 0.8f, 1.5f }, { 0.3f, 0.2f, 0.8f, 1.0f });
	FarLight::Renderer2D::DrawRotatedQuad({ 0.0f, -0.5f }, { 1.0f, 1.0f }, -m_Rotation, m_ShovelKnightTexture, 2.0f, { 0.3f, 0.8f, 0.2f, 1.0f });

	for (float x = -10.0f; x < 10.0f; x += 0.5f)
	{
		for (float y = -10.0f; y < 10.0f; y += 0.5f)
		{
			FarLight::Renderer2D::DrawQuad({ x, y, 0.1f }, { 0.45f, 0.45f }, m_Texture, 1.0f, { x + 100.0f / 200.0f, 0.6f, y + 100.0f / 200.0f, 0.7f });
		}
	}

	m_Controller = FarLight::Renderer2D::GetRender2DBatchController();

	FarLight::Renderer2D::EndScene();
}

void Example2DRenderer::OnUserInterfaceRender() noexcept
{
	ImGui::Begin("Batching Statistics");

	for (int i = 0; i < m_Controller.GetBatches().size(); ++i)
	{
		ImGui::Text("========== Statistic for batch #%d:", i+1);
		ImGui::Text("   Maximum Vertex Count: %d", m_Controller.GetBatches()[i].GetStatistic().MaxVertexNumber);
		ImGui::Text("   Used Vertex Count: %d", m_Controller.GetBatches()[i].GetStatistic().UsedVertexNumber);
		ImGui::Text("   Maximum Index Count: %d", m_Controller.GetBatches()[i].GetStatistic().MaxIndexNumber);
		ImGui::Text("   Used Index Count: %d", m_Controller.GetBatches()[i].GetStatistic().UsedIndexNumber);
		ImGui::Text("   Maximum Texture Slots: %d", m_Controller.GetBatches()[i].GetStatistic().MaxTextureSlots);
		ImGui::Text("   Used Texture Slots: %d", m_Controller.GetBatches()[i].GetStatistic().UsedTextureSlots);
		ImGui::Text("   Used Shader ID: %d", m_Controller.GetBatches()[i].GetStatistic().UsedShader->GetID());
		ImGui::Text("   Used Default Texture ID: %d", m_Controller.GetBatches()[i].GetStatistic().UsedTextures[0]->GetID());
		ImGui::Text("   Used Layout Size, Count and Stride: %d / %d / %d", m_Controller.GetBatches()[i].GetStatistic().UsedLayout.GetElements().size(), m_Controller.GetBatches()[i].GetStatistic().UsedLayout.GetCount(), m_Controller.GetBatches()[i].GetStatistic().UsedLayout.GetStride());
	}

	ImGui::End();
}

void Example2DRenderer::OnEvent(FarLight::Event& event) noexcept
{
	m_CameraController.OnEvent(event);
}