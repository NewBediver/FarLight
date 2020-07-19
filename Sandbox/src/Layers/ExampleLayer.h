#pragma once

#include <FarLight.h>

namespace FarLight
{
	class ExampleLayer
		: public Layer
	{
	public:
		ExampleLayer();

		virtual void OnAttach() const override;
		virtual void OnDetach() const override;
		virtual void OnUpdate(const Timestep& timestamp) override;
		virtual void OnUserInterfaceRender() override;
		virtual void OnEvent(Event& event) override;

	private:
		void HandleInput(const Timestep& timestamp);

		std::shared_ptr<Shader> _shader;
		std::shared_ptr<VertexArray> _vertexArray;

		std::shared_ptr<Shader> _blueShader;
		std::shared_ptr<VertexArray> _squareVertexArray;

		OrthographicCamera _camera;

		float _cameraMovementSpeed;
		glm::vec3 _cameraPosition;

		float _cameraRotationSpeed;
		float _cameraRotation;

		float _squareMovementSpeed;
		glm::vec3 _squarePosition;
		glm::vec3 _squareColor;
	};
}