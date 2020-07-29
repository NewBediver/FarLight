#pragma once

#include "FarLight/Core/Core.h"
#include "FarLight/LogSystem/Logger.h"

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

	static unsigned int ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::Float:  return sizeof(float);
			case ShaderDataType::Float2: return sizeof(float) * 2;
			case ShaderDataType::Float3: return sizeof(float) * 3;
			case ShaderDataType::Float4: return sizeof(float) * 4;
			case ShaderDataType::Mat3:   return sizeof(float) * 3 * 3;
			case ShaderDataType::Mat4:   return sizeof(float) * 4 * 4;
			case ShaderDataType::Int:    return sizeof(int);
			case ShaderDataType::Int2:   return sizeof(int) * 2;
			case ShaderDataType::Int3:   return sizeof(int) * 3;
			case ShaderDataType::Int4:   return sizeof(int) * 4;
			case ShaderDataType::Bool:   return sizeof(bool);
		}

		FL_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	static unsigned int ShaderDataTypeCount(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::Float:  return 1;
			case ShaderDataType::Float2: return 2;
			case ShaderDataType::Float3: return 3;
			case ShaderDataType::Float4: return 4;
			case ShaderDataType::Mat3:   return 3 * 3;
			case ShaderDataType::Mat4:   return 4 * 4;
			case ShaderDataType::Int:    return 1;
			case ShaderDataType::Int2:   return 2;
			case ShaderDataType::Int3:   return 3;
			case ShaderDataType::Int4:   return 4;
			case ShaderDataType::Bool:   return 1;
		}

		FL_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	class FARLIGHT_API Shader
	{
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetInt(const std::string& name, const int i1) const = 0;

		virtual void SetFloat(const std::string& name, const float f1) const = 0;
		virtual void SetFloat2(const std::string& name, const float f1, const float f2) const = 0;
		virtual void SetFloat3(const std::string& name, const float f1, const float f2, const float f3) const = 0;
		virtual void SetFloat4(const std::string& name, const float f1, const float f2, const float f3, const float f4) const = 0;

		virtual void SetMat3(const std::string& name, const glm::mat3& matrix) const = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& matrix) const = 0;

		virtual ~Shader() = default;

		static Ref<Shader> Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};
}