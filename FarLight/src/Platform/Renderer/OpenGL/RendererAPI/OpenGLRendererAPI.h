#pragma once

#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

namespace FarLight
{
	class OpenGLRendererAPI
		: public RendererAPI
	{
	public:
		virtual void Init() const override;
		virtual void SetClearColor(const glm::vec4& color) const override;
		virtual void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const override;
		virtual void Clear() const override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) const override;
	};
}