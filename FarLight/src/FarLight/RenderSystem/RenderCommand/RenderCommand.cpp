#include "flpch.h"

#include "RenderCommand.h"

#include "Platform/Renderer/OpenGL/RendererAPI/OpenGLRendererAPI.h"

namespace FarLight
{
	std::shared_ptr<RendererAPI> RenderCommand::_rendererAPI = std::make_shared<OpenGLRendererAPI>();
}