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
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		void UploadUniformInt(const std::string& name, int i1) const;

		void UploadUniformFloat(const std::string& name, float f1) const;
		void UploadUniformFloat2(const std::string& name, float f1, float f2) const;
		void UploadUniformFloat3(const std::string& name, float f1, float f2, float f3) const;
		void UploadUniformFloat4(const std::string& name, float f1, float f2, float f3, float f4) const;

		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix) const;
		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix) const;

	private:
		GLint GetUniformLocation(const std::string& name) const;

		unsigned int _rendererID;
		mutable std::unordered_map<std::string, GLint> _uniformLocation;
	};
}