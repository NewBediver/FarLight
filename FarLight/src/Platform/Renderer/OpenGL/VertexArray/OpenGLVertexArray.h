#pragma once

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"

#include <glad/glad.h>

namespace FarLight
{
	static constexpr
	GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) noexcept
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
		OpenGLVertexArray(const OpenGLVertexArray&) = delete;
		OpenGLVertexArray(OpenGLVertexArray&&) = delete;
		OpenGLVertexArray& operator=(const OpenGLVertexArray&) = delete;
		OpenGLVertexArray& operator=(OpenGLVertexArray&&) = delete;

		explicit OpenGLVertexArray() noexcept;

		virtual ~OpenGLVertexArray() noexcept;

		virtual void Bind() const noexcept override;
		virtual void Unbind() const noexcept override;

		virtual unsigned GetID() const noexcept override { return m_RendererID; }

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& buffer) noexcept override;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& buffer) noexcept override;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const noexcept { return m_VertexBuffers; }
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const noexcept { return m_IndexBuffer; }

	private:
		unsigned m_RendererID;
		unsigned m_VertexBufferIndex;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;
	};
}