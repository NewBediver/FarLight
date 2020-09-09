#pragma once

#include <string>

#include "FarLight/Core/Core.h"

#include <cereal/archives/binary.hpp>

namespace FarLight
{
    class FileSystem
    {
    public:
        FileSystem(const FileSystem&) = delete;
        FileSystem(FileSystem&&) = delete;
        FileSystem& operator=(const FileSystem&) = delete;
        FileSystem& operator=(FileSystem&&) = delete;

        static FileSystem& GetInstance() noexcept
        {
            static FileSystem s_Instance;
            return s_Instance;
        }

    private:
        explicit FileSystem() noexcept = default;
    };
}
