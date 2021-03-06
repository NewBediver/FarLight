// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"

#include <glm/gtc/matrix_transform.hpp>

#include <glad/glad.h>

namespace FarLight
{
    Scope<BatchController> Renderer2D::s_BatchController = nullptr;

    void Renderer2D::Init() noexcept
    {
        FL_PROFILE_FUNCTION();

        RenderCommand::Init();
        s_BatchController = CreateScope<BatchController>();
    }

    void Renderer2D::Shutdown() noexcept
    {
        FL_PROFILE_FUNCTION();

        s_BatchController.reset();
    }

    void Renderer2D::BeginScene(Ref<Camera> camera) noexcept
    {
        FL_PROFILE_FUNCTION();

        BeginSceneInit(camera->GetViewMatrix(), camera->GetProjectionMatrix());
    }

    void Renderer2D::BeginSceneInit(const glm::mat4& view, const glm::mat4& projection) noexcept
    {
        FL_PROFILE_FUNCTION();

        s_BatchController->ClearAll(BatchType::Dynamic);
        s_BatchController->SetViewProjection(view, projection);
    }

    void Renderer2D::EndScene() noexcept
    {
        FL_PROFILE_FUNCTION();

        s_BatchController->RenderAll(BatchType::Static);
        s_BatchController->RenderAll(BatchType::Dynamic);
    }

    void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color, BatchType type) noexcept
    {
        DrawQuad({ position.x, position.y, 0.0f }, size, color, type);
    }

    void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        RecalculateQuadData(position, size, color, type);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color, BatchType type) noexcept
    {
        DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, color, type);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        RecalculateQuadData(position, size, counterclockwiseRadians, color, type);
    }

    void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor, BatchType type) noexcept
    {
        DrawQuad({ position.x, position.y, 0.0f }, size, texture, tintColor, type);
    }

    void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        RecalculateQuadData(position, size, texture, 1.0f, tintColor, type);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor, BatchType type) noexcept
    {
        DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tintColor, type);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        RecalculateQuadData(position, size, counterclockwiseRadians, texture, 1.0f, tintColor, type);
    }

    void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor, BatchType type) noexcept
    {
        DrawQuad({ position.x, position.y, 0.0f }, size, atlasTile, tintColor, type);
    }

    void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        RecalculateQuadData(position, size, atlasTile, 1.0f, tintColor, type);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor, BatchType type) noexcept
    {
        DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, atlasTile, tintColor, type);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, const glm::vec4& tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        RecalculateQuadData(position, size, counterclockwiseRadians, atlasTile, 1.0f, tintColor, type);
    }

    void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor, BatchType type) noexcept
    {
        DrawQuad({ position.x, position.y, 0.0f }, size, texture, tilingFactor, tintColor, type);
    }

    void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        RecalculateQuadData(position, size, texture, tilingFactor, tintColor, type);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor, BatchType type) noexcept
    {
        DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tilingFactor, tintColor, type);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        RecalculateQuadData(position, size, counterclockwiseRadians, texture, tilingFactor, tintColor, type);
    }

    void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor, BatchType type) noexcept
    {
        DrawQuad({ position.x, position.y, 0.0f }, size, atlasTile, tilingFactor, tintColor, type);
    }

    void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        RecalculateQuadData(position, size, atlasTile, tilingFactor, tintColor, type);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor, BatchType type) noexcept
    {
        DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, atlasTile, tilingFactor, tintColor, type);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4& tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        RecalculateQuadData(position, size, counterclockwiseRadians, atlasTile, tilingFactor, tintColor, type);
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
            rotationMat * glm::vec4(halfXSize, -halfYSize, position.z, 1.0f),  // LowerRight
            rotationMat * glm::vec4(halfXSize,  halfYSize, position.z, 1.0f),  // UpperRight
            rotationMat * glm::vec4(-halfXSize,  halfYSize, position.z, 1.0f)   // UpperLeft
        };

        for (int i = 0; i < tmp.size(); ++i)
        {
            tmp[i].x += position.x;
            tmp[i].y += position.y;
        }
        return tmp;
    }

    std::vector<float> Renderer2D::RecalculateSquareVertexData(const std::array<glm::vec4, 4>& position, const glm::vec4& color, const std::array<glm::vec2, 4>& textureCoordinates, float tilingFactor) noexcept
    {
        std::vector<float> data(position.size() * static_cast<unsigned long long>(GetDefaultLayout().GetCount()));
        for (unsigned i = 0; i < position.size(); ++i)
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

    void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size);
        std::array<glm::vec2, 4> textureCoords = GetDefaultTexture()->GetCoordinates();

        std::vector<float> vertexData = RecalculateSquareVertexData(positions, color, textureCoords);
        std::vector<unsigned> indexData = RecalculateSquareIndexData();

        s_BatchController->AddData(BatchConfiguration(type, GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), positions.size(), vertexData, indexData.size(), indexData);
    }
    void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size, counterclockwiseRadians);
        std::array<glm::vec2, 4> textureCoords = GetDefaultTexture()->GetCoordinates();

        std::vector<float> vertexData = RecalculateSquareVertexData(positions, color, textureCoords);
        std::vector<unsigned> indexData = RecalculateSquareIndexData();

        s_BatchController->AddData(BatchConfiguration(type, GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), positions.size(), vertexData, indexData.size(), indexData);
    }

    void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4 tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size);
        std::array<glm::vec2, 4> textureCoords = texture->GetCoordinates();

        std::vector<float> vertexData = RecalculateSquareVertexData(positions, tintColor, textureCoords, tilingFactor);
        std::vector<unsigned> indexData = RecalculateSquareIndexData();

        s_BatchController->AddData(BatchConfiguration(type, GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), positions.size(), vertexData, indexData.size(), indexData, texture, 9);
    }
    void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4 tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size, counterclockwiseRadians);
        std::array<glm::vec2, 4> textureCoords = texture->GetCoordinates();

        std::vector<float> vertexData = RecalculateSquareVertexData(positions, tintColor, textureCoords, tilingFactor);
        std::vector<unsigned> indexData = RecalculateSquareIndexData();

        s_BatchController->AddData(BatchConfiguration(type, GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), positions.size(), vertexData, indexData.size(), indexData, texture, 9);
    }

    void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4 tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size);
        std::array<glm::vec2, 4> textureCoords = atlasTile->GetCoordinates();

        std::vector<float> vertexData = RecalculateSquareVertexData(positions, tintColor, textureCoords, tilingFactor);
        std::vector<unsigned> indexData = RecalculateSquareIndexData();

        s_BatchController->AddData(BatchConfiguration(type, GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), positions.size(), vertexData, indexData.size(), indexData, atlasTile->GetTexture(), 9);
    }
    void Renderer2D::RecalculateQuadData(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<AtlasTile>& atlasTile, float tilingFactor, const glm::vec4 tintColor, BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        std::array<glm::vec4, 4> positions = RecalculateSquareVertexPosition(position, size, counterclockwiseRadians);
        std::array<glm::vec2, 4> textureCoords = atlasTile->GetCoordinates();

        std::vector<float> vertexData = RecalculateSquareVertexData(positions, tintColor, textureCoords, tilingFactor);
        std::vector<unsigned> indexData = RecalculateSquareIndexData();

        s_BatchController->AddData(BatchConfiguration(type, GetDefaultLayout(), GetDefaultTexture(), GetDefaultShader()), positions.size(), vertexData, indexData.size(), indexData, atlasTile->GetTexture(), 9);
    }
}
