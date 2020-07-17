#pragma once

#include "FarLight/RenderSystem/Shader/Shader.h"

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

		virtual void UploadUnoformMat4(const std::string& name, const glm::mat4& matrix) const override;

	private:
		unsigned int _rendererID;
	};
}