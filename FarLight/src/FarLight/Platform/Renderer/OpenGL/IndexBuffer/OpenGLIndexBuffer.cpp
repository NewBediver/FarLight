#include "flpch.h"
#include "OpenGLIndexBuffer.h"

#include <glad/glad.h>

namespace FarLight
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* indicies, unsigned int count)
		: _rendererID(0), _count(count)
	{
		glCreateBuffers(1, &_rendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, _count * sizeof(unsigned int), indicies, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &_rendererID);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}