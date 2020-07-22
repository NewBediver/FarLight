#include "flpch.h"

#include "OpenGLVertexBuffer.h"

#include <glad/glad.h>

namespace FarLight
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(const float* verticies, const unsigned int size, const BufferLayout& layout)
		: _rendererID(0), _layout(layout)
	{
		glCreateBuffers(1, &_rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
		glBufferData(GL_ARRAY_BUFFER, size, verticies, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &_rendererID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}