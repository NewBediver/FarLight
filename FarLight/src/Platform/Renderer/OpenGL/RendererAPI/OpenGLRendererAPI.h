#pragma once

#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

namespace FarLight
{
	class FARLIGHT_API OpenGLRendererAPI
		: public RendererAPI
	{
	public:
		virtual void Init() const override;
		virtual void SetClearColor(const glm::vec4& color) const override;
		virtual void SetViewport(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height) const override;
		virtual void Clear() const override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) const override;
	};
}