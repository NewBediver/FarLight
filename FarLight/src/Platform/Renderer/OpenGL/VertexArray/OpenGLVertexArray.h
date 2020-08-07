#pragma once

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"

#include <glad/glad.h>

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

	class OpenGLVertexArray final
		: public VertexArray
	{
	public:
		explicit OpenGLVertexArray();

		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual unsigned GetID() const override { return m_RendererID; }

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& buffer) override;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& buffer) override;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }

	private:
		unsigned m_RendererID;
		unsigned m_VertexBufferIndex;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;
	};
}