#pragma once

#include "FarLight/RenderSystem/Framebuffer/Framebuffer.h"

namespace FarLight
{
	class OpenGLFramebuffer
		: public Framebuffer
	{
	public:
		OpenGLFramebuffer(const OpenGLFramebuffer&) = delete;
		OpenGLFramebuffer(OpenGLFramebuffer&&) = delete;
		OpenGLFramebuffer& operator=(const OpenGLFramebuffer&) = delete;
		OpenGLFramebuffer& operator=(OpenGLFramebuffer&&) = delete;

		explicit OpenGLFramebuffer(const FramebufferSpecification& spec) noexcept;
		virtual ~OpenGLFramebuffer() noexcept;

		virtual void Bind() const noexcept override;
		virtual void Unbind() const noexcept override;

		virtual unsigned GetID() const noexcept override { return m_RendererID; }
		virtual unsigned GetColorAttachmentID() const noexcept override { return m_ColorAttachment; }
		virtual unsigned GetDepthStencilAttachmentID() const noexcept override { return m_DepthStencilAttachment; }

		virtual const FramebufferSpecification& GetSpecification() const noexcept { return m_Specification; }

	private:
		void Invalidate() noexcept;

		unsigned m_RendererID;
		unsigned m_ColorAttachment, m_DepthStencilAttachment;
		FramebufferSpecification m_Specification;
	};
}