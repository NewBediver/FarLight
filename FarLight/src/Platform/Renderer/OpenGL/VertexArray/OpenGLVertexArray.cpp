// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

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
		: m_RendererID(0)
		, m_VertexBufferIndex(0)
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	FarLight::OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void FarLight::OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void FarLight::OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void FarLight::OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& buffer)
	{
		FL_CORE_ASSERT(buffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		buffer->Bind();

		const auto& layout = buffer->GetLayout();
		for (auto& element = layout.cbegin(); element != layout.cend(); ++element)
		{
			glEnableVertexAttribArray(m_VertexBufferIndex);
			glVertexAttribPointer(m_VertexBufferIndex,
				ShaderDataTypeCount(element->m_Type),
				ShaderDataTypeToOpenGLBaseType(element->m_Type),
				element->m_Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				reinterpret_cast<const void*>(static_cast<long long>(element->m_Offset)));
			++m_VertexBufferIndex;
		}

		m_VertexBuffers.push_back(buffer);
	}

	void FarLight::OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& buffer)
	{
		glBindVertexArray(m_RendererID);
		buffer->Bind();

		m_IndexBuffer = buffer;
	}
}