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

	const BufferLayout& Renderer2D::GetDefaultLayout() noexcept
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

	const Ref<FarLight::Shader>& Renderer2D::GetDefaultShader() noexcept
	{
		static Ref<Shader> s_DefaultShader = Shader::Create("assets/shaders/DefaultSquare/DefaultSquareShader.vert", "assets/shaders/DefaultSquare/DefaultSquareShader.frag");
		return s_DefaultShader;
	}

	const Ref<FarLight::Texture2D>& Renderer2D::GetDefaultTexture() noexcept
	{
		static Ref<Texture2D> s_DefaultTexture = Texture2D::Create(1, 1);
		return s_DefaultTexture;
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

		GetBatchController().ClearAll();
		GetBatchController().ResetRenderCalls();
		GetBatchController().SetViewProjection(camera.GetViewMatrix(), camera.GetProjectionMatrix());
	}

	void Renderer2D::EndScene() noexcept
	{
		FL_PROFILE_FUNCTION();

		GetBatchController().RenderAll();
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

		float halfXSize = size.x / 2;
		float halfYSize = size.y / 2;

		glm::vec4 positions[4];
		if (counterclockwiseRadians == 0.0f)
		{
			positions[0] = { position.x - halfXSize, position.y - halfYSize, position.z, 1.0f };  // LowerLeft
			positions[1] = { position.x + halfXSize, position.y - halfYSize, position.z, 1.0f };  // LowerRight
			positions[2] = { position.x + halfXSize, position.y + halfYSize, position.z, 1.0f };  // UpperRight
			positions[3] = { position.x - halfXSize, position.y + halfYSize, position.z, 1.0f };  // UpperLeft
		}
		else
		{
			positions[0] = { -halfXSize, -halfYSize, position.z, 1.0f };  // LowerLeft
			positions[1] = {  halfXSize, -halfYSize, position.z, 1.0f };  // LowerRight
			positions[2] = {  halfXSize,  halfYSize, position.z, 1.0f };  // UpperRight
			positions[3] = { -halfXSize,  halfYSize, position.z, 1.0f };  // UpperLeft
			for (int i = 0; i < 4; ++i)
			{
				positions[i] = glm::rotate(glm::mat4(1.0f), counterclockwiseRadians, glm::vec3(0.0f, 0.0f, 1.0f)) * positions[i];
				positions[i] = glm::vec4(positions[i].x + position.x, positions[i].y + position.y, positions[i].z, positions[i].w);
			}
		}

		static constexpr glm::vec2 s_TextureCoordinates[4] =
		{
			{ 0.0f, 0.0f },  // LowerLeft
			{ 1.0f, 0.0f },  // LowerRight
			{ 1.0f, 1.0f },  // UpperRight
			{ 0.0f, 1.0f }   // UpperLeft
		};

		std::vector<float> data(4ull * static_cast<unsigned long long>(GetDefaultLayout().GetCount()));
		for (unsigned i = 0; i < 4; ++i)
		{
			unsigned offset = i * GetDefaultLayout().GetCount();
			data[offset] = positions[i].x;
			data[offset +  1ull] = positions[i].y;
			data[offset +  2ull] = positions[i].z;
			data[offset +  3ull] = color.r;
			data[offset +  4ull] = color.g;
			data[offset +  5ull] = color.b;
			data[offset +  6ull] = color.a;
			data[offset +  7ull] = s_TextureCoordinates[i].x;
			data[offset +  8ull] = s_TextureCoordinates[i].y;
			data[offset +  9ull] = 0;
			data[offset + 10ull] = tilingFactor;
		}

		static std::vector<unsigned> s_Indices = { 0, 1, 2, 2, 3, 0 };
		if (texture == nullptr)
		{
			GetBatchController().AddData(BatchStatistic(GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), 4, data, 6, s_Indices);
		}
		else
		{
			GetBatchController().AddData(BatchStatistic(GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), 4, data, 6, s_Indices, texture, 9);
		}
	}
}