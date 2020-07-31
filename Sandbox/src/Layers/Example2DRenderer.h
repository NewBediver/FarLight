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
	void LogTimerData(const std::string& name, float duration);

	FarLight::OrthographicCameraController m_CameraController;

	FarLight::Ref<FarLight::Texture2D> m_Texture;
	FarLight::Ref<FarLight::Texture2D> m_ShovelKnightTexture;

	FarLight::CPUTimer m_Timer;
	FarLight::CPUTimer m_TotalTimer;

	std::unordered_map<std::string, float> m_CPUProfilerData;
};