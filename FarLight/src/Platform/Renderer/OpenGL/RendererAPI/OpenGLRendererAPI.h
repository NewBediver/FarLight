#pragma once

#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

namespace FarLight
{
	class OpenGLRendererAPI final
		: public RendererAPI
	{
	public:
		OpenGLRendererAPI(const OpenGLRendererAPI&) = delete;
		OpenGLRendererAPI(OpenGLRendererAPI&&) = delete;
		OpenGLRendererAPI& operator=(const OpenGLRendererAPI&) = delete;
		OpenGLRendererAPI& operator=(OpenGLRendererAPI&&) = delete;

		explicit OpenGLRendererAPI() noexcept = default;

		virtual void Init() const noexcept override;
		virtual void SetClearColor(const glm::vec4& color) const noexcept override;
		virtual void SetViewport(unsigned x, unsigned y, unsigned width, unsigned height) const noexcept override;
		virtual void Clear() const noexcept override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) const noexcept override;
	};
}