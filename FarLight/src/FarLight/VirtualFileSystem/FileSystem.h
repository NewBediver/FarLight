#pragma once

#include <string>

#include "FarLight/Core/Core.h"

#include "FarLight/SerializationSystem/Serialization.h"

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

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

        void Initialize() const noexcept;

        std::string GetRootDirectory() const noexcept { return m_RootDirectory; }

        std::string GetAssetsDirectory() const noexcept { return m_AssetsDirectory; }

        std::string GetEditorDirectory() const noexcept { return m_EditorDirectory; }
        std::string GetResourcesDirectory() const noexcept { return m_ResourcesDirectory; }

        std::string GetShadersDirectory() const noexcept { return m_ShadersDirectory; }

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
        explicit FileSystem() noexcept
            : m_RootDirectory(fs::current_path().string())
        {
            m_AssetsDirectory = m_RootDirectory + "\\Assets";

            m_EditorDirectory = m_AssetsDirectory + "\\Editor";
            m_ResourcesDirectory = m_AssetsDirectory + "\\Resources";

            m_ShadersDirectory = m_ResourcesDirectory + "\\Shaders";
        }

        void DirectoryInitialization(const std::string& dir) const noexcept;

        void LoadShaders(const std::string& dir) const noexcept;
        void LoadShader(const std::string& pathToVert) const noexcept;

        std::string m_RootDirectory;
        std::string m_AssetsDirectory;
        std::string m_EditorDirectory;
        std::string m_ResourcesDirectory;
        std::string m_ShadersDirectory;
    };
}
