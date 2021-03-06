#pragma once

#include <glm/glm.hpp>

namespace FarLight
{
    enum class ShaderDataType
    {
        None = 0,
        Float, Float2, Float3, Float4,
        Mat3, Mat4,
        Int, Int2, Int3, Int4,
        Bool
    };

    static constexpr
        unsigned ShaderDataTypeSize(ShaderDataType type)
    {
        switch (type)
        {
            case ShaderDataType::Float:  return sizeof(float);
            case ShaderDataType::Float2: return 2 * sizeof(float);
            case ShaderDataType::Float3: return 3 * sizeof(float);
            case ShaderDataType::Float4: return 4 * sizeof(float);
            case ShaderDataType::Mat3:   return 3 * ShaderDataTypeSize(ShaderDataType::Float3);
            case ShaderDataType::Mat4:   return 4 * ShaderDataTypeSize(ShaderDataType::Float4);
            case ShaderDataType::Int:    return sizeof(int);
            case ShaderDataType::Int2:   return 2 * sizeof(int);
            case ShaderDataType::Int3:   return 3 * sizeof(int);
            case ShaderDataType::Int4:   return 4 * sizeof(int);
            case ShaderDataType::Bool:   return sizeof(bool);
        }

        FL_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
    }

    static constexpr
        unsigned ShaderDataTypeCount(ShaderDataType type)
    {
        switch (type)
        {
            case ShaderDataType::Float:  return 1;
            case ShaderDataType::Float2: return 2;
            case ShaderDataType::Float3: return 3;
            case ShaderDataType::Float4: return 4;
            case ShaderDataType::Mat3:   return 3 * ShaderDataTypeCount(ShaderDataType::Float3);
            case ShaderDataType::Mat4:   return 4 * ShaderDataTypeCount(ShaderDataType::Float4);
            case ShaderDataType::Int:    return 1;
            case ShaderDataType::Int2:   return 2;
            case ShaderDataType::Int3:   return 3;
            case ShaderDataType::Int4:   return 4;
            case ShaderDataType::Bool:   return 1;
        }

        FL_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
    }

    class Shader
    {
    public:
        static Ref<Shader> Create(const std::string& vertexSrc, const std::string& fragmentSrc) noexcept;

        virtual ~Shader() noexcept = default;

        virtual void Bind() const noexcept = 0;
        virtual void Unbind() const noexcept = 0;

        virtual unsigned GetID() const noexcept = 0;

        virtual void SetInt(const std::string& name, int i1) const noexcept = 0;

        virtual void SetIntArray(const std::string& name, const int* values, unsigned count) const noexcept = 0;

        virtual void SetFloat(const std::string& name, float f1) const noexcept = 0;
        virtual void SetFloat2(const std::string& name, float f1, float f2) const noexcept = 0;
        virtual void SetFloat3(const std::string& name, float f1, float f2, float f3) const noexcept = 0;
        virtual void SetFloat4(const std::string& name, float f1, float f2, float f3, float f4) const noexcept = 0;

        virtual void SetMat3(const std::string& name, const glm::mat3& matrix) const noexcept = 0;
        virtual void SetMat4(const std::string& name, const glm::mat4& matrix) const noexcept = 0;
    };
}
