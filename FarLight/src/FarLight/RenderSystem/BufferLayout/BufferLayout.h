#pragma once

#include <vector>

#include "FarLight/RenderSystem/Shader/Shader.h"

namespace FarLight
{
	struct BufferElement
	{
		std::string Name;
		ShaderDataType Type;
		unsigned int Size;
		unsigned int Offset;
		bool Normalized;

		BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
			: Type(type)
			, Name(name)
			, Size(ShaderDataTypeSize(type))
			, Offset(0)
			, Normalized(normalized)
		{ }

		bool operator==(const BufferElement& other) const
		{
			return Name == other.Name
				&& Type == other.Type
				&& Normalized == other.Normalized;
		}
	};

	class BufferLayout
	{
	public:
		BufferLayout(const std::initializer_list<BufferElement>& elements);

		unsigned int GetStride() const { return m_Stride; }
		unsigned int GetSize() const { return m_Elements.size(); }
		unsigned int GetDataSize() const { return GetStride(); }
		const std::vector<BufferElement>& GetElements() const { return m_Elements; }

		std::vector<BufferElement>::const_iterator cbegin() const { return m_Elements.cbegin(); }
		std::vector<BufferElement>::const_iterator cend() const { return m_Elements.cend(); }

		bool operator==(const BufferLayout& other) const
		{
			bool res = m_Stride == other.m_Stride;
			for (int i = 0; i < GetSize(); ++i) res &= m_Elements[i] == other.m_Elements[i];
			return res;
		}

	private:
		std::vector<BufferElement> m_Elements;
		unsigned int m_Stride;
	};
}