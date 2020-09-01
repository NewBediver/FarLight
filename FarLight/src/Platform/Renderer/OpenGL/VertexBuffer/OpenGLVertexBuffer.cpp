// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Platform/Renderer/OpenGL/VertexBuffer/OpenGLVertexBuffer.h"

namespace FarLight
{
    OpenGLVertexBuffer::OpenGLVertexBuffer(const void* vertices, unsigned size, const BufferLayout& layout) noexcept
        : m_RendererID(0)
        , m_Offset(size)
        , m_Layout(layout)
        , m_UsageType(GL_STATIC_DRAW)
    {
        FL_PROFILE_FUNCTION();

        glCreateBuffers(1, &m_RendererID);
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
        glBufferData(GL_ARRAY_BUFFER, m_Offset, vertices, m_UsageType);
    }

    OpenGLVertexBuffer::OpenGLVertexBuffer(unsigned size, const BufferLayout& layout) noexcept
        : m_RendererID(0)
        , m_Offset(0)
        , m_Layout(layout)
        , m_UsageType(GL_DYNAMIC_DRAW)
    {
        FL_PROFILE_FUNCTION();

        glCreateBuffers(1, &m_RendererID);
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, m_UsageType);
    }

    void OpenGLVertexBuffer::AddSubData(const void* vertices, unsigned size) noexcept
    {
        FL_PROFILE_FUNCTION();
        FL_CORE_ASSERT(m_UsageType == GL_DYNAMIC_DRAW, "Cannot add sub data to non-dynamic vertex array!");

        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
        glBufferSubData(GL_ARRAY_BUFFER, m_Offset, size, vertices);

        m_Offset += size;
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer() noexcept
    {
        FL_PROFILE_FUNCTION();

        glDeleteBuffers(1, &m_RendererID);
    }

    void OpenGLVertexBuffer::Bind() const noexcept
    {
        FL_PROFILE_FUNCTION();

        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    }

    void OpenGLVertexBuffer::Unbind() const noexcept
    {
        FL_PROFILE_FUNCTION();

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}
