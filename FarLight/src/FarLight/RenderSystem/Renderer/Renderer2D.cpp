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
		FL_PROFILE_FUNCTION();

		RenderCommand::Init();
		FL_CORE_INFO("[Renderer2D] initialized.");

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
			{ FarLight::ShaderDataType::Float2, "a_TextureCoordinates" }
		};
		s_Storage->m_VertexArray->AddVertexBuffer(FarLight::VertexBuffer::Create(squareVertices, sizeof(squareVertices), squareLayout));

		unsigned int squareIndicies[2*3] = { 0, 1, 2, 2, 3, 0 };
		s_Storage->m_VertexArray->SetIndexBuffer(FarLight::IndexBuffer::Create(squareIndicies, sizeof(squareVertices) / sizeof(squareVertices[0])));

		s_Storage->m_Shader = FarLight::Shader::Create("assets/shaders/DefaultSquare/DefaultSquareShader.vert", "assets/shaders/DefaultSquare/DefaultSquareShader.frag");

		s_Storage->m_Texture = FarLight::Texture2D::Create(1, 1);
	}

	void Renderer2D::Shutdown()
	{
		FL_PROFILE_FUNCTION();

		s_Storage.reset();
		FL_CORE_INFO("[Renderer2D] terminated.");
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		FL_PROFILE_FUNCTION();

		auto* ptr = &s_Storage->m_Shader;
		(*ptr)->Bind();
		(*ptr)->SetMat4("u_Transformation.Projection", camera.GetProjectionMatrix());
		(*ptr)->SetMat4("u_Transformation.View", camera.GetViewMatrix());
		(*ptr)->SetInt("u_Texture", 0);
	}

	void Renderer2D::EndScene()
	{
		FL_PROFILE_FUNCTION();
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{
		FL_PROFILE_FUNCTION();

		s_Storage->m_Shader->SetMat4("u_Transformation.Model", glm::translate(glm::mat4(1.0f), position)
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		s_Storage->m_Shader->SetFloat4("u_Color", color.r, color.g, color.b, color.a);
		s_Storage->m_Shader->SetFloat("u_TilingFactor", 1.0f);

		s_Storage->m_Texture->Bind(0);

		s_Storage->m_VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->m_VertexArray);

		s_Storage->m_Texture->Unbind(0);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color)
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, color);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color)
	{
		FL_PROFILE_FUNCTION();

		s_Storage->m_Shader->SetMat4("u_Transformation.Model", glm::translate(glm::mat4(1.0f), position)
			* glm::rotate(glm::mat4(1.0f), counterclockwiseRadians, glm::vec3(0.0f, 0.0f, 1.0f))
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		s_Storage->m_Shader->SetFloat4("u_Color", color.r, color.g, color.b, color.a);
		s_Storage->m_Shader->SetFloat("u_TilingFactor", 1.0f);

		s_Storage->m_Texture->Bind(0);

		s_Storage->m_VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->m_VertexArray);

		s_Storage->m_Texture->Unbind(0);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		FL_PROFILE_FUNCTION();

		s_Storage->m_Shader->SetMat4("u_Transformation.Model", glm::translate(glm::mat4(1.0f), position)
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		s_Storage->m_Shader->SetFloat4("u_Color", tintColor.r, tintColor.g, tintColor.b, tintColor.a);
		s_Storage->m_Shader->SetFloat("u_TilingFactor", 1.0f);

		texture->Bind(0);

		s_Storage->m_VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->m_VertexArray);

		texture->Unbind(0);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		FL_PROFILE_FUNCTION();

		s_Storage->m_Shader->SetMat4("u_Transformation.Model", glm::translate(glm::mat4(1.0f), position)
			* glm::rotate(glm::mat4(1.0f), counterclockwiseRadians, glm::vec3(0.0f, 0.0f, 1.0f))
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		s_Storage->m_Shader->SetFloat4("u_Color", tintColor.r, tintColor.g, tintColor.b, tintColor.a);
		s_Storage->m_Shader->SetFloat("u_TilingFactor", 1.0f);

		texture->Bind(0);

		s_Storage->m_VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->m_VertexArray);

		texture->Unbind(0);
	}


	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		FL_PROFILE_FUNCTION();

		s_Storage->m_Shader->SetMat4("u_Transformation.Model", glm::translate(glm::mat4(1.0f), position)
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		s_Storage->m_Shader->SetFloat4("u_Color", tintColor.r, tintColor.g, tintColor.b, tintColor.a);
		s_Storage->m_Shader->SetFloat("u_TilingFactor", tilingFactor);

		texture->Bind(0);

		s_Storage->m_VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->m_VertexArray);

		texture->Unbind(0);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		FL_PROFILE_FUNCTION();

		s_Storage->m_Shader->SetMat4("u_Transformation.Model", glm::translate(glm::mat4(1.0f), position)
			* glm::rotate(glm::mat4(1.0f), counterclockwiseRadians, glm::vec3(0.0f, 0.0f, 1.0f))
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		s_Storage->m_Shader->SetFloat4("u_Color", tintColor.r, tintColor.g, tintColor.b, tintColor.a);
		s_Storage->m_Shader->SetFloat("u_TilingFactor", tilingFactor);

		texture->Bind(0);

		s_Storage->m_VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->m_VertexArray);

		texture->Unbind(0);
	}
}