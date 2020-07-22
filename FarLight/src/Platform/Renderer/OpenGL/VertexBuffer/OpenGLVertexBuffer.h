#pragma once

#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"

namespace FarLight
{
	class FARLIGHT_API OpenGLVertexBuffer
		: public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(const float* vetricies, const unsigned int size, const BufferLayout& layout);

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const BufferLayout& GetLayout() const override { return _layout; }
		virtual void SetLayout(const BufferLayout& layout) override { _layout = layout; }

		virtual ~OpenGLVertexBuffer();

	private:
		unsigned int _rendererID;
		BufferLayout _layout;
	};
}