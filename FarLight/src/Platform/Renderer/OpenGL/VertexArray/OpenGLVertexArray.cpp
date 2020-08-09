// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OpenGLVertexArray.h"

#include <glad\glad.h>

namespace FarLight
{
	FarLight::OpenGLVertexArray::OpenGLVertexArray() noexcept
		: m_RendererID(0)
		, m_VertexBufferIndex(0)
	{
		FL_PROFILE_FUNCTION();

		glCreateVertexArrays(1, &m_RendererID);
	}

	FarLight::OpenGLVertexArray::~OpenGLVertexArray() noexcept
	{
		FL_PROFILE_FUNCTION();

		glDeleteVertexArrays(1, &m_RendererID);
	}

	void FarLight::OpenGLVertexArray::Bind() const noexcept
	{
		FL_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
	}

	void FarLight::OpenGLVertexArray::Unbind() const noexcept
	{
		FL_PROFILE_FUNCTION();

		glBindVertexArray(0);
	}

	void FarLight::OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& buffer) noexcept
	{
		FL_PROFILE_FUNCTION();

		FL_CORE_ASSERT(buffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		buffer->Bind();

		const auto& layout = buffer->GetLayout();
		for (auto& element = layout.cbegin(); element != layout.cend(); ++element)
		{
			glEnableVertexAttribArray(m_VertexBufferIndex);
			glVertexAttribPointer(m_VertexBufferIndex,
				ShaderDataTypeCount(element->Type),
				ShaderDataTypeToOpenGLBaseType(element->Type),
				element->Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				reinterpret_cast<const void*>(static_cast<long long>(element->Offset)));
			++m_VertexBufferIndex;
		}

		m_VertexBuffers.push_back(buffer);
	}

	void FarLight::OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& buffer) noexcept
	{
		FL_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
		buffer->Bind();

		m_IndexBuffer = buffer;
	}
}