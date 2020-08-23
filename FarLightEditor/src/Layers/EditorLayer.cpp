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
		FramebufferSpecification spec = {1280, 720};
		m_Framebuffer = Framebuffer::Create(spec);

		//m_Texture = Texture2D::Create("assets/textures/Box.png");
		//m_ShovelKnightTexture = Texture2D::Create("assets/textures/ShovelKnightDigPromo.png");

		m_Scene = Scene::Create();
		m_Square = CreateRef<Entity>(m_Scene->CreateEntity("Square"));
		m_Square->AddComponent<RendererComponent>(glm::vec4(0.2f, 0.8, 0.6f, 1.0f));

		/*Renderer2D::DrawQuad({ 0.0f, -0.5f, -0.1f }, { 10.0f, 10.0f }, m_Texture, 1.5f, glm::vec4(1.0f), BatchType::Static);
		Renderer2D::DrawQuad({ -1.0f, 0.3f }, { 0.8f, 1.5f }, { 0.3f, 0.2f, 0.8f, 1.0f }, BatchType::Static);*/
	}

	void EditorLayer::OnDetach() noexcept
	{

	}

	void EditorLayer::OnUpdate(const Timestep& timestep) noexcept
	{
		if (m_IsRenderViewportFocused)
			m_CameraController.OnUpdate(timestep);

		m_Rotation += static_cast<float>(timestep);

		m_Framebuffer->Bind();
		RenderCommand::SetClearColor({ 0.5f, 0.5f, 0.5f, 1.0f });
		RenderCommand::Clear();

		Renderer2D::BeginScene(m_CameraController.GetCamera());

		/*Renderer2D::DrawRotatedQuad({ 1.0f, 1.0f, 0.0f }, { 1.3f, 0.6f }, m_Rotation, { 0.8f, 0.2f, 0.3f, 1.0f });
		Renderer2D::DrawRotatedQuad({ 0.0f, -0.5f }, { 1.0f, 1.0f }, -m_Rotation, m_ShovelKnightTexture, 2.0f, { 0.3f, 0.8f, 0.2f, 1.0f });

		for (float x = -20.0f; x < 20.0f; x += 2.0f)
		{
			for (float y = -20.0f; y < 20.0f; y += 2.0f)
			{
				Renderer2D::DrawQuad({ x, y, 0.1f }, { 1.0f, 1.0f }, { (x + 20.0f) / 40.0f, 0.6f, (y + 20.0f) / 40.0f, 0.7f });
			}
		}*/
		m_Scene->OnUpdate(timestep);
		
		Renderer2D::EndScene();
		m_Framebuffer->Unbind();

	}

	void EditorLayer::OnUserInterfaceRender() noexcept
	{
		EnableDocking();
		UpdateRenderViewport();

		if (m_Options.ShowBatchStatistics) GetBatchingStatistic();
		if (m_Options.ShowFileSystem) GetFileSystem();
	}

	void EditorLayer::OnEvent(Event& event) noexcept
	{
		m_CameraController.OnEvent(event);
	}

	void EditorLayer::EnableDocking() noexcept
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

	void EditorLayer::UpdateMenuBar() noexcept
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Show file system", "Fs")) m_Options.ShowFileSystem = true;
				if (ImGui::MenuItem("Exit", "E")) Application::GetInstance().Close();
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Tools"))
			{
				if (ImGui::MenuItem("Show batch statistics", "B")) m_Options.ShowBatchStatistics = true;
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

	void EditorLayer::GetBatchingStatistic() noexcept
	{
		auto& controller = Renderer2D::GetRender2DBatchController();
		ImGui::Begin("Batching Statistics", &m_Options.ShowBatchStatistics);
		for (unsigned i = 0; i < controller->GetBatches().size(); ++i)
		{
			std::string name = "Statistics for batch #" + std::to_string(i + 1);
			if (ImGui::CollapsingHeader(name.c_str()))
			{
				ImGui::BulletText("Batch type: %s", controller->GetBatches()[i].GetConfiguration().Type == BatchType::Dynamic ? "Dynamic" : "Static");
				ImGui::Separator();
				ImGui::BulletText("Maximum Vertex Count: %d", controller->GetBatches()[i].GetConfiguration().MaxVertexNumber);
				ImGui::BulletText("Used Vertex Count: %d", controller->GetBatches()[i].GetConfiguration().UsedVertexNumber);
				ImGui::Separator();
				ImGui::BulletText("Maximum Index Count: %d", controller->GetBatches()[i].GetConfiguration().MaxIndexNumber);
				ImGui::BulletText("Used Index Count: %d", controller->GetBatches()[i].GetConfiguration().UsedIndexNumber);
				ImGui::Separator();
				ImGui::BulletText("Maximum Texture Slots: %d", controller->GetBatches()[i].GetConfiguration().MaxTextureSlots);
				ImGui::BulletText("Used Texture Slots: %d", controller->GetBatches()[i].GetConfiguration().UsedTextureSlots);
				ImGui::Separator();
				ImGui::BulletText("Used Shader ID: %d", controller->GetBatches()[i].GetConfiguration().UsedShader->GetID());
				ImGui::BulletText("Used Default Texture ID: %d", controller->GetBatches()[i].GetConfiguration().UsedTextures[0]->GetID());
				ImGui::BulletText("Used Layout Size, Count and Stride: %d / %d / %d", controller->GetBatches()[i].GetConfiguration().UsedLayout.GetElements().size(), controller->GetBatches()[i].GetConfiguration().UsedLayout.GetCount(), controller->GetBatches()[i].GetConfiguration().UsedLayout.GetStride());
			}
		}
		ImGui::End();
	}

	void EditorLayer::GetFileSystem() noexcept
	{
		ImGui::Begin("File system", &m_Options.ShowFileSystem);
		DirectoryTraverslBuild(FileSystem::GetAssetsDirectory());
		DirectoryTraverslBuild(FileSystem::GetEditorDirectory());
		DirectoryTraverslBuild(FileSystem::GetResourcesDirectory());
		ImGui::End();
	}

	void EditorLayer::DirectoryTraverslBuild(Directory& directory) noexcept
	{
		if (ImGui::TreeNode(directory.GetRelativePath().c_str()))
		{
			for (auto& node : directory.GetDirectoryMap())
			{
				DirectoryTraverslBuild(node.second);
			}
			ImGui::TreePop();
		}
	}
}