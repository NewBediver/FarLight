#include <FarLight.h>

#include <FarLight/Core/EntryPoint.h>

#include "Layers/EditorLayer.h"

namespace FarLight
{
	Application& CreateApplication() noexcept
	{
		auto& app = Application::GetInstance();
		app.PushLayer(CreateRef<EditorLayer>());
		return app;
	}
}
