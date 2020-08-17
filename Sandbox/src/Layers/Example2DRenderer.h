#pragma once

#include <FarLight.h>

#include <glm/glm.hpp>

class Example2DRenderer
	: public FarLight::Layer
{
public:
	explicit Example2DRenderer() noexcept;

	virtual void OnAttach() noexcept override;
	virtual void OnDetach() noexcept override;
	virtual void OnUpdate(const FarLight::Timestep& timestamp) noexcept override;
	virtual void OnUserInterfaceRender() noexcept override;
	virtual void OnEvent(FarLight::Event& event) noexcept override;

private:
	FarLight::OrthographicCameraController m_CameraController;

	FarLight::Ref<FarLight::Texture2D> m_Texture;
	FarLight::Ref<FarLight::Texture2D> m_ShovelKnightTexture;

	float m_Rotation;
	FarLight::BatchController m_Controller;

	FarLight::AtlasMap m_AtlasMap;
	std::unordered_map<char, glm::vec2> m_AtlasCoords;
};