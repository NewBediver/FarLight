// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Renderer2D.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

namespace FarLight
{
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

		RecalculateQuadData(position, size, counterclockwiseRadians, color);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor) noexcept
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, texture, 1.0f, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor) noexcept
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, counterclockwiseRadians, texture, 1.0f,  tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor) noexcept
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, atlasTile, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, atlasTile, 1.0f, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor) noexcept
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, atlasTile, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, counterclockwiseRadians, atlasTile, 1.0f, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, counterclockwiseRadians, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, atlasTile, tilingFactor, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, atlasTile, tilingFactor, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, atlasTile, tilingFactor, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		RecalculateQuadData(position, size, counterclockwiseRadians, atlasTile, tilingFactor, tintColor);
	}

	std::array<glm::vec4, 4> Renderer2D::RecalculateSquareVertexPosition(const glm::vec3& position, const glm::vec2& size) noexcept
	{
		float halfXSize = size.x / 2;
		float halfYSize = size.y / 2;

		return std::array<glm::vec4, 4>
		{
			glm::vec4(position.x - halfXSize, position.y - halfYSize, position.z, 1.0f),  // LowerLeft
			glm::vec4(position.x + halfXSize, position.y - halfYSize, position.z, 1.0f),  // LowerRight
			glm::vec4(position.x + halfXSize, position.y + halfYSize, position.z, 1.0f),  // UpperRight
			glm::vec4(position.x - halfXSize, position.y + halfYSize, position.z, 1.0f)   // UpperLeft
		};
	}
	std::array<glm::vec4, 4> Renderer2D::RecalculateSquareVertexPosition(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians) noexcept
	{
		float halfXSize = size.x / 2;
		float halfYSize = size.y / 2;

		glm::mat4 rotationMat = glm::rotate(glm::mat4(1.0f), counterclockwiseRadians, glm::vec3(0.0f, 0.0f, 1.0f));

		std::array<glm::vec4, 4> tmp = 
		{
			rotationMat * glm::vec4(-halfXSize, -halfYSize, position.z, 1.0f),  // LowerLeft
			rotationMat * glm::vec4( halfXSize, -halfYSize, position.z, 1.0f),  // LowerRight
			rotationMat * glm::vec4( halfXSize,  halfYSize, position.z, 1.0f),  // UpperRight
			rotationMat * glm::vec4(-halfXSize,  halfYSize, position.z, 1.0f)   // UpperLeft
		};

		for (int i = 0; i < 4; ++i)
		{
			tmp[i].x += position.x;
			tmp[i].y += position.y;
		}
		return tmp;
	}

	std::vector<float> Renderer2D::RecalculateSquareVertexData(const std::array<glm::vec4, 4>& position, const glm::vec4& color, const std::array<glm::vec2, 4>& textureCoordinates, float tilingFactor) noexcept
	{
		std::vector<float> data(4ull * static_cast<unsigned long long>(GetDefaultLayout().GetCount()));
		for (unsigned i = 0; i < 4; ++i)
		{
			unsigned offset = i * GetDefaultLayout().GetCount();
			data[offset] = position[i].x;
			data[offset + 1ull] = position[i].y;
			data[offset + 2ull] = position[i].z;
			data[offset + 3ull] = color.r;
			data[offset + 4ull] = color.g;
			data[offset + 5ull] = color.b;
			data[offset + 6ull] = color.a;
			data[offset + 7ull] = textureCoordinates[i].x;
			data[offset + 8ull] = textureCoordinates[i].y;
			data[offset + 9ull] = 0.0f;
			data[offset + 10ull] = tilingFactor;
		}
		return data;
	}
	std::vector<unsigned> Renderer2D::RecalculateSquareIndexData() noexcept
	{
		return { 0, 1, 2, 2, 3, 0 };
	}

	void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color) noexcept
	{
		FL_PROFILE_FUNCTION();

		std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size);
		std::array<glm::vec2, 4> textureCoords = GetDefaultTexture()->GetCoordinates();

		std::vector<float> vertexData = RecalculateSquareVertexData(positions, color, textureCoords);
		std::vector<unsigned> indexData = RecalculateSquareIndexData();

		GetBatchController().AddData(BatchStatistic(GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), 4, vertexData, 6, indexData);
	}
	void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color) noexcept
	{
		FL_PROFILE_FUNCTION();

		std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size, counterclockwiseRadians);
		std::array<glm::vec2, 4> textureCoords = GetDefaultTexture()->GetCoordinates();

		std::vector<float> vertexData = RecalculateSquareVertexData(positions, color, textureCoords);
		std::vector<unsigned> indexData = RecalculateSquareIndexData();

		GetBatchController().AddData(BatchStatistic(GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), 4, vertexData, 6, indexData);
	}

	void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4 tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size);
		std::array<glm::vec2, 4> textureCoords = texture->GetCoordinates();

		std::vector<float> vertexData = RecalculateSquareVertexData(positions, tintColor, textureCoords, tilingFactor);
		std::vector<unsigned> indexData = RecalculateSquareIndexData();

		GetBatchController().AddData(BatchStatistic(GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), 4, vertexData, 6, indexData, texture, 9);
	}
	void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4 tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size, counterclockwiseRadians);
		std::array<glm::vec2, 4> textureCoords = texture->GetCoordinates();

		std::vector<float> vertexData = RecalculateSquareVertexData(positions, tintColor, textureCoords, tilingFactor);
		std::vector<unsigned> indexData = RecalculateSquareIndexData();

		GetBatchController().AddData(BatchStatistic(GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), 4, vertexData, 6, indexData, texture, 9);
	}

	void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4 tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size);
		std::array<glm::vec2, 4> textureCoords = atlasTile->GetCoordinates();

		std::vector<float> vertexData = RecalculateSquareVertexData(positions, tintColor, textureCoords, tilingFactor);
		std::vector<unsigned> indexData = RecalculateSquareIndexData();

		GetBatchController().AddData(BatchStatistic(GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), 4, vertexData, 6, indexData, atlasTile->GetTexture(), 9);
	}
	void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4 tintColor) noexcept
	{
		FL_PROFILE_FUNCTION();

		std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size, counterclockwiseRadians);
		std::array<glm::vec2, 4> textureCoords = atlasTile->GetCoordinates();

		std::vector<float> vertexData = RecalculateSquareVertexData(positions, tintColor, textureCoords, tilingFactor);
		std::vector<unsigned> indexData = RecalculateSquareIndexData();

		GetBatchController().AddData(BatchStatistic(GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), 4, vertexData, 6, indexData, atlasTile->GetTexture(), 9);
	}
}