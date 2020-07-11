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

	private:
		unsigned int _rendererID;
	};
}