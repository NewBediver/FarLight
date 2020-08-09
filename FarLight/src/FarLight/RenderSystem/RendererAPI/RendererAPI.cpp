// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "RendererAPI.h"

namespace FarLight
{
	RendererAPI::API RendererAPI::GetAPI() noexcept
	{
		#ifdef FL_PLATFORM_WINDOWS
			static API s_API = API::OpenGL;
			return s_API;
		#else
			FL_CORE_ASSERT(false, "Unknown platform!");
			static API s_API = API::None;
			return s_API;
		#endif
	}
}