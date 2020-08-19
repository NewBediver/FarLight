#include "EditorLayer.h"

#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>

namespace FarLight
{
	EditorLayer::EditorLayer() noexcept
		: Layer("Editor Layer")
		, m_CameraController(1280.0f / 720.0f)
		, m_Rotation(0.0f)
		, m_IsRenderViewportFocused(false)
		, m_IsRenderViewportHovered(false)
	{ }

	void EditorLayer::OnAttach() noexcept
	{
		FramebufferSpecification spec;
		spec.Width = 1280;
		spec.Height = 720;
		m_Framebuffer = Framebuffer::Create(spec);

		m_Texture = Texture2D::Create("assets/textures/Box.png");
		m_ShovelKnightTexture = Texture2D::Create("assets/textures/ShovelKnightDigPromo.png");
	}

	void EditorLayer::OnDetach() noexcept
	{

	}

	void EditorLayer::OnUpdate(const Timestep& timestamp) noexcept
	{
		if (m_IsRenderViewportFocused)
			m_CameraController.OnUpdate(timestamp);

		m_Rotation += static_cast<float>(timestamp);

		m_Framebuffer->Bind();
		RenderCommand::SetClearColor({ 0.5f, 0.5f, 0.5f, 1.0f });
		RenderCommand::Clear();

		Renderer2D::BeginScene(m_CameraController.GetCamera());

		FarLight::Renderer2D::DrawQuad({ 0.0f, -0.5f, -0.1f }, { 10.0f, 10.0f }, m_Texture, 1.5f);
		FarLight::Renderer2D::DrawRotatedQuad({ 1.0f, 1.0f, 0.0f }, { 1.3f, 0.6f }, m_Rotation, { 0.8f, 0.2f, 0.3f, 1.0f });
		FarLight::Renderer2D::DrawQuad({ -1.0f, 0.3f }, { 0.8f, 1.5f }, { 0.3f, 0.2f, 0.8f, 1.0f });
		FarLight::Renderer2D::DrawRotatedQuad({ 0.0f, -0.5f }, { 1.0f, 1.0f }, -m_Rotation, m_ShovelKnightTexture, 2.0f, { 0.3f, 0.8f, 0.2f, 1.0f });

		for (float x = -10.0f; x < 10.0f; x += 1.0f)
		{
			for (float y = -10.0f; y < 10.0f; y += 1.0f)
			{
				FarLight::Renderer2D::DrawQuad({ x, y, 0.1f }, { 0.45f, 0.45f }, m_Texture, 1.0f, { x + 100.0f / 200.0f, 0.6f, y + 100.0f / 200.0f, 0.7f });
			}
		}
		
		Renderer2D::EndScene();
		m_Framebuffer->Unbind();

	}

	void EditorLayer::OnUserInterfaceRender() noexcept
	{
		EnableDocking();
		UpdateRenderViewport();

		GetBatchingStatistic();
	}

	void EditorLayer::OnEvent(Event& event) noexcept
	{
		m_CameraController.OnEvent(event);
	}

	void EditorLayer::EnableDocking() const noexcept
	{
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
		// because it would be confusing to have two docking targets within each others.
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->GetWorkPos());
		ImGui::SetNextWindowSize(viewport->GetWorkSize());
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
		// and handle the pass-thru hole, so we ask Begin() to not render a background.
		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
		// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
		// all active windows docked into it will lose their parent and become undocked.
		// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
		// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace", nullptr, window_flags);
		ImGui::PopStyleVar();

		ImGui::PopStyleVar(2);

		// DockSpace
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}

		UpdateMenuBar();

		ImGui::End();
	}

	void EditorLayer::UpdateMenuBar() const noexcept
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Exit", "E")) FarLight::Application::GetInstance().Close();
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
	}

	void EditorLayer::UpdateRenderViewport() noexcept
	{
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0, 0 });
		ImGui::Begin("Render Viewport", nullptr);

		m_IsRenderViewportFocused = ImGui::IsWindowFocused();
		m_IsRenderViewportHovered = ImGui::IsWindowHovered();
		Application::GetInstance().SetEditorEventsBlock(!m_IsRenderViewportFocused || !m_IsRenderViewportHovered);

		auto tmp = ImGui::GetContentRegionAvail();
		m_Framebuffer->Resize(static_cast<unsigned>(tmp.x), static_cast<unsigned>(tmp.y));
		m_CameraController.OnResize(tmp.x, tmp.y);

		unsigned renderTextureID = m_Framebuffer->GetColorAttachmentID();
		ImGui::Image(reinterpret_cast<void*>(renderTextureID), { static_cast<float>(m_Framebuffer->GetSpecification().Width), static_cast<float>(m_Framebuffer->GetSpecification().Height) }, { 0, 1 }, { 1, 0 });
		ImGui::End();
		ImGui::PopStyleVar();
	}

	void EditorLayer::GetBatchingStatistic() const noexcept
	{
		auto& controller = Renderer2D::GetRender2DBatchController();
		ImGui::Begin("Batching Statistics");
		for (unsigned i = 0; i < controller.GetBatches().size(); ++i)
		{
			ImGui::Text("========== Statistic for batch #%d: ==========", i + 1);
			ImGui::Text("   Maximum Vertex Count: %d", controller.GetBatches()[i].GetStatistic().MaxVertexNumber);
			ImGui::Text("   Maximum Index Count: %d", controller.GetBatches()[i].GetStatistic().MaxIndexNumber);
			ImGui::Text("   Maximum Texture Slots: %d", controller.GetBatches()[i].GetStatistic().MaxTextureSlots);
			ImGui::Text("   Used Shader ID: %d", controller.GetBatches()[i].GetStatistic().UsedShader->GetID());
			ImGui::Text("   Used Default Texture ID: %d", controller.GetBatches()[i].GetStatistic().UsedTextures[0]->GetID());
			ImGui::Text("   Used Layout Size, Count and Stride: %d / %d / %d", controller.GetBatches()[i].GetStatistic().UsedLayout.GetElements().size(), controller.GetBatches()[i].GetStatistic().UsedLayout.GetCount(), controller.GetBatches()[i].GetStatistic().UsedLayout.GetStride());
			ImGui::Text("   Render calls: %d", controller.GetBatches()[i].GetStatistic().GetRenderStatistic().size());
			for (unsigned j = 0; j < controller.GetBatches()[i].GetStatistic().GetRenderStatistic().size(); ++j)
			{
				ImGui::Text("   ===== Statistic for render call #%d: =====", j + 1);
				ImGui::Text("      Used Vertex Count: %d", controller.GetBatches()[i].GetStatistic().GetRenderStatistic()[j].UsedVertexNumber);
				ImGui::Text("      Used Index Count: %d", controller.GetBatches()[i].GetStatistic().GetRenderStatistic()[j].UsedIndexNumber);
				ImGui::Text("      Used Texture Slots: %d", controller.GetBatches()[i].GetStatistic().GetRenderStatistic()[j].UsedTextureSlots);
				ImGui::Text("   =========================================");
			}
			ImGui::Text("============================================");
		}
		ImGui::End();
	}
}