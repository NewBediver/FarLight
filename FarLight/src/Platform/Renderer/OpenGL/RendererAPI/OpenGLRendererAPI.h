#pragma once

#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

namespace FarLight
{
	class OpenGLRendererAPI final
		: public RendererAPI
	{
	public:
		virtual void Init() const override;
		virtual void SetClearColor(const glm::vec4& color) const override;
		virtual void SetViewport(unsigned x, unsigned y, unsigned width, unsigned height) const override;
		virtual void Clear() const override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) const override;
	};
}