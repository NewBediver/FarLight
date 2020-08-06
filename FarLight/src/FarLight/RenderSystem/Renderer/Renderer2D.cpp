// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Renderer2D.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

namespace FarLight
{
	Scope<Renderer2D::QuadVertexData> Renderer2D::s_QuadData = CreateScope<QuadVertexData>();
	Scope<Batch> Renderer2D::s_Batch = nullptr;

	void Renderer2D::Init()
	{
		FL_PROFILE_FUNCTION();

		RenderCommand::Init();
		FL_CORE_INFO("[Renderer2D] initialized.");

		s_QuadData->PosLowerRight = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f);
		s_QuadData->PosUpperRight = glm::vec4(0.5f, 0.5f, 0.0f, 1.0f);
		s_QuadData->PosUpperLeft = glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f);
		s_QuadData->PosLowerLeft = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f);
		s_QuadData->Indices[0] = 0;
		s_QuadData->Indices[1] = 1;
		s_QuadData->Indices[2] = 2;
		s_QuadData->Indices[3] = 2;
		s_QuadData->Indices[4] = 3;
		s_QuadData->Indices[5] = 0;

		s_Batch = CreateScope<Batch>(1000
			, 1500
			, BufferLayout({
				{ ShaderDataType::Float3, "a_Position" },
				{ ShaderDataType::Float4, "a_Color" },
				{ ShaderDataType::Float2, "a_TextureCoordinates" }
			})
			, Shader::Create("assets/shaders/DefaultSquare/DefaultSquareShader.vert", "assets/shaders/DefaultSquare/DefaultSquareShader.frag")
			, Texture2D::Create(1, 1));
	}

	void Renderer2D::Shutdown()
	{
		FL_PROFILE_FUNCTION();

		s_Batch.reset();
		s_QuadData.reset();

		FL_CORE_INFO("[Renderer2D] terminated.");
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		FL_PROFILE_FUNCTION();

		s_Batch->SetViewProjection(camera.GetViewMatrix(), camera.GetProjectionMatrix());
		s_Batch->SetTextureSlot(0);
	}

	void Renderer2D::EndScene()
	{
		FL_PROFILE_FUNCTION();

		s_Batch->Render();
		s_Batch->Clear();
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{
		FL_PROFILE_FUNCTION();

		glm::mat4 transformation = glm::translate(glm::mat4(1.0f), position)
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f));

		glm::vec4 posLowerRight = transformation * s_QuadData->PosLowerRight;
		glm::vec4 posUpperRight = transformation * s_QuadData->PosUpperRight;
		glm::vec4 posUpperLeft = transformation * s_QuadData->PosUpperLeft;
		glm::vec4 posLowerLeft = transformation * s_QuadData->PosLowerLeft;

		float squareVertices[4 * 9] =
		{
			// position                                           // color                               // textures
			posLowerRight.x, posLowerRight.y, posLowerRight.z,    color.r, color.g, color.b, color.a,    1.0f, 0.0f,
			posUpperRight.x, posUpperRight.y, posUpperRight.z,    color.r, color.g, color.b, color.a,    1.0f, 1.0f,
			posUpperLeft.x,  posUpperLeft.y,  posUpperLeft.z,     color.r, color.g, color.b, color.a,    0.0f, 1.0f,
			posLowerLeft.x,  posLowerLeft.y,  posLowerLeft.z,     color.r, color.g, color.b, color.a,    0.0f, 0.0f
		};

		unsigned int squareIndices[6];
		for (int i = 0; i < 6; ++i) squareIndices[i] = s_QuadData->Indices[i];

		s_Batch->AddData(4, squareVertices, 6, squareIndices);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color)
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, color);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const glm::vec4& color)
	{
		FL_PROFILE_FUNCTION();

		glm::mat4 transformation = glm::translate(glm::mat4(1.0f), position)
			* glm::rotate(glm::mat4(1.0f), counterclockwiseRadians, glm::vec3(0.0f, 0.0f, 1.0f))
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f));

		glm::vec4 posLowerRight = transformation * s_QuadData->PosLowerRight;
		glm::vec4 posUpperRight = transformation * s_QuadData->PosUpperRight;
		glm::vec4 posUpperLeft = transformation * s_QuadData->PosUpperLeft;
		glm::vec4 posLowerLeft = transformation * s_QuadData->PosLowerLeft;

		float squareVertices[4 * 9] =
		{
			// position                                           // color                               // textures
			posLowerRight.x, posLowerRight.y, posLowerRight.z,    color.r, color.g, color.b, color.a,    1.0f, 0.0f,
			posUpperRight.x, posUpperRight.y, posUpperRight.z,    color.r, color.g, color.b, color.a,    1.0f, 1.0f,
			posUpperLeft.x,  posUpperLeft.y,  posUpperLeft.z,     color.r, color.g, color.b, color.a,    0.0f, 1.0f,
			posLowerLeft.x,  posLowerLeft.y,  posLowerLeft.z,     color.r, color.g, color.b, color.a,    0.0f, 0.0f
		};

		unsigned int squareIndices[6];
		for (int i = 0; i < 6; ++i) squareIndices[i] = s_QuadData->Indices[i];

		s_Batch->AddData(4, squareVertices, 6, squareIndices);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		FL_PROFILE_FUNCTION();

		/*s_Storage->Shader->SetMat4("u_Transformation.Model", glm::translate(glm::mat4(1.0f), position)
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		s_Storage->Shader->SetFloat4("u_Color", tintColor.r, tintColor.g, tintColor.b, tintColor.a);
		s_Storage->Shader->SetFloat("u_TilingFactor", 1.0f);

		texture->Bind(0);

		s_Storage->VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->VertexArray);

		texture->Unbind(0);*/
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, const glm::vec4& tintColor)
	{
		FL_PROFILE_FUNCTION();

		/*s_Storage->Shader->SetMat4("u_Transformation.Model", glm::translate(glm::mat4(1.0f), position)
			* glm::rotate(glm::mat4(1.0f), counterclockwiseRadians, glm::vec3(0.0f, 0.0f, 1.0f))
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		s_Storage->Shader->SetFloat4("u_Color", tintColor.r, tintColor.g, tintColor.b, tintColor.a);
		s_Storage->Shader->SetFloat("u_TilingFactor", 1.0f);

		texture->Bind(0);

		s_Storage->VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->VertexArray);

		texture->Unbind(0);*/
	}


	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		FL_PROFILE_FUNCTION();

		/*s_Storage->Shader->SetMat4("u_Transformation.Model", glm::translate(glm::mat4(1.0f), position)
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		s_Storage->Shader->SetFloat4("u_Color", tintColor.r, tintColor.g, tintColor.b, tintColor.a);
		s_Storage->Shader->SetFloat("u_TilingFactor", tilingFactor);

		texture->Bind(0);

		s_Storage->VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->VertexArray);

		texture->Unbind(0);*/
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		DrawRotatedQuad({ position.x, position.y, 0.0f }, size, counterclockwiseRadians, texture, tilingFactor, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float counterclockwiseRadians, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		FL_PROFILE_FUNCTION();

		/*s_Storage->Shader->SetMat4("u_Transformation.Model", glm::translate(glm::mat4(1.0f), position)
			* glm::rotate(glm::mat4(1.0f), counterclockwiseRadians, glm::vec3(0.0f, 0.0f, 1.0f))
			* glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f)));
		s_Storage->Shader->SetFloat4("u_Color", tintColor.r, tintColor.g, tintColor.b, tintColor.a);
		s_Storage->Shader->SetFloat("u_TilingFactor", tilingFactor);

		texture->Bind(0);

		s_Storage->VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->VertexArray);

		texture->Unbind(0);*/
	}
}