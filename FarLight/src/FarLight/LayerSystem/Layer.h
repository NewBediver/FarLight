#pragma once

#include "flpch.h"

#include "FarLight/Core.h"
#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API Layer
	{
	public:
		explicit Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() const = 0;
		virtual void OnDetach() const = 0;
		virtual void OnUpdate() = 0;
		virtual void OnUserInterfaceRender() = 0;
		virtual void OnEvent(Event& event) = 0;

		const std::string& GetName() const;

	private:
		std::string _name;
	};
}
