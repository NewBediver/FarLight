#pragma once

#include <FarLight.h>

using namespace FarLight;

class InputLayer
	: public Layer
{
public:
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate() override;
	virtual void OnEvent(Event& event) override;
};