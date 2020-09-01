// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/RenderSystem/Batching/BatchController.h"

namespace FarLight
{
    void BatchController::AddData(const BatchConfiguration& stat, unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices) noexcept
    {
        FL_PROFILE_FUNCTION();

        for (auto& elm : m_Batches)
        {
            if (stat == elm.GetConfiguration())
            {
                if (elm.HasFreeTextureSlots() && elm.HasFreeIndexSlots(indexNumber) && elm.HasFreeVertexSlots(vertexNumber))
                {
                    elm.AddData(vertexNumber, vertexData, indexNumber, indices);
                    return;
                }
            }
        }

        m_Batches.emplace_back(stat);
        m_Batches.back().AddData(vertexNumber, vertexData, indexNumber, indices);
    }

    void BatchController::AddData(const BatchConfiguration& stat, unsigned vertexNumber, const std::vector<float>& vertexData, unsigned indexNumber, const std::vector<unsigned>& indices, const Ref<Texture2D>& texture, unsigned textureIndexDataOffset) noexcept
    {
        FL_PROFILE_FUNCTION();

        for (auto& elm : m_Batches)
        {
            if (stat == elm.GetConfiguration())
            {
                if (elm.HasFreeTextureSlots(1) && elm.HasFreeIndexSlots(indexNumber) && elm.HasFreeVertexSlots(vertexNumber))
                {
                    elm.AddData(vertexNumber, vertexData, indexNumber, indices, texture, textureIndexDataOffset);
                    return;
                }
            }
        }

        m_Batches.emplace_back(stat);
        m_Batches.back().AddData(vertexNumber, vertexData, indexNumber, indices, texture, textureIndexDataOffset);
    }

    void BatchController::RenderAll(BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        for (auto& batch : m_Batches)
        {
            if (type == batch.GetConfiguration().Type) batch.Render();
        }
    }

    void BatchController::ClearAll(BatchType type) noexcept
    {
        FL_PROFILE_FUNCTION();

        for (auto& batch : m_Batches)
        {
            if (type == batch.GetConfiguration().Type) batch.Clear();
        }
    }

    void BatchController::SetViewProjection(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) noexcept
    {
        FL_PROFILE_FUNCTION();

        for (auto& batch : m_Batches)
            batch.SetViewProjection(viewMatrix, projectionMatrix);
    }
}
