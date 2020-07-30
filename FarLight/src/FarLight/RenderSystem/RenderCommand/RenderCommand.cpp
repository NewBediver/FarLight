// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "RenderCommand.h"

#include "Platform/Renderer/OpenGL/RendererAPI/OpenGLRendererAPI.h"

namespace FarLight
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();
}