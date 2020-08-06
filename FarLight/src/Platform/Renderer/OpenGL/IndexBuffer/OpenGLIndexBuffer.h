#pragma once

#include <vector>

#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

#include <glad/glad.h>

namespace FarLight
{
	class OpenGLIndexBuffer
		: public IndexBuffer
	{
	public:
		explicit OpenGLIndexBuffer(const unsigned int* indicies, unsigned int count);
		explicit OpenGLIndexBuffer(unsigned int count);

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddSubData(const unsigned int* indices, unsigned int size) override;

		virtual unsigned int GetCount() const override { return m_Count; }
		virtual void SetCount(unsigned int count) override { m_Count = count; }

		virtual unsigned int GetID() const override { return m_RendererID; }
		virtual unsigned int GetUsageType() const override { return m_UsageType; }

		virtual ~OpenGLIndexBuffer();

	private:
		unsigned int m_RendererID;
		unsigned int m_Count;
		GLenum m_UsageType;
	};
}