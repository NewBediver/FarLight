// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OpenGLVertexBuffer.h"

namespace FarLight
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(const float* vertices, unsigned int size, const BufferLayout& layout)
		: m_RendererID(0)
		, m_Offset(0)
		, m_Layout(layout)
		, m_UsageType(GL_STATIC_DRAW)
	{
		FL_PROFILE_FUNCTION();

		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, m_UsageType);
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(unsigned int size, const BufferLayout& layout)
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

	void OpenGLVertexBuffer::AddSubData(const float* vertices, unsigned int size)
	{
		FL_PROFILE_FUNCTION();
		FL_CORE_ASSERT(m_UsageType == GL_DYNAMIC_DRAW, "Cannot add sub data to non-dynamic vertex array!");

		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferSubData(GL_ARRAY_BUFFER, m_Offset, size, vertices);

		m_Offset += size;
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		FL_PROFILE_FUNCTION();

		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		FL_PROFILE_FUNCTION();

		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		FL_PROFILE_FUNCTION();

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}