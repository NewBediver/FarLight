#pragma once

#include <vector>

#include "FarLight/RenderSystem/Shader/Shader.h"

namespace FarLight
{
	struct BufferElement
	{
		std::string m_Name;
		ShaderDataType m_Type;
		unsigned int m_Size;
		unsigned int m_Offset;
		bool m_Normalized;

		BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
			: m_Type(type)
			, m_Name(name)
			, m_Size(ShaderDataTypeSize(type))
			, m_Offset(0)
			, m_Normalized(normalized)
		{ }
	};

	class BufferLayout
	{
	public:
		BufferLayout(const std::initializer_list<BufferElement>& elements);

		unsigned int GetStride() const { return m_Stride; }
		const std::vector<BufferElement>& GetElements() const { return m_Elements; }

		std::vector<BufferElement>::const_iterator cbegin() const { return m_Elements.cbegin(); }
		std::vector<BufferElement>::const_iterator cend() const { return m_Elements.cend(); }

	private:
		std::vector<BufferElement> m_Elements;
		unsigned int m_Stride;
	};
}