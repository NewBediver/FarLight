// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/VirtualFileSystem/FileType.h"

namespace FarLight
{
    std::string GetFileExtension(const std::string& path) noexcept
    {
        FL_PROFILE_FUNCTION()

        int periodIndex;
        for (periodIndex = path.length()-1; periodIndex >= 0; --periodIndex)
        {
            if (path[periodIndex] == '.')
            {
                ++periodIndex;
                break;
            }
        }

        if (periodIndex == -1) return "";

        std::string ext = path.substr(periodIndex);
        std::transform(ext.begin(), ext.end(), ext.begin(), [](char c) -> char
            {
                if (c >= 'A' && c <= 'Z') return c ^ 0x20;
                return c;
            });
        return ext;
    }

    FileType GetFileType(const std::string& path) noexcept
    {
        FL_PROFILE_FUNCTION();

        std::string extension = GetFileExtension(path);
        if (extension == "cfg")
            return FileType::Configuration;
        else if (extension == "bmp" || extension == "tga" || extension == "png" || extension == "jpg" || extension == "jpeg")
            return FileType::Image;
        else if (extension == "vert")
            return FileType::VertexShader;
        else if (extension == "frag")
            return FileType::FragmentShader;
        else
            return FileType::Unknown;
    }
}
