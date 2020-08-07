#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"
#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
#include "FarLight/RenderSystem/Shader/Shader.h"
#include "FarLight/RenderSystem/Camera/OrthographicCamera.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"

#include "FarLight/RenderSystem/Batching/Batch.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class Renderer2D final
	{
	public:
		Renderer2D() = delete;
		Renderer2D(const Renderer2D&) = delete;
		Renderer2D(Renderer2D&&) = delete;
		Renderer2D& operator=(const Renderer2D&) = delete;
		Renderer2D& operator=(Renderer2D&&) = delete;

		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		// Quad draw calls
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color);

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f));

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f));

		static void SetViewport(unsigned width, unsigned height) { RenderCommand::SetViewport(0, 0, width, height); }
		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:

		struct QuadVertexData
		{
			glm::vec4 PosLowerRight;
			glm::vec4 PosUpperRight;
			glm::vec4 PosUpperLeft;
			glm::vec4 PosLowerLeft;
			unsigned Indices[6];
		};

		static Scope<Batch> s_Batch;
		static Scope<QuadVertexData> s_QuadData;
	};
}