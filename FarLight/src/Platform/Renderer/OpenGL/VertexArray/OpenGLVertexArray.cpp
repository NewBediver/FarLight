#include "flpch.h"

#include "OpenGLVertexArray.h"

#include <glad\glad.h>

namespace FarLight
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case FarLight::ShaderDataType::Float:    return GL_FLOAT;
			case FarLight::ShaderDataType::Float2:   return GL_FLOAT;
			case FarLight::ShaderDataType::Float3:   return GL_FLOAT;
			case FarLight::ShaderDataType::Float4:   return GL_FLOAT;
			case FarLight::ShaderDataType::Mat3:     return GL_FLOAT;
			case FarLight::ShaderDataType::Mat4:     return GL_FLOAT;
			case FarLight::ShaderDataType::Int:      return GL_INT;
			case FarLight::ShaderDataType::Int2:     return GL_INT;
			case FarLight::ShaderDataType::Int3:     return GL_INT;
			case FarLight::ShaderDataType::Int4:     return GL_INT;
			case FarLight::ShaderDataType::Bool:     return GL_BOOL;
		}

		FL_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	FarLight::OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &_rendererID);
	}

	FarLight::OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &_rendererID);
	}

	void FarLight::OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(_rendererID);
	}

	void FarLight::OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void FarLight::OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer)
	{
		FL_CORE_ASSERT(buffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(_rendererID);
		buffer->Bind();

		unsigned int index = 0;
		const auto& layout = buffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				ShaderDataTypeCount(element.Type),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			++index;
		}

		_vertexBuffers.push_back(buffer);
	}

	void FarLight::OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& buffer)
	{
		glBindVertexArray(_rendererID);
		buffer->Bind();

		_indexBuffer = buffer;
	}
}