// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Renderer2D.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

namespace FarLight
{
	BatchController& Renderer2D::GetBatchController() noexcept
	{
		static BatchController s_BatchController;
		return s_BatchController;
	}


	BatchConfiguration& Renderer2D::GetDefaultBatchConfiguration() noexcept
	{
		static BatchConfiguration s_BatchConfiguration(BufferLayout({
					{ ShaderDataType::Float3, "a_Position" },
					{ ShaderDataType::Float4, "a_Color" },
					{ ShaderDataType::Float2, "a_TextureCoordinates" },
					{ ShaderDataType::Float,  "a_TextureId"},
					{ ShaderDataType::Float,  "a_TilingFactor"}
			}), 
			{ Texture2D::Create(1, 1) },
			Shader::Create("assets/shaders/DefaultSquare/DefaultSquareShader.vert", "assets/shaders/DefaultSquare/DefaultSquareShader.frag"));
		return s_BatchConfiguration;
	}

	void Renderer2D::Init() noexcept
	{
		FL_PROFILE_FUNCTION();

		RenderCommand::Init();
		FL_CORE_INFO("[Renderer2D] initialized.");
	}

	void Renderer2D::Shutdown() noexcept
	{
		FL_PROFILE_FUNCTION();

		FL_CORE_INFO("[Renderer2D] terminated.");
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera) noexcept
	{
		FL_PROFILE_FUNCTION();

		GetBatchController().SetViewProjection(camera.GetViewMatrix(), camera.GetProjectionMatrix());
	}

	void Renderer2D::EndScene() noexcept
	{
		FL_PROFILE_FUNCTION();

		Flush();
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color) noexcept
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, color);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color) noexcept
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, color);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, color, counterclockwiseRadians);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor) noexcept
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, tintColor, 0.0f, texture);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor) noexcept
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, tintColor, counterclockwiseRadians, texture);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, tintColor, 0.0f, texture, tilingFactor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, tintColor, counterclockwiseRadians, texture, tilingFactor);
	}

	void Renderer2D::RecalculateQuadData(const glm::vec3& position
		, const glm::vec2& size
		, const glm::vec4& color
		, float counterclockwiseRadians
		, const Ref<Texture2D>& texture
		, float tilingFactor
		, const Ref<Shader>& shader) noexcept
	{
		FL_PROFILE_FUNCTION();

		glm::mat4 transformation = glm::translate(glm::mat4(1.0f), position)
			* glm::rotate(glm::mat4(1.0f), counterclockwiseRadians, glm::vec3(0.0f, 0.0f, 1.0f))
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f));

		static constexpr glm::vec4 s_Positions[4] = {
			{  0.5f, -0.5f,  0.0f,  1.0f },  // LowerRight
			{  0.5f,  0.5f,  0.0f,  1.0f },  // UpperRight
			{ -0.5f,  0.5f,  0.0f,  1.0f },  // UpperLeft
			{ -0.5f, -0.5f,  0.0f,  1.0f }   // LowerLeft
		};

		static constexpr glm::vec2 s_TextureCoordinates[4] = {
			{ 1.0f, 0.0f },  // LowerRight
			{ 1.0f, 1.0f },  // UpperRight
			{ 0.0f, 1.0f },  // UpperLeft
			{ 0.0f, 0.0f }   // LowerLeft
		};

		std::vector<VertexData> vertices(4);
		for (unsigned i = 0; i < 4; ++i)
		{
			vertices[i].Position = glm::vec3(transformation * s_Positions[i]);
			vertices[i].Color = color;
			vertices[i].TextureCoordinates = s_TextureCoordinates[i];
			vertices[i].TilingFactor = tilingFactor;
		}

		static std::vector<unsigned> s_Indices = { 0, 1, 2, 2, 3, 0 };

		GetBatchController().AddData(GetDefaultBatchConfiguration(), vertices, s_Indices, texture);
	}

	void Renderer2D::Flush() noexcept
	{
		FL_PROFILE_FUNCTION();

		GetBatchController().RenderAll();
		GetBatchController().ClearAll();
	}
}