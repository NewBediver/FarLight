#pragma once

#include <vector>

#include "FarLight/RenderSystem/Shader/Shader.h"

namespace FarLight
{
	struct FARLIGHT_API BufferElement
	{
		std::string Name;
		ShaderDataType Type;
		unsigned int Size;
		unsigned int Offset;
		bool Normalized;

		BufferElement(const ShaderDataType type, const std::string& name, const bool normalized = false)
			: Type(type), Name(name), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized) { }
	};

	class FARLIGHT_API BufferLayout
	{
	public:
		BufferLayout(const std::initializer_list<BufferElement>& elements);

		const unsigned int GetStride() const { return _stride; }
		const std::vector<BufferElement>& GetElements() const { return _elements; }

		std::vector<BufferElement>::const_iterator cbegin() const { return _elements.cbegin(); }
		std::vector<BufferElement>::const_iterator cend() const { return _elements.cend(); }

	private:
		void CalculateOffsetAndStride();

		std::vector<BufferElement> _elements;
		unsigned int _stride;
	};
}