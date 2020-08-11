#pragma once

#include "FarLight/RenderSystem/Shader/Shader.h"

#include <glad/glad.h>

#include <unordered_map>

namespace FarLight
{
	class OpenGLShader final
		: public Shader
	{
	public:
		OpenGLShader(const OpenGLShader&) = delete;
		OpenGLShader(OpenGLShader&&) = delete;
		OpenGLShader& operator=(const OpenGLShader&) = delete;
		OpenGLShader& operator=(OpenGLShader&&) = delete;

		explicit OpenGLShader(const std::string& vertexPath, const std::string& fragmentPath) noexcept;

		virtual ~OpenGLShader() noexcept;

		virtual void Bind() const noexcept override;
		virtual void Unbind() const noexcept override;

		virtual unsigned GetID() const noexcept override { return m_RendererID; }

		virtual void SetInt(const std::string& name, int i1) const noexcept override;

		virtual void SetIntArray(const std::string& name, const int* values, unsigned count) const noexcept override;

		virtual void SetFloat(const std::string& name, float f1) const noexcept override;
		virtual void SetFloat2(const std::string& name, float f1, float f2) const noexcept override;
		virtual void SetFloat3(const std::string& name, float f1, float f2, float f3) const noexcept override;
		virtual void SetFloat4(const std::string& name, float f1, float f2, float f3, float f4) const noexcept override;

		virtual void SetMat3(const std::string& name, const glm::mat3& matrix) const noexcept override;
		virtual void SetMat4(const std::string& name, const glm::mat4& matrix) const noexcept override;

	private:
		GLint GetUniformLocation(const std::string& name) const noexcept;

		std::string RetrieveShaderCodeFromFile(const std::string& path) const noexcept;
		GLuint CreateCompileShader(const std::string& code, const GLuint shaderType) const noexcept;
		GLuint LinkShaders(GLuint vertexShaderID, GLuint fragmentShaderID) const noexcept;
		std::vector<GLchar> GetErrorMessageFromGlad(GLuint program) const noexcept;

		unsigned m_RendererID;
		mutable std::unordered_map<std::string, GLint> m_UniformLocation;
	};
}