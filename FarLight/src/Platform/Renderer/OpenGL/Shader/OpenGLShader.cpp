// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OpenGLShader.h"

#include <glm/gtc/type_ptr.hpp>

namespace FarLight
{
	OpenGLShader::OpenGLShader(const std::string& vertexPath, const std::string& fragmentPath)
		: _rendererID(0)
	{
		std::string vertexCode = RetrieveShaderCodeFromFile(vertexPath);
		std::string fragmentCode = RetrieveShaderCodeFromFile(fragmentPath);
		
		GLuint vertexShader = CreateCompileShader(vertexCode, GL_VERTEX_SHADER);
		GLuint fragmentShader = CreateCompileShader(fragmentCode, GL_FRAGMENT_SHADER);

		_rendererID = LinkShaders(vertexShader, fragmentShader);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(_rendererID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(_rendererID);

	}
	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	void OpenGLShader::SetInt(const std::string& name, const int i1) const
	{
		glUniform1i(GetUniformLocation(name), i1);
	}

	void OpenGLShader::SetFloat(const std::string& name, const float f1) const
	{
		glUniform1f(GetUniformLocation(name), f1);
	}

	void OpenGLShader::SetFloat2(const std::string& name, const float f1, const float f2) const
	{
		glUniform2f(GetUniformLocation(name), f1, f2);
	}

	void OpenGLShader::SetFloat3(const std::string& name, const float f1, const float f2, const float f3) const
	{
		glUniform3f(GetUniformLocation(name), f1, f2, f3);
	}

	void OpenGLShader::SetFloat4(const std::string& name, const float f1, const float f2, const float f3, const float f4) const
	{
		glUniform4f(GetUniformLocation(name), f1, f2, f3, f4);
	}

	void OpenGLShader::SetMat3(const std::string& name, const glm::mat3& matrix) const
	{
		glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
	}

	void OpenGLShader::SetMat4(const std::string& name, const glm::mat4& matrix) const
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
	}

	const GLint OpenGLShader::GetUniformLocation(const std::string& name) const
	{
		if (_uniformLocation.find(name) == _uniformLocation.end())
			_uniformLocation[name] = glGetUniformLocation(_rendererID, name.c_str());
		return _uniformLocation[name];
	}

	const std::string OpenGLShader::RetrieveShaderCodeFromFile(const std::string& path) const
	{
		std::string code;
		std::ifstream shaderFile;
		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			shaderFile.open(path);
			std::stringstream shaderStream;
			shaderStream << shaderFile.rdbuf();
			shaderFile.close();
			code = shaderStream.str();
		}
		catch (const std::ifstream::failure& e)
		{
			FL_CORE_ERROR("Shader program retrieving error: {0}", path);
			FL_CORE_ERROR("Error massage: {0}", e.what());
			FL_CORE_ASSERT(false, "Critical error in shader retrieving!");
		}
		return code;
	}

	const GLuint OpenGLShader::CreateCompileShader(const std::string& code, const GLuint shaderType) const
	{
		GLuint shader = glCreateShader(shaderType);

		const GLchar* source = code.c_str();
		glShaderSource(shader, 1, &source, 0);

		glCompileShader(shader);

		GLint isCompiled = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			glDeleteShader(shader);

			FL_CORE_ERROR("Shader compilation error: {0}", shader);
			FL_CORE_ERROR("{0}", GetErrorMessageFromGlad(shader).data());
			FL_CORE_ASSERT(false, "Critical error in shader compilation!");

			return -1;
		}

		return shader;
	}

	const GLuint OpenGLShader::LinkShaders(GLuint vertexShaderID, GLuint fragmentShaderID) const
	{
		GLuint program = glCreateProgram();

		glAttachShader(program, vertexShaderID);
		glAttachShader(program, fragmentShaderID);

		glLinkProgram(program);

		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			glDeleteProgram(program);
			
			glDeleteShader(vertexShaderID);
			glDeleteShader(fragmentShaderID);

			FL_CORE_ERROR("Shader program linking error: {0}", program);
			FL_CORE_ERROR("{0}", GetErrorMessageFromGlad(program).data());
			FL_CORE_ASSERT(false, "Critical error in shader program linking!");

			return -1;
		}

		glDetachShader(program, vertexShaderID);
		glDeleteShader(vertexShaderID);

		glDetachShader(program, fragmentShaderID);
		glDeleteShader(fragmentShaderID);

		return program;
	}
	const std::vector<GLchar> OpenGLShader::GetErrorMessageFromGlad(const GLuint program) const
	{
		GLint maxLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

		return infoLog;
	}
}