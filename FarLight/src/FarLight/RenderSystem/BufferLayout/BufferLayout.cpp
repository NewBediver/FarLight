#include "flpch.h"

#include "BufferLayout.h"

namespace FarLight
{
	BufferLayout::BufferLayout(const std::initializer_list<BufferElement>& elements)
		: _elements(elements), _stride(0)
	{
		CalculateOffsetAndStride();
	}

	void BufferLayout::CalculateOffsetAndStride()
	{
		unsigned int offset = 0;
		_stride = 0;
		for (auto& element : _elements)
		{
			element.Offset = offset;
			offset += element.Size;
			_stride += element.Size;
		}
	}
}