#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"
#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
#include "FarLight/RenderSystem/Shader/Shader.h"
#include "FarLight/RenderSystem/Camera/OrthographicCamera.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		// Quad draw calls
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture);
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& color);

		static void SetViewport(unsigned int width, unsigned int height) { RenderCommand::SetViewport(0, 0, width, height); }
		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		Renderer2D() = delete;
		Renderer2D(const Renderer2D&) = delete;
		Renderer2D(Renderer2D&&) = delete;
		Renderer2D& operator=(const Renderer2D&) = delete;
		Renderer2D& operator=(Renderer2D&&) = delete;

		struct Renderer2DStorage
		{
			Ref<VertexArray> m_VertexArray;
			Ref<Shader> m_Shader;
			Ref<Texture2D> m_Texture;
		};

		static Scope<Renderer2DStorage> s_Storage;
	};
}