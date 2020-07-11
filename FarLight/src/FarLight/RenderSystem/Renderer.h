#pragma once

namespace FarLight
{
	enum class RendererAPI
	{
		None = 0,
		OpenGL = 1
	};


	class FARLIGHT_API Renderer
	{
	public:
		static RendererAPI GetAPI() { return _rendererAPI; }
		static void SetAPI(RendererAPI api) { _rendererAPI = api; }

	private:
		static RendererAPI _rendererAPI;
	};
}