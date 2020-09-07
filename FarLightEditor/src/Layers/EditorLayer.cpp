#include "EditorLayer.h"

#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>
#include <imgui_internal.h>

namespace FarLight
{
    EditorLayer::EditorLayer() noexcept
        : Layer("Editor Layer")
    { }

    void EditorLayer::OnAttach() noexcept
    {
        FramebufferSpecification spec = { 1280, 720 };
        m_Framebuffer = Framebuffer::Create(spec);

        m_Scene = Scene::Create();
        auto tmp = m_Scene->CreateEntity("Square");
        tmp.GetComponent<TransformComponent>().SetSize(glm::vec3(400.0f, 400.0f, 0.0f));
        tmp.AddComponent<RenderComponent>(glm::vec4(0.2f, 0.8, 0.6f, 1.0f));

        /*auto camera = m_Scene->CreateEntity("Camera");
        camera.AddComponent<CameraComponent>(spec.Width, spec.Height, true);

        class Script
            : public ScriptableBehaviour
        {
            virtual void OnCreate() noexcept override
            {
                FL_TRACE("Script::OnCreate()");
            }

            virtual void OnDestroy() noexcept override
            {
                FL_TRACE("Script::OnDestroy()");
            }

            virtual void OnUpdate(const Timestep& ts) noexcept override
            {
                FL_TRACE("Script::OnUpdate()");

                auto& transformComp = GetComponent<TransformComponent>();
                float speed = 5.0f;
                float velocity = speed * ts;

                glm::vec3 position = transformComp.GetPosition();

                if (Input::IsKeyPressed(KeyboardKeyCode::FL_KEY_W)) position.y += velocity;
                else if (Input::IsKeyPressed(KeyboardKeyCode::FL_KEY_S)) position.y -= velocity;

                if (Input::IsKeyPressed(KeyboardKeyCode::FL_KEY_A)) position.x -= velocity;
                else if (Input::IsKeyPressed(KeyboardKeyCode::FL_KEY_D)) position.x += velocity;

                transformComp.SetPosition(position);

                if (HasAllComponents<CameraComponent>())
                {
                    auto& camera = GetComponent<CameraComponent>().GetCamera();

                    if (Input::IsKeyPressed(KeyboardKeyCode::FL_KEY_Q)) camera->SetZoom(camera->GetZoom() - velocity);
                    else if (Input::IsKeyPressed(KeyboardKeyCode::FL_KEY_E)) camera->SetZoom(camera->GetZoom() + velocity);
                }
            }
        };
        camera.AddComponent<NativeScriptComponent>().Bind<Script>();*/

        m_Panels.Hierarchy = CreateScope<SceneHierarchyPanel>(m_Scene);
    }

    void EditorLayer::OnDetach() noexcept
    {

    }

    void EditorLayer::OnUpdate(const Timestep& timestep) noexcept
    {
        m_Framebuffer->Resize(static_cast<unsigned>(m_RenderViewportOptions.Width), static_cast<unsigned>(m_RenderViewportOptions.Height));
        //m_CameraController.OnResize(m_RenderViewportOptions.Width, m_RenderViewportOptions.Height);
        m_Scene->OnViewportResize(m_RenderViewportOptions.Width, m_RenderViewportOptions.Height);

        /*if (m_RenderViewportOptions.IsFocused && m_RenderViewportOptions.IsHovered)
            m_CameraController.OnUpdate(timestep);*/

        m_Framebuffer->Bind();

        m_Scene->OnUpdate(timestep);

        m_Framebuffer->Unbind();

    }

    void EditorLayer::OnUserInterfaceRender() noexcept
    {
        //bool demo = true;
        //ImGui::ShowDemoWindow(&demo);

        EnableDocking();
        UpdateRenderViewport();

        m_Panels.Hierarchy->ShowContent();

        if (m_Options.ShowBatchStatistics) GetBatchingStatistic();

        if (m_Options.ShowFileSystem) GetFileSystem();
    }

    void EditorLayer::OnEvent(Event& event) noexcept
    {
        //m_CameraController.OnEvent(event);
        m_Scene->OnEvent(event);
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
                if (ImGui::MenuItem("Show ECS", "ECS")) m_Panels.Hierarchy->SetShown(true);
                if (ImGui::MenuItem("Show batch statistics", "B")) m_Options.ShowBatchStatistics = true;
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Entities"))
            {
                if (ImGui::MenuItem("Create Empty", "CE")) m_Scene->CreateEntity();
                if (ImGui::MenuItem("Create Square", "CS")) m_Scene->CreateSquare();
                if (ImGui::MenuItem("Create Camera", "CC")) m_Scene->CreateCamera();
                ImGui::Separator();
                if (ImGui::MenuItem("Show ECS", "ECS")) m_Panels.Hierarchy->SetShown(true);
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
    }

    void EditorLayer::UpdateRenderViewport() noexcept
    {
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0, 0 });
        ImGui::Begin("Render Viewport", nullptr);

        m_RenderViewportOptions.IsFocused = ImGui::IsWindowFocused();
        m_RenderViewportOptions.IsHovered = ImGui::IsWindowFocused();
        m_Scene->SetIsRenderViewportFocused(m_RenderViewportOptions.IsFocused);
        m_Scene->SetIsRenderViewportHovered(m_RenderViewportOptions.IsHovered);
        Application::GetInstance().SetEditorEventsBlock(!m_RenderViewportOptions.IsFocused || !m_RenderViewportOptions.IsHovered);

        auto tmp = ImGui::GetContentRegionAvail();
        m_RenderViewportOptions.Width = tmp.x;
        m_RenderViewportOptions.Height = tmp.y;

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
        std::string label = directory.GetAbsolutePath().c_str();
        if (ImGui::TreeNode(label.c_str()))
        {
            for (auto& node : directory.GetDirectoryMap())
            {
                DirectoryTraverslBuild(node.second);
            }
            ImGui::TreePop();
        }
    }
}
