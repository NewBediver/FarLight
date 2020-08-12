#pragma once

#include <vector>

#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

#include <glad/glad.h>

namespace FarLight
{
	class OpenGLIndexBuffer final
		: public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(const OpenGLIndexBuffer&) = delete;
		OpenGLIndexBuffer(OpenGLIndexBuffer&&) = delete;
		OpenGLIndexBuffer& operator=(const OpenGLIndexBuffer&) = delete;
		OpenGLIndexBuffer& operator=(OpenGLIndexBuffer&&) = delete;

		explicit OpenGLIndexBuffer(const void* indicies, unsigned count) noexcept;
		explicit OpenGLIndexBuffer(unsigned count) noexcept;

		virtual ~OpenGLIndexBuffer() noexcept;

		virtual void Bind() const noexcept override;
		virtual void Unbind() const noexcept override;

		virtual unsigned GetID() const noexcept override { return m_RendererID; }

		virtual void AddSubData(const void* indices, unsigned count) noexcept override;

		virtual unsigned GetCount() const noexcept override { return m_Count; }
		virtual void SetCount(unsigned count) noexcept override { m_Count = count; }

		virtual unsigned GetUsageType() const noexcept override { return m_UsageType; }

	private:
		unsigned m_RendererID;
		unsigned m_Count;
		GLenum m_UsageType;
	};
}