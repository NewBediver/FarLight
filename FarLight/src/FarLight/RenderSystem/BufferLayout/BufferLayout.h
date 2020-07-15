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

		BufferElement() = default;
		BufferElement(ShaderDataType type, std::string name, bool normalized = false)
			: Type(type), Name(name), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized) { }
	};

	class FARLIGHT_API BufferLayout
	{
	public:
		BufferLayout() = default;
		BufferLayout(const std::initializer_list<BufferElement>& elements);

		unsigned int GetStride() const { return _stride; }
		const std::vector<BufferElement>& GetElements() const { return _elements; }

		std::vector<BufferElement>::iterator begin() { return _elements.begin(); }
		std::vector<BufferElement>::iterator end() { return _elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return _elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return _elements.end(); }

	private:
		void CalculateOffsetAndStride();

		std::vector<BufferElement> _elements;
		unsigned int _stride;
	};
}