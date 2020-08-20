#pragma once

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"
#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
#include "FarLight/RenderSystem/Shader/Shader.h"
#include "FarLight/RenderSystem/Camera/OrthographicCamera.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"
#include "FarLight/RenderSystem/textureAtlas/AtlasTile.h"

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
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color, BatchType type = BatchType::Dynamic) noexcept;
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color, BatchType type = BatchType::Dynamic) noexcept;
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color, BatchType type = BatchType::Dynamic) noexcept;
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color, BatchType type = BatchType::Dynamic) noexcept;

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;

		static void SetViewport(unsigned width, unsigned height) noexcept { RenderCommand::SetViewport(0, 0, width, height); }
		
		static RendererAPI::API GetAPI() noexcept { return RendererAPI::GetAPI(); }
		static const Scope<BatchController>& GetRender2DBatchController() noexcept { return s_BatchController; }

	private:
		static Scope<BatchController> s_BatchController;

		static const BufferLayout& Renderer2D::GetDefaultLayout() noexcept
		{
			static BufferLayout s_DefaultLayout({
						{ ShaderDataType::Float3, "a_Position" },
						{ ShaderDataType::Float4, "a_Color" },
						{ ShaderDataType::Float2, "a_TextureCoordinates" },
						{ ShaderDataType::Float,  "a_TextureId"},
						{ ShaderDataType::Float,  "a_TilingFactor"}
				});
			return s_DefaultLayout;
		}

		static const Ref<FarLight::Shader>& Renderer2D::GetDefaultShader() noexcept
		{
			static Ref<Shader> s_DefaultShader = Shader::Create("assets/shaders/DefaultSquare/DefaultSquareShader.vert", "assets/shaders/DefaultSquare/DefaultSquareShader.frag");
			return s_DefaultShader;
		}

		static const Ref<FarLight::Texture2D>& Renderer2D::GetDefaultTexture() noexcept
		{
			static Ref<Texture2D> s_DefaultTexture = Texture2D::Create(1, 1);
			return s_DefaultTexture;
		}

		static std::array<glm::vec4, 4> RecalculateSquareVertexPosition(const glm::vec3& position, const glm::vec2& size) noexcept;
		static std::array<glm::vec4, 4> RecalculateSquareVertexPosition(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians) noexcept;

		static std::vector<float> RecalculateSquareVertexData(const std::array<glm::vec4, 4>& position, const glm::vec4& color, const std::array<glm::vec2, 4>& textureCoordinates, float tilingFactor = 1.0f) noexcept;
		static std::vector<unsigned> RecalculateSquareIndexData() noexcept;

		static void RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color, BatchType type = BatchType::Dynamic) noexcept;
		static void RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color, BatchType type = BatchType::Dynamic) noexcept;

		static void RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4 tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4 tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;

		static void RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, float tilingFactor = 1.0f, const glm::vec4 tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
		static void RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, float tilingFactor = 1.0f, const glm::vec4 tintColor = glm::vec4(1.0f), BatchType type = BatchType::Dynamic) noexcept;
	};
}