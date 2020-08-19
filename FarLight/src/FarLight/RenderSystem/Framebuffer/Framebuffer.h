#pragma once

namespace FarLight
{
	struct FramebufferSpecification
	{
		unsigned Width = 0;
		unsigned Height = 0;
		unsigned Samples = 1;
	};

	class Framebuffer
	{
	public:
		static Ref<Framebuffer> Create(const FramebufferSpecification& spec) noexcept;

		Framebuffer(const Framebuffer&) = delete;
		Framebuffer(Framebuffer&&) = delete;
		Framebuffer& operator=(const Framebuffer&) = delete;
		Framebuffer& operator=(Framebuffer&&) = delete;

		explicit Framebuffer() noexcept = default;
		virtual ~Framebuffer() noexcept = default;

		virtual void Bind() const noexcept = 0;
		virtual void Unbind() const noexcept = 0;

		virtual void Resize(unsigned width, unsigned height) noexcept = 0;

		virtual unsigned GetID() const noexcept = 0;
		virtual unsigned GetColorAttachmentID() const noexcept = 0;
		virtual unsigned GetDepthStencilAttachmentID() const noexcept = 0;

		virtual const FramebufferSpecification& GetSpecification() const noexcept = 0;
	};
}