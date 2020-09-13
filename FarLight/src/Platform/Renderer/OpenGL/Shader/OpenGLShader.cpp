// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

#include <glm/gtc/type_ptr.hpp>

namespace FarLight
{
    OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc) noexcept
        : m_RendererID(0)
    {
        FL_PROFILE_FUNCTION();

        std::string vertexCode = RetrieveShaderCodeFromFile(vertexSrc);
        std::string fragmentCode = RetrieveShaderCodeFromFile(fragmentSrc);

        GLuint vertexShader = CreateCompileShader(vertexCode, GL_VERTEX_SHADER);
        GLuint fragmentShader = CreateCompileShader(fragmentCode, GL_FRAGMENT_SHADER);

        /*GLuint vertexShader = CreateCompileShader(vertexSrc, GL_VERTEX_SHADER);
        GLuint fragmentShader = CreateCompileShader(fragmentSrc, GL_FRAGMENT_SHADER);*/

        m_RendererID = LinkShaders(vertexShader, fragmentShader);
    }

    OpenGLShader::~OpenGLShader() noexcept
    {
        FL_PROFILE_FUNCTION();

        glDeleteProgram(m_RendererID);
    }

    void OpenGLShader::Bind() const noexcept
    {
        FL_PROFILE_FUNCTION();

        glUseProgram(m_RendererID);

    }

    void OpenGLShader::Unbind() const noexcept
    {
        FL_PROFILE_FUNCTION();

        glUseProgram(0);
    }

    void OpenGLShader::SetInt(const std::string& name, int i1) const noexcept
    {
        FL_PROFILE_FUNCTION();

        glUniform1i(GetUniformLocation(name), i1);
    }

    void OpenGLShader::SetIntArray(const std::string& name, const int* values, unsigned count) const noexcept
    {
        FL_PROFILE_FUNCTION();

        glUniform1iv(GetUniformLocation(name), count, values);
    }

    void OpenGLShader::SetFloat(const std::string& name, float f1) const noexcept
    {
        FL_PROFILE_FUNCTION();

        glUniform1f(GetUniformLocation(name), f1);
    }

    void OpenGLShader::SetFloat2(const std::string& name, float f1, float f2) const noexcept
    {
        FL_PROFILE_FUNCTION();

        glUniform2f(GetUniformLocation(name), f1, f2);
    }

    void OpenGLShader::SetFloat3(const std::string& name, float f1, float f2, float f3) const noexcept
    {
        FL_PROFILE_FUNCTION();

        glUniform3f(GetUniformLocation(name), f1, f2, f3);
    }

    void OpenGLShader::SetFloat4(const std::string& name, float f1, float f2, float f3, float f4) const noexcept
    {
        FL_PROFILE_FUNCTION();

        glUniform4f(GetUniformLocation(name), f1, f2, f3, f4);
    }

    void OpenGLShader::SetMat3(const std::string& name, const glm::mat3& matrix) const noexcept
    {
        FL_PROFILE_FUNCTION();

        glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::SetMat4(const std::string& name, const glm::mat4& matrix) const noexcept
    {
        FL_PROFILE_FUNCTION();

        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
    }

    GLint OpenGLShader::GetUniformLocation(const std::string& name) const noexcept
    {
        FL_PROFILE_FUNCTION();

        if (m_UniformLocation.find(name) == m_UniformLocation.end())
            m_UniformLocation[name] = glGetUniformLocation(m_RendererID, name.c_str());
        return m_UniformLocation[name];
    }

    std::string OpenGLShader::RetrieveShaderCodeFromFile(const std::string& path) const noexcept
    {
        FL_PROFILE_FUNCTION();

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

    GLuint OpenGLShader::CreateCompileShader(const std::string& code, const GLuint shaderType) const noexcept
    {
        FL_PROFILE_FUNCTION();

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

    GLuint OpenGLShader::LinkShaders(GLuint vertexShaderID, GLuint fragmentShaderID) const noexcept
    {
        FL_PROFILE_FUNCTION();

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

    std::vector<GLchar> OpenGLShader::GetErrorMessageFromGlad(GLuint program) const noexcept
    {
        GLint maxLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

        return infoLog;
    }
}
