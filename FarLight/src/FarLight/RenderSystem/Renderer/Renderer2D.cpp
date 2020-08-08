// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Renderer2D.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

namespace FarLight
{
	//Scope<Batch> Renderer2D::s_Batch = nullptr;

	Scope<BatchController> Renderer2D::s_BatchController = CreateScope<BatchController>();

	void Renderer2D::Init()
	{
		FL_PROFILE_FUNCTION();

		RenderCommand::Init();
		FL_CORE_INFO("[Renderer2D] initialized.");

		/*s_Batch = CreateScope<Batch>( BufferLayout({
				{ ShaderDataType::Float3, "a_Position" },
				{ ShaderDataType::Float4, "a_Color" },
				{ ShaderDataType::Float2, "a_TextureCoordinates" }
			})
			, Shader::Create("assets/shaders/DefaultSquare/DefaultSquareShader.vert", "assets/shaders/DefaultSquare/DefaultSquareShader.frag")
			, Texture2D::Create(1, 1));*/
	}

	void Renderer2D::Shutdown()
	{
		FL_PROFILE_FUNCTION();

		FL_CORE_INFO("[Renderer2D] terminated.");
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		FL_PROFILE_FUNCTION();

		s_BatchController->SetViewProjection(camera.GetViewMatrix(), camera.GetProjectionMatrix());
	}

	void Renderer2D::EndScene()
	{
		FL_PROFILE_FUNCTION();

		s_BatchController->RenderAll();
		s_BatchController->ClearAll();
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, color);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color)
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, color);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color)
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, color, counterclockwiseRadians);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, tintColor, 0.0f, texture);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, tintColor, counterclockwiseRadians, texture);
	}


	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, tintColor, 0.0f, texture, tilingFactor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
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
		, const Ref<Shader>& shader)
	{
		FL_PROFILE_FUNCTION();

		static constexpr glm::vec4 s_PosLowerRight = { 0.5f, -0.5f, 0.0f, 1.0f };
		static constexpr glm::vec4 s_PosUpperRight = { 0.5f, 0.5f, 0.0f, 1.0f };
		static constexpr glm::vec4 s_PosUpperLeft = { -0.5f, 0.5f, 0.0f, 1.0f };
		static constexpr glm::vec4 s_PosLowerLeft = { -0.5f, -0.5f, 0.0f, 1.0f };

		static constexpr unsigned s_Indices[6] = { 0, 1, 2, 2, 3, 0 };

		glm::mat4 transformation = glm::translate(glm::mat4(1.0f), position)
			* glm::rotate(glm::mat4(1.0f), counterclockwiseRadians, glm::vec3(0.0f, 0.0f, 1.0f))
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f));

		glm::vec4 posLowerRight = transformation * s_PosLowerRight;
		glm::vec4 posUpperRight = transformation * s_PosUpperRight;
		glm::vec4 posUpperLeft = transformation * s_PosUpperLeft;
		glm::vec4 posLowerLeft = transformation * s_PosLowerLeft;

		float squareVertices[4 * 10] =
		{
			// position                                           // color                               // textures
			posLowerRight.x, posLowerRight.y, posLowerRight.z,    color.r, color.g, color.b, color.a,    1.0f, 0.0f,    tilingFactor,
			posUpperRight.x, posUpperRight.y, posUpperRight.z,    color.r, color.g, color.b, color.a,    1.0f, 1.0f,    tilingFactor,
			posUpperLeft.x,  posUpperLeft.y,  posUpperLeft.z,     color.r, color.g, color.b, color.a,    0.0f, 1.0f,    tilingFactor,
			posLowerLeft.x,  posLowerLeft.y,  posLowerLeft.z,     color.r, color.g, color.b, color.a,    0.0f, 0.0f,    tilingFactor
		};

		static Default2D s_DefaultData =
		{
			Shader::Create("assets/shaders/DefaultSquare/DefaultSquareShader.vert", "assets/shaders/DefaultSquare/DefaultSquareShader.frag"),
			Texture2D::Create(1, 1),
			BufferLayout({
					{ ShaderDataType::Float3, "a_Position" },
					{ ShaderDataType::Float4, "a_Color" },
					{ ShaderDataType::Float2, "a_TextureCoordinates" },
					{ ShaderDataType::Float, "a_TilingFactor"}
				}),
			0
		};

		s_BatchController->AddData(
			BatchConfiguration(s_DefaultData.DefaultLayout, s_DefaultData.DefaultShader, texture == nullptr ? s_DefaultData.DefaultTexture : texture, s_DefaultData.DefaultTextureSlot)
			, 4
			, squareVertices
			, 6
			, s_Indices);
	}

}