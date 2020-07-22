#pragma once

#include <FarLight.h>

class ExampleLayer
	: public FarLight::Layer
{
public:
	ExampleLayer();

	virtual void OnAttach() const override;
	virtual void OnDetach() const override;
	virtual void OnUpdate(const FarLight::Timestep& timestamp) override;
	virtual void OnUserInterfaceRender() override;
	virtual void OnEvent(FarLight::Event& event) override;

private:
	void HandleInput(const FarLight::Timestep& timestamp);

	FarLight::Ref<FarLight::Shader> _shader;
	FarLight::Ref<FarLight::VertexArray> _vertexArray;

	FarLight::Ref<FarLight::Shader> _blueShader;
	FarLight::Ref<FarLight::VertexArray> _squareVertexArray;

	FarLight::OrthographicCamera _camera;

	float _squareMovementSpeed;
	glm::vec3 _squarePosition;
	glm::vec3 _squareColor;
};