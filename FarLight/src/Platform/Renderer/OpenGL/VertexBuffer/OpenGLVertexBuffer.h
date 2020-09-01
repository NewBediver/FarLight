#pragma once

#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"

#include <glad/glad.h>

namespace FarLight
{
    class OpenGLVertexBuffer
        : public VertexBuffer
    {
    public:
        explicit OpenGLVertexBuffer(const void* vertices, unsigned size, const BufferLayout& layout) noexcept;
        explicit OpenGLVertexBuffer(unsigned size, const BufferLayout& layout) noexcept;

        virtual ~OpenGLVertexBuffer() noexcept;

        virtual void Bind() const noexcept override;
        virtual void Unbind() const noexcept override;

        virtual unsigned GetID() const noexcept override { return m_RendererID; }

        virtual const BufferLayout& GetLayout() const noexcept override { return m_Layout; }
        virtual void SetLayout(const BufferLayout& layout) noexcept override { m_Layout = layout; }

        virtual unsigned GetOffset() const noexcept override { return m_Offset; }
        virtual void SetOffset(unsigned offset) noexcept override { m_Offset = offset; }

        virtual unsigned GetUsageType() const noexcept override { return m_UsageType; }

        virtual void AddSubData(const void* vertices, unsigned size) noexcept override;

    private:
        unsigned m_RendererID;
        unsigned m_Offset;
        BufferLayout m_Layout;
        GLenum m_UsageType;
    };
}
