#include "ExampleLayer.h"

FarLight::ExampleLayer::ExampleLayer()
	: Layer("ExampleLayer")
	, _camera(-1.5f, 1.5f, -1.0f, 1.0f)
	, _cameraMovementSpeed(0.01f)
	, _cameraPosition(0.0f)
	, _cameraRotationSpeed(1.0f)
	, _cameraRotation(0.0f)
{
	_vertexArray = VertexArray::Create();

	float verticies[3 * 7] = {
		-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
		 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
		 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
	};

	std::shared_ptr<VertexBuffer> vertexBuffer = VertexBuffer::Create(verticies, sizeof(verticies));
	BufferLayout layout = {
		{ ShaderDataType::Float3, "a_Position" },
		{ ShaderDataType::Float4, "a_Color" }
	};
	vertexBuffer->SetLayout(layout);
	_vertexArray->AddVertexBuffer(vertexBuffer);

	unsigned int indices[3] = { 0, 1, 2 };
	std::shared_ptr<IndexBuffer> indexBuffer = IndexBuffer::Create(indices, sizeof(indices) / sizeof(unsigned int));
	_vertexArray->SetIndexBuffer(indexBuffer);

	_squareVertexArray = VertexArray::Create();

	float squareVertices[3 * 4] = {
		-0.75f, -0.75f, 0.0f,
		 0.75f, -0.75f, 0.0f,
		 0.75f,  0.75f, 0.0f,
		-0.75f,  0.75f, 0.0f
	};

	std::shared_ptr<VertexBuffer> squareVertexBuffer = VertexBuffer::Create(squareVertices, sizeof(squareVertices));
	squareVertexBuffer->SetLayout({
		{ShaderDataType::Float3, "a_Position"}
		});
	_squareVertexArray->AddVertexBuffer(squareVertexBuffer);

	unsigned int squareIndicies[6] = { 0, 1, 2, 2, 3, 0 };
	std::shared_ptr<IndexBuffer> squareIndexBuffer = IndexBuffer::Create(squareIndicies, sizeof(squareIndicies) / sizeof(unsigned int));
	_squareVertexArray->SetIndexBuffer(squareIndexBuffer);

	std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

	std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 a_Color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				a_Color = vec4(v_Position + 0.5, 1.0);
				a_Color = v_Color;
			}
		)";

	_shader = Shader::Create(vertexSrc, fragmentSrc);


	std::string blueVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

	std::string blueFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 a_Color;

			in vec3 v_Position;

			void main()
			{
				a_Color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

	_blueShader = Shader::Create(blueVertexSrc, blueFragmentSrc);
}

void FarLight::ExampleLayer::OnAttach() const
{
}

void FarLight::ExampleLayer::OnDetach() const
{
}

void FarLight::ExampleLayer::OnUpdate()
{
	HandleInput();

	FarLight::RenderCommand::SetClearColor({ 0.2f, 0.2f, 0.2f, 1.00f });
	FarLight::RenderCommand::Clear();

	_camera.SetPosition(_cameraPosition);
	_camera.SetZRotation(_cameraRotation);

	FarLight::Renderer::BeginScene(_camera);

	FarLight::Renderer::Submit(_blueShader, _squareVertexArray);
	FarLight::Renderer::Submit(_shader, _vertexArray);

	FarLight::Renderer::EndScene();
}

void FarLight::ExampleLayer::OnUserInterfaceRender()
{
}

void FarLight::ExampleLayer::OnEvent(Event& event)
{
}

void FarLight::ExampleLayer::HandleInput()
{
	if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_LEFT))
		_cameraPosition.x += _cameraMovementSpeed;
	else if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_RIGHT))
		_cameraPosition.x -= _cameraMovementSpeed;

	if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_DOWN))
		_cameraPosition.y += _cameraMovementSpeed;
	else if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_UP))
		_cameraPosition.y -= _cameraMovementSpeed;

	if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_Q))
		_cameraRotation -= _cameraRotationSpeed;
	else if (Input::IsKeyPressed(KeyboardKeyCodes::FL_KEY_E))
		_cameraRotation += _cameraRotationSpeed;
}
