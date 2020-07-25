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

	FarLight::Library<FarLight::Shader> _shaderLib;
	FarLight::Library<FarLight::Texture> _textureLib;

	FarLight::Ref<FarLight::VertexArray> _vertexArray;
	FarLight::Ref<FarLight::VertexArray> _squareVertexArray;

	FarLight::OrthographicCamera _camera;

	float _squareMovementSpeed;
	glm::vec3 _squarePosition;
	glm::vec3 _squareColor;
};