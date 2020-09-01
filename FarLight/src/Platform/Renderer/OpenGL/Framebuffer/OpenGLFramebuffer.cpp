// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Platform/Renderer/OpenGL/Framebuffer/OpenGLFramebuffer.h"

#include <glad/glad.h>

namespace FarLight
{
    OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferSpecification& spec) noexcept
        : m_RendererID(0)
        , m_ColorAttachment(0)
        , m_DepthStencilAttachment(0)
        , m_Specification(spec)
    {
        FL_CORE_ASSERT(spec.Width > 0, "Framebuffer width should be greater than 0!");
        FL_CORE_ASSERT(spec.Height > 0, "Framebuffer height should be greater than 0!");

        Invalidate();
    }

    OpenGLFramebuffer::~OpenGLFramebuffer() noexcept
    {
        DeleteOpenGLObjects();
    }

    void OpenGLFramebuffer::Bind() const noexcept
    {
        glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);
        glViewport(0, 0, m_Specification.Width, m_Specification.Height);
    }

    void OpenGLFramebuffer::Unbind() const noexcept
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void OpenGLFramebuffer::Resize(unsigned width, unsigned height) noexcept
    {
        if (width > 0 && height > 0 && (m_Specification.Width != width || m_Specification.Height != height))
        {
            m_Specification.Width = width;
            m_Specification.Height = height;
            Invalidate();
        }
    }

    void OpenGLFramebuffer::Invalidate() noexcept
    {
        if (m_RendererID) DeleteOpenGLObjects();

        glGenFramebuffers(1, &m_RendererID);
        glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);

        // create a color attachment texture
        glGenTextures(1, &m_ColorAttachment);
        glBindTexture(GL_TEXTURE_2D, m_ColorAttachment);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Specification.Width, m_Specification.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorAttachment, 0);

        // create a renderbuffer object for depth and stencil attachment (we won't be sampling these)
        glGenRenderbuffers(1, &m_DepthStencilAttachment);
        glBindRenderbuffer(GL_RENDERBUFFER, m_DepthStencilAttachment);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_Specification.Width, m_Specification.Height);
        glBindRenderbuffer(GL_RENDERBUFFER, 0);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_DepthStencilAttachment);

        FL_CORE_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "Framebuffer is incomplete!");

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void OpenGLFramebuffer::DeleteOpenGLObjects() noexcept
    {
        glDeleteFramebuffers(1, &m_RendererID);
        glDeleteTextures(1, &m_ColorAttachment);
        glDeleteRenderbuffers(1, &m_DepthStencilAttachment);
    }
}
