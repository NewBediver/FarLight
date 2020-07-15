#pragma once

#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"

namespace FarLight
{
	class FARLIGHT_API OpenGLVertexBuffer
		: public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vetricies, unsigned int size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const BufferLayout& GetLayout() const override { return _layout; }
		virtual void SetLayout(const BufferLayout& layout) override { _layout = layout; }

	private:
		unsigned int _rendererID;
		BufferLayout _layout;
	};
}