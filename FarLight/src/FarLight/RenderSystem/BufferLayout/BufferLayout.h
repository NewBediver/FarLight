#pragma once

#include <vector>

#include "FarLight/RenderSystem/Shader/Shader.h"

namespace FarLight
{
	struct BufferElement final
	{
		std::string Name;
		ShaderDataType Type;
		unsigned Size;
		unsigned Offset;
		bool Normalized;

		BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
			: Type(type)
			, Name(name)
			, Size(ShaderDataTypeSize(type))
			, Offset(0)
			, Normalized(normalized)
		{ }
	};

	class BufferLayout final
	{
	public:
		BufferLayout(const std::initializer_list<BufferElement>& elements);

		unsigned GetStride() const { return m_Stride; }
		unsigned GetSize() const { return static_cast<unsigned>(m_Elements.size()); }
		const std::vector<BufferElement>& GetElements() const { return m_Elements; }

		std::vector<BufferElement>::const_iterator cbegin() const { return m_Elements.cbegin(); }
		std::vector<BufferElement>::const_iterator cend() const { return m_Elements.cend(); }

	private:
		std::vector<BufferElement> m_Elements;
		unsigned m_Stride;
	};
}