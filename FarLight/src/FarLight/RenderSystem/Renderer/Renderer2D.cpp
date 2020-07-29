// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Renderer2D.h"

#include <glm/gtc/matrix_transform.hpp>

namespace FarLight
{
	Scope<Renderer2D::Renderer2DStorage> Renderer2D::_storage = nullptr;

	void Renderer2D::Init()
	{
		RenderCommand::Init();
		FL_CORE_INFO("Renderer2D initialized.");

		_storage = CreateScope<Renderer2DStorage>();
		_storage->m_VertexArray = FarLight::VertexArray::Create();

		float squareVertices[3 * 4] = {
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f
		};

		FarLight::BufferLayout squareLayout = {
			{ FarLight::ShaderDataType::Float3, "a_Position" }
		};
		_storage->m_VertexArray->AddVertexBuffer(FarLight::VertexBuffer::Create(squareVertices, sizeof(squareVertices), squareLayout));

		unsigned int squareIndicies[6] = { 0, 1, 2, 2, 3, 0 };
		_storage->m_VertexArray->SetIndexBuffer(FarLight::IndexBuffer::Create(squareIndicies, sizeof(squareIndicies) / sizeof(unsigned int)));

		_storage->m_Shader = FarLight::Shader::Create("assets/shaders/Square/Square.vert", "assets/shaders/Square/Square.frag");
	}

	void Renderer2D::Shutdown()
	{
		_storage.reset();
		FL_CORE_INFO("Renderer2D terminated.");
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		_storage->m_Shader->Bind();
		_storage->m_Shader->SetMat4("u_Projection", camera.GetProjectionMatrix());
		_storage->m_Shader->SetMat4("u_View", camera.GetViewMatrix());
	}

	void Renderer2D::EndScene()
	{

	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{
		_storage->m_Shader->Bind();
		_storage->m_Shader->SetMat4("u_Model", glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		_storage->m_Shader->SetFloat4("u_Color", color.r, color.g, color.b, color.a);

		_storage->m_VertexArray->Bind();
		RenderCommand::DrawIndexed(_storage->m_VertexArray);
	}
}