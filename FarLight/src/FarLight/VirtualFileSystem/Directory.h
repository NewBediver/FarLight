#pragma once

#include <filesystem>
#include <map>

namespace FarLight
{
    class Directory
    {
    public:
        Directory() = default;
        explicit Directory(Directory& parent, const std::string& relativePath) noexcept;

        bool IsExists() const noexcept { return std::filesystem::directory_entry(m_AbsolutePath).exists(); }
        bool IsExists(const std::string& name) const noexcept { return m_DirectoryMap.find(name) != m_DirectoryMap.end() && m_DirectoryMap.at(name).IsExists(); }

        void Create() noexcept;
        Directory& Create(const std::string& relativeName) noexcept;

        Directory& GetDirectory(const std::string& relativeName) noexcept;

        const std::string& GetAbsolutePath() const noexcept { return m_AbsolutePath; }
        const std::string& GetRelativePath() const noexcept { return m_RelativePath; }

        const Directory* GetParent() const noexcept { return m_ParentDirectory; }
        std::map<std::string, Directory>& GetDirectoryMap() noexcept;

    private:
        explicit Directory(const std::string& absolutePath) noexcept;

        constexpr bool IsResolvedContent() const noexcept { return m_IsResolvedContent; }
        constexpr void SetResolvedContent(bool status) noexcept { m_IsResolvedContent = status; }

        void ResolveContent() noexcept;

        std::string m_AbsolutePath;
        std::string m_RelativePath;

        Directory* m_ParentDirectory;

        bool m_IsResolvedContent;
        std::map<std::string, Directory> m_DirectoryMap;
        //std::unordered_map<std::string, Asset> m_AssetsMap;

        friend class FileSystem;
    };
}
