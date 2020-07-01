#pragma once

#include <FarLight/LayerSystem/Layer.h>

using namespace FarLight;

class ExampleLayer
	: public Layer
{
public:
	ExampleLayer(std::string name);

	virtual void OnUpdate() override;
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent(Event& event) override;

};

