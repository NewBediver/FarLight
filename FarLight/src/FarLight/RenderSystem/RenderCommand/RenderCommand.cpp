#include "flpch.h"

#include "RenderCommand.h"

#include "Platform/Renderer/OpenGL/RendererAPI/OpenGLRendererAPI.h"

namespace FarLight
{
	Scope<RendererAPI> RenderCommand::_rendererAPI = Scope<OpenGLRendererAPI>(new OpenGLRendererAPI());
}