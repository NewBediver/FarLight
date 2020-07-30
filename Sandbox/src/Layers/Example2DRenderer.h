#pragma once

#include <FarLight.h>

#include <glm/glm.hpp>

class Example2DRenderer
	: public FarLight::Layer
{
public:
	explicit Example2DRenderer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(const FarLight::Timestep& timestamp) override;
	virtual void OnUserInterfaceRender() override;
	virtual void OnEvent(FarLight::Event& event) override;

private:
	FarLight::OrthographicCameraController m_CameraController;
};