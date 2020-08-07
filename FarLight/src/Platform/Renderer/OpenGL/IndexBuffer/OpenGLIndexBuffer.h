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
		explicit OpenGLIndexBuffer(const void* indicies, unsigned count);
		explicit OpenGLIndexBuffer(unsigned count);

		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual unsigned GetID() const override { return m_RendererID; }

		virtual void AddSubData(const void* indices, unsigned size) override;

		virtual unsigned GetCount() const override { return m_Count; }
		virtual void SetCount(unsigned count) override { m_Count = count; }

		virtual unsigned GetUsageType() const override { return m_UsageType; }

	private:
		unsigned m_RendererID;
		unsigned m_Count;
		GLenum m_UsageType;
	};
}