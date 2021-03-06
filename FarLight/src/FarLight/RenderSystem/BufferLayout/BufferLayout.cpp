// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/RenderSystem/BufferLayout/BufferLayout.h"

namespace FarLight
{
    BufferLayout::BufferLayout(const std::initializer_list<BufferElement>& elements) noexcept
        : m_Elements(elements)
        , m_Stride(0)
        , m_Count(0)
    {
        unsigned offset = 0;
        for (auto& element : m_Elements)
        {
            element.Offset = offset;
            offset += element.Size;
            m_Stride += element.Size;
            m_Count += ShaderDataTypeCount(element.Type);
        }
    }
}
