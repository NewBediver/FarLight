#pragma once

#include <FarLight.h>

using namespace FarLight;

class ExampleLayer
	: public Layer
{
public:
	explicit ExampleLayer();
	virtual void OnAttach() const override;
	virtual void OnDetach() const override;
	virtual void OnUpdate() override;
	virtual void OnUserInterfaceRender() override;
	virtual void OnEvent(Event& event) override;
};