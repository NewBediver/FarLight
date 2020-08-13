#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"
#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
#include "FarLight/RenderSystem/Shader/Shader.h"
#include "FarLight/RenderSystem/Camera/OrthographicCamera.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"

#include "FarLight/RenderSystem/Batching/Batch.h"
#include "FarLight/RenderSystem/Batching/BatchController.h"

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

		static void Init() noexcept;
		static void Shutdown() noexcept;

		static void BeginScene(const OrthographicCamera& camera) noexcept;
		static void EndScene() noexcept;

		// Quad draw calls
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color) noexcept;
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color) noexcept;
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color) noexcept;
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color) noexcept;

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f)) noexcept;
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f)) noexcept;
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f)) noexcept;
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f)) noexcept;

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f)) noexcept;
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f)) noexcept;
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f)) noexcept;
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f)) noexcept;

		static void SetViewport(unsigned width, unsigned height) noexcept { RenderCommand::SetViewport(0, 0, width, height); }
		
		static RendererAPI::API GetAPI() noexcept { return RendererAPI::GetAPI(); }
		static const BatchController& GetRender2DBatchController() noexcept { return GetBatchController(); }

	private:
		static BatchController& GetBatchController() noexcept;

		static const BufferLayout& GetDefaultLayout() noexcept;
		static const Ref<Shader>& GetDefaultShader() noexcept;
		static const Ref<Texture2D>& GetDefaultTexture() noexcept;

		static void RecalculateQuadData(const glm::vec3& position = glm::vec3(0.0f)
			, const glm::vec2& size = glm::vec2(1.0f)
			, const glm::vec4& color = glm::vec4(1.0f)
			, float counterclockwiseRadians = 0.0f
			, const Ref<Texture2D>& texture = nullptr
			, float tilingFactor = 1.0f
			, const Ref<Shader>& shader = nullptr) noexcept;
	};
}