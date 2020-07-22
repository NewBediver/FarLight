#pragma once

#include "FarLight/RenderSystem/Shader/Shader.h"

#include <glad/glad.h>

#include <unordered_map>

namespace FarLight
{
	class FARLIGHT_API OpenGLShader
		: public Shader
	{
	public:
		OpenGLShader(const std::string& vertexPath, const std::string& fragmentPath);

		virtual void Bind() const override;
		virtual void Unbind() const override;

		void UploadUniformInt(const std::string& name, const int i1) const;

		void UploadUniformFloat(const std::string& name, const float f1) const;
		void UploadUniformFloat2(const std::string& name, const float f1, const float f2) const;
		void UploadUniformFloat3(const std::string& name, const float f1, const float f2, const float f3) const;
		void UploadUniformFloat4(const std::string& name, const float f1, const float f2, const float f3, const float f4) const;

		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix) const;
		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix) const;

		virtual ~OpenGLShader();

	private:
		const GLint GetUniformLocation(const std::string& name) const;

		const std::string RetrieveShaderCodeFromFile(const std::string& path) const;
		const GLuint CreateCompileShader(const std::string& code, const GLuint shaderType) const;
		const GLuint LinkShaders(GLuint vertexShaderID, GLuint fragmentShaderID) const;
		const std::vector<GLchar> GetErrorMessageFromGlad(const GLuint program) const;

		unsigned int _rendererID;
		mutable std::unordered_map<std::string, GLint> _uniformLocation;
	};
}