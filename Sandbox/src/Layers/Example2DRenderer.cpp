#include <functional>
#include <sstream>
#include <iomanip>

#include "Example2DRenderer.h"

#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>

static const char* s_Map =
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGQUUUUUEGGGGGGG"
"GGGGGGGGGGGGGuQUsWWWoWaEGGGGGG"
"GGGGGGGGGGGGGQsWWWWWWWWRGGGGGG"
"GGGGGGGGGGuGGLWWpWWiWWOaUUEGGG"
"GGGGGGGGGcGGuADDeWWWWWWWWWRGGG"
"GGGGGGGGGbGyGGuGAeWWWoWWPWRGGG"
"GGGGGGGGGBGYbGuGGADDDeWWWWRGGG"
"GGGGGGGGGcGGBbcGGcGGGADDDDSGGG"
"GGGGGGGGGGGGGBGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";

Example2DRenderer::Example2DRenderer() noexcept
	: Layer("Example2DRenderer")
	, m_CameraController(1280.0f / 720.0f)
	, m_Rotation(0.0f)
{ }

void Example2DRenderer::OnAttach() noexcept
{
	FarLight::FramebufferSpecification spec;
	spec.Width = 1280;
	spec.Height = 720;
	m_Framebuffer = FarLight::Framebuffer::Create(spec);

	m_Texture = FarLight::Texture2D::Create("assets/textures/Box.png");
	m_ShovelKnightTexture = FarLight::Texture2D::Create("assets/textures/ShovelKnightDigPromo.png");

	m_TileSheet = FarLight::Texture2D::Create("assets/textures/tilesheets/Kenney_roguelike.png");
	m_TextureMap['G'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 5, 30 });
	m_TextureMap['W'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 3, 29 });

	m_TextureMap['L'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 2, 29 });
	m_TextureMap['U'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 3, 30 });
	m_TextureMap['R'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 4, 29 });
	m_TextureMap['D'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 3, 28 });

	m_TextureMap['Q'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 2, 30 });
	m_TextureMap['E'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 4, 30 });
	m_TextureMap['A'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 2, 28 });
	m_TextureMap['S'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 4, 28 });

	m_TextureMap['q'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 0, 29 });
	m_TextureMap['e'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 1, 29 });
	m_TextureMap['a'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 0, 28 });
	m_TextureMap['s'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 1, 28 });

	m_TextureMap['Y'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 14, 19 });
	m_TextureMap['y'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 14, 20 });
	m_TextureMap['u'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 14, 21 });

	m_TextureMap['B'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 15, 19 });
	m_TextureMap['b'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 15, 20 });
	m_TextureMap['c'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 15, 21 });

	m_TextureMap['i'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 54, 7 });
	m_TextureMap['o'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 55, 7 });
	m_TextureMap['p'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 56, 7 });
	m_TextureMap['I'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 54, 6 });
	m_TextureMap['O'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 55, 6 });
	m_TextureMap['P'] = FarLight::SubTexture::Create(m_TileSheet, { 16, 16 }, { 56, 6 });
}

void Example2DRenderer::OnDetach() noexcept
{

}

void Example2DRenderer::OnUpdate(const FarLight::Timestep& timestamp) noexcept
{
	m_CameraController.OnUpdate(timestamp);
	
	m_Rotation += static_cast<float>(timestamp);

	m_Framebuffer->Bind();
	FarLight::RenderCommand::SetClearColor({ 0.5f, 0.5f, 0.5f, 1.0f });
	FarLight::RenderCommand::Clear();

	FarLight::Renderer2D::BeginScene(m_CameraController.GetCamera());

	for (int y = 0; y < 30; ++y)
	{
		for (int x = 0; x < 30; ++x)
		{
			if (m_TextureMap.find(s_Map[x + y * 30]) != m_TextureMap.end())
			{
				if (s_Map[x + y * 30] != 'G' && s_Map[x + y * 30] != 'W')
				{
					switch (s_Map[x + y * 30])
					{
						case 'i':
						case 'o':
						case 'p':
						case 'I':
						case 'O':
						case 'P':
						{
							FarLight::Renderer2D::DrawQuad({ x - 15, 15 - y, -0.1f }, { 1.0f, 1.0f }, m_TextureMap[s_Map['W']]);
							break;
						}
						default:
						{
							FarLight::Renderer2D::DrawQuad({ x - 15, 15 - y, -0.1f }, { 1.0f, 1.0f }, m_TextureMap[s_Map['G']]);
							break;
						}
					}
				}
				FarLight::Renderer2D::DrawQuad({ x - 15, 15 - y }, { 1.0f, 1.0f }, m_TextureMap[s_Map[x + y * 30]]);
			}
		}
	}

	FarLight::Renderer2D::EndScene();
	m_Framebuffer->Unbind();

	m_Controller = FarLight::Renderer2D::GetRender2DBatchController();
}

void Example2DRenderer::OnUserInterfaceRender() noexcept
{
	static bool p_open = true;
	static bool opt_fullscreen_persistant = true;
	bool opt_fullscreen = opt_fullscreen_persistant;
	static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

	// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
	// because it would be confusing to have two docking targets within each others.
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
	if (opt_fullscreen)
	{
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->GetWorkPos());
		ImGui::SetNextWindowSize(viewport->GetWorkSize());
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
	}

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
	ImGui::Begin("DockSpace", &p_open, window_flags);
	ImGui::PopStyleVar();

	if (opt_fullscreen) ImGui::PopStyleVar(2);

	// DockSpace
	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
	{
		ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
		ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
	}

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit", "E")) FarLight::Application::GetInstance().Close();
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	ImGui::End();

	ImGui::Begin("RenderScreen");
	unsigned renderTextureID = m_Framebuffer->GetColorAttachmentID();
	ImGui::Image((void *)renderTextureID, { 800, 600 });
	ImGui::End();

	ImGui::Begin("Batching Statistics");
	for (unsigned i = 0; i < m_Controller.GetBatches().size(); ++i)
	{
		ImGui::Text("========== Statistic for batch #%d: ==========", i+1);
		ImGui::Text("   Maximum Vertex Count: %d", m_Controller.GetBatches()[i].GetStatistic().MaxVertexNumber);
		ImGui::Text("   Maximum Index Count: %d", m_Controller.GetBatches()[i].GetStatistic().MaxIndexNumber);
		ImGui::Text("   Maximum Texture Slots: %d", m_Controller.GetBatches()[i].GetStatistic().MaxTextureSlots);
		ImGui::Text("   Used Shader ID: %d", m_Controller.GetBatches()[i].GetStatistic().UsedShader->GetID());
		ImGui::Text("   Used Default Texture ID: %d", m_Controller.GetBatches()[i].GetStatistic().UsedTextures[0]->GetID());
		ImGui::Text("   Used Layout Size, Count and Stride: %d / %d / %d", m_Controller.GetBatches()[i].GetStatistic().UsedLayout.GetElements().size(), m_Controller.GetBatches()[i].GetStatistic().UsedLayout.GetCount(), m_Controller.GetBatches()[i].GetStatistic().UsedLayout.GetStride());
		ImGui::Text("   Render calls: %d", m_Controller.GetBatches()[i].GetStatistic().GetRenderStatistic().size());
		for (unsigned j = 0; j < m_Controller.GetBatches()[i].GetStatistic().GetRenderStatistic().size(); ++j)
		{
			ImGui::Text("   ===== Statistic for render call #%d: =====", j + 1);
			ImGui::Text("      Used Vertex Count: %d", m_Controller.GetBatches()[i].GetStatistic().GetRenderStatistic()[j].UsedVertexNumber);
			ImGui::Text("      Used Index Count: %d", m_Controller.GetBatches()[i].GetStatistic().GetRenderStatistic()[j].UsedIndexNumber);
			ImGui::Text("      Used Texture Slots: %d", m_Controller.GetBatches()[i].GetStatistic().GetRenderStatistic()[j].UsedTextureSlots);
			ImGui::Text("   =========================================");
		}
		ImGui::Text("============================================");
	}
	ImGui::End();
}

void Example2DRenderer::OnEvent(FarLight::Event& event) noexcept
{
	m_CameraController.OnEvent(event);
}