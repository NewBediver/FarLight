#pragma once

#include "FarLight/EventSystem/Event.h"
#include "FarLight/Core/Timestep.h"

namespace FarLight
{
	class FARLIGHT_API Layer
	{
	public:
		explicit Layer(const std::string& name = "Layer")
			: _name(name) { }

		virtual void OnAttach() const = 0;
		virtual void OnDetach() const = 0;
		virtual void OnUpdate(const Timestep& timestamp) = 0;
		virtual void OnUserInterfaceRender() = 0;
		virtual void OnEvent(Event& event) = 0;

		const std::string& GetName() const { return _name; }

		virtual ~Layer() = default;

	private:
		std::string _name;
	};
}
