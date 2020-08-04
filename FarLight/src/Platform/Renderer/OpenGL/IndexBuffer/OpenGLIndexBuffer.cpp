// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OpenGLIndexBuffer.h"

namespace FarLight
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(const unsigned int* indicies, unsigned int count)
		: m_RendererID(0)
		, m_Count(count)
		, m_UsageType(GL_STATIC_DRAW)
	{
		FL_PROFILE_FUNCTION();

		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(unsigned int), indicies, m_UsageType);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int count)
		: m_RendererID(0)
		, m_Count(0)
		, m_UsageType(GL_DYNAMIC_DRAW)
	{
		FL_PROFILE_FUNCTION();

		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(unsigned int), nullptr, m_UsageType);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		FL_PROFILE_FUNCTION();

		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		FL_PROFILE_FUNCTION();

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		FL_PROFILE_FUNCTION();

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void OpenGLIndexBuffer::AddSubData(const unsigned int* vertices, unsigned int count, unsigned int offset)
	{
		FL_PROFILE_FUNCTION();
		FL_CORE_ASSERT(m_UsageType == GL_DYNAMIC_DRAW, "Cannot add sub data to non-dynamic index array!");

		Bind();
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, count * sizeof(unsigned int), vertices);
		m_Count += count;
	}
}