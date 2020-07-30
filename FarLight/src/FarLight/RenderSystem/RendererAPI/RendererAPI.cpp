// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "RendererAPI.h"

namespace FarLight
{
	RendererAPI::API RendererAPI::s_Api = RendererAPI::API::OpenGL;
}