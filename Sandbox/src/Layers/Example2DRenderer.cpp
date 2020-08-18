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

	m_Texture = FarLight::Texture2D::Create("assets/textures/Box.png");
	m_ShovelKnightTexture = FarLight::Texture2D::Create("assets/textures/ShovelKnightDigPromo.png");

	m_AtlasMap = FarLight::AtlasMap::Create(FarLight::Texture2D::Create("assets/textures/tilesheets/Kenney_roguelike.png"), { 16, 16 });

	m_AtlasCoords['G'] = { 5, 30 };
	m_AtlasCoords['W'] = { 3, 29 };

	m_AtlasCoords['L'] = { 2, 29 };
	m_AtlasCoords['U'] = { 3, 30 };
	m_AtlasCoords['R'] = { 4, 29 };
	m_AtlasCoords['D'] = { 3, 28 };

	m_AtlasCoords['Q'] = { 2, 30 };
	m_AtlasCoords['E'] = { 4, 30 };
	m_AtlasCoords['A'] = { 2, 28 };
	m_AtlasCoords['S'] = { 4, 28 };

	m_AtlasCoords['q'] = { 0, 29 };
	m_AtlasCoords['e'] = { 1, 29 };
	m_AtlasCoords['a'] = { 0, 28 };
	m_AtlasCoords['s'] = { 1, 28 };

	m_AtlasCoords['Y'] = { 14, 19 };
	m_AtlasCoords['y'] = { 14, 20 };
	m_AtlasCoords['u'] = { 14, 21 };

	m_AtlasCoords['B'] = { 15, 19 };
	m_AtlasCoords['b'] = { 15, 20 };
	m_AtlasCoords['c'] = { 15, 21 };

	m_AtlasCoords['i'] = { 54, 7 };
	m_AtlasCoords['o'] = { 55, 7 };
	m_AtlasCoords['p'] = { 56, 7 };
	m_AtlasCoords['I'] = { 54, 6 };
	m_AtlasCoords['O'] = { 55, 6 };
	m_AtlasCoords['P'] = { 56, 6 };
}

void Example2DRenderer::OnDetach() noexcept
{

}

void Example2DRenderer::OnUpdate(const FarLight::Timestep& timestamp) noexcept
{
	m_CameraController.OnUpdate(timestamp);
	
	m_Rotation += static_cast<float>(timestamp);

	FarLight::RenderCommand::SetClearColor({ 0.5f, 0.5f, 0.5f, 1.0f });
	FarLight::RenderCommand::Clear();

	FarLight::Renderer2D::BeginScene(m_CameraController.GetCamera());

	for (int y = 0; y < 30; ++y)
	{
		for (int x = 0; x < 30; ++x)
		{
			if (m_AtlasCoords.find(s_Map[x + y * 30]) != m_AtlasCoords.end())
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
						FarLight::Renderer2D::DrawQuad({ x - 15, 15 - y, -0.1f }, { 1.0f, 1.0f }, m_AtlasMap->GetAtlasTile(m_AtlasCoords['W']));
						break;
					}
					default:
					{
						FarLight::Renderer2D::DrawQuad({ x - 15, 15 - y, -0.1f }, { 1.0f, 1.0f }, m_AtlasMap->GetAtlasTile(m_AtlasCoords['G']));
						break;
					}
					}
				}
				FarLight::Renderer2D::DrawQuad({ x - 15, 15 - y }, { 1.0f, 1.0f }, m_AtlasMap->GetAtlasTile(m_AtlasCoords[s_Map[x + y * 30]]));
			}
		}
	}

	FarLight::Renderer2D::EndScene();
}

void Example2DRenderer::OnUserInterfaceRender() noexcept
{

}

void Example2DRenderer::OnEvent(FarLight::Event& event) noexcept
{
	m_CameraController.OnEvent(event);
}