#pragma once

#include "FarLight/RenderSystem/Shader/Shader.h"

#include <glad/glad.h>

#include <unordered_map>

namespace FarLight
{
	class OpenGLShader
		: public Shader
	{
	public:
		explicit OpenGLShader(const std::string& vertexPath, const std::string& fragmentPath);

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void SetInt(const std::string& name, int i1) const override;

		virtual void SetFloat(const std::string& name, float f1) const override;
		virtual void SetFloat2(const std::string& name, float f1, float f2) const override;
		virtual void SetFloat3(const std::string& name, float f1, float f2, float f3) const override;
		virtual void SetFloat4(const std::string& name, float f1, float f2, float f3, float f4) const override;

		virtual void SetMat3(const std::string& name, const glm::mat3& matrix) const override;
		virtual void SetMat4(const std::string& name, const glm::mat4& matrix) const override;

		virtual ~OpenGLShader();

	private:
		GLint GetUniformLocation(const std::string& name) const;

		std::string RetrieveShaderCodeFromFile(const std::string& path) const;
		GLuint CreateCompileShader(const std::string& code, const GLuint shaderType) const;
		GLuint LinkShaders(GLuint vertexShaderID, GLuint fragmentShaderID) const;
		std::vector<GLchar> GetErrorMessageFromGlad(GLuint program) const;

		unsigned int m_RendererID;
		mutable std::unordered_map<std::string, GLint> m_UniformLocation;
	};
}