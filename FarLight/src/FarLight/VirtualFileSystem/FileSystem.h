#pragma once

#include <string>
#include <unordered_map>

#include "FarLight/Abstraction/Singleton/Singleton.h"

#include "FarLight/Core/Core.h"

#include "FarLight/VirtualFileSystem/Settings/Settings.h"

#include "FarLight/SerializationSystem/Serialization.h"


namespace FarLight
{
    class FileSystem final
        : public Singleton<FileSystem>
    {
        friend class Singleton<FileSystem>;

    public:
        bool IsFileExists(const std::string& name) const noexcept;
        void CreateEmptyFile(const std::string& name, const std::string& path) noexcept;
        const std::string& GetFile(const std::string& name) const noexcept;

        bool IsDirectoryExists(const std::string& name) const noexcept;
        void CreateEmptyDirectory(const std::string& name, const std::string& path) noexcept;
        const std::string& GetDirectory(const std::string& name) const noexcept;

        template<typename T>
        bool WriteToDisk(T& obj, const std::string& filePath) noexcept
        {
            FL_PROFILE_FUNCTION();

            bool result = true;
            try
            {
                std::ofstream fs(filePath);
                FL_SERIALIZE_DATA(fs, obj);
            }
            catch (const std::exception& e)
            {
                result = false;
                FL_CORE_ERROR("An error occurred while attempting to serialize an object to disk.\nPath: {0}\nError: {1}", filePath, e.what());
            }
            return result;
        }

        template<typename T>
        T ReadFromDisk(const std::string& filePath) noexcept
        {
            FL_PROFILE_FUNCTION();

            T data;
            try
            {
                std::ifstream fs(filePath);
                FL_DESERIALIZE_DATA(fs, data);
            }
            catch (std::exception& e)
            {
                FL_CORE_ERROR("An error occurred while attempting to deserialize an object from disk.\nPath: {0}\nError: {1}", filePath, e.what());
            }
            return data;
        }

    private:
        explicit FileSystem() noexcept;

        void ReconstructDirectory(const std::string& name, const std::string& option, Settings& settings);

        mutable std::unordered_map<std::string, std::string> m_DirectoriesMap;
        mutable std::unordered_map<std::string, std::string> m_FilesMap;
    };
}
