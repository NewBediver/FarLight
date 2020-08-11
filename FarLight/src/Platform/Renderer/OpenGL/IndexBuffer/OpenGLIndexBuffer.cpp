// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OpenGLIndexBuffer.h"

namespace FarLight
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(const void* indicies, unsigned count) noexcept
		: m_RendererID(0)
		, m_Count(count)
		, m_UsageType(GL_STATIC_DRAW)
	{
		FL_PROFILE_FUNCTION();

		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(unsigned), indicies, m_UsageType);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned count) noexcept
		: m_RendererID(0)
		, m_Count(0)
		, m_UsageType(GL_DYNAMIC_DRAW)
	{
		FL_PROFILE_FUNCTION();

		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned), nullptr, m_UsageType);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer() noexcept
	{
		FL_PROFILE_FUNCTION();

		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLIndexBuffer::Bind() const noexcept
	{
		FL_PROFILE_FUNCTION();

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLIndexBuffer::Unbind() const noexcept
	{
		FL_PROFILE_FUNCTION();

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void OpenGLIndexBuffer::AddSubData(const void* indices, unsigned count) noexcept
	{
		FL_PROFILE_FUNCTION();
		FL_CORE_ASSERT(m_UsageType == GL_DYNAMIC_DRAW, "Cannot add sub data to non-dynamic index array!");

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(unsigned), count * sizeof(unsigned), indices);

		m_Count += count;
	}
}