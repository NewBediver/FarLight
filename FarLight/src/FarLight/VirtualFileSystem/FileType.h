#pragma once

#include <string>

namespace FarLight
{
    enum class FileType
    {
        Unknown = 0,
        Configuration,
        VertexShader,
        FragmentShader,
        Image
    };

    std::string GetFileExtension(const std::string& path) noexcept;
    FileType GetFileType(const std::string& path) noexcept;
}
