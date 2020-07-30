// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Renderer2D.h"

#include <glm/gtc/matrix_transform.hpp>

namespace FarLight
{
	Scope<Renderer2D::Renderer2DStorage> Renderer2D::s_Storage = nullptr;

	void Renderer2D::Init()
	{
		RenderCommand::Init();
		FL_CORE_INFO("Renderer2D initialized.");

		s_Storage = CreateScope<Renderer2DStorage>();
		s_Storage->m_VertexArray = FarLight::VertexArray::Create();

		float squareVertices[4*5] = {
			// position             // textures
			 0.5f, -0.5f,  0.0f,    1.0f, 0.0f,
			 0.5f,  0.5f,  0.0f,    1.0f, 1.0f,
			-0.5f,  0.5f,  0.0f,    0.0f, 1.0f,
			-0.5f, -0.5f,  0.0f,    0.0f, 0.0f
		};

		FarLight::BufferLayout squareLayout = {
			{ FarLight::ShaderDataType::Float3, "a_Position" },
			{ FarLight::ShaderDataType::Float2, "a_TexCoord" }
		};
		s_Storage->m_VertexArray->AddVertexBuffer(FarLight::VertexBuffer::Create(squareVertices, sizeof(squareVertices), squareLayout));

		unsigned int squareIndicies[2*3] = { 0, 1, 2, 2, 3, 0 };
		s_Storage->m_VertexArray->SetIndexBuffer(FarLight::IndexBuffer::Create(squareIndicies, sizeof(squareVertices) / sizeof(squareVertices[0])));

		s_Storage->m_Shader = FarLight::Shader::Create("assets/shaders/Square/Square.vert", "assets/shaders/Square/Square.frag");

		s_Storage->m_TextureShader = FarLight::Shader::Create("assets/shaders/Texture/Texture.vert", "assets/shaders/Texture/Texture.frag");
		s_Storage->m_TextureShader->Bind();
		s_Storage->m_TextureShader->SetInt("u_Texture", 0);
	}

	void Renderer2D::Shutdown()
	{
		s_Storage.reset();
		FL_CORE_INFO("Renderer2D terminated.");
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		s_Storage->m_Shader->Bind();
		s_Storage->m_Shader->SetMat4("u_Projection", camera.GetProjectionMatrix());
		s_Storage->m_Shader->SetMat4("u_View", camera.GetViewMatrix());

		s_Storage->m_TextureShader->Bind();
		s_Storage->m_TextureShader->SetMat4("u_Projection", camera.GetProjectionMatrix());
		s_Storage->m_TextureShader->SetMat4("u_View", camera.GetViewMatrix());
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
		s_Storage->m_Shader->Bind();
		s_Storage->m_Shader->SetMat4("u_Model", glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		s_Storage->m_Shader->SetFloat4("u_Color", color.r, color.g, color.b, color.a);

		s_Storage->m_VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->m_VertexArray);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture)
	{
		s_Storage->m_TextureShader->Bind();
		s_Storage->m_TextureShader->SetMat4("u_Model", glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));

		texture->Bind(0);

		s_Storage->m_VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->m_VertexArray);
	}

}