// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Directory.h"

#include "FarLight/Core/Core.h"

namespace FarLight
{
	

	Directory::Directory(const std::string& absolutePath) noexcept
		: m_AbsolutePath(absolutePath)
		, m_RelativePath("")
		, m_ParentDirectory(nullptr)
		, m_IsResolvedContent(false)
	{
		FL_CORE_ASSERT(!absolutePath.empty(), "Specified path cannot be empty!");

		if (!IsExists())
			Create();
	}

	Directory::Directory(Directory& parent, const std::string& relativePath) noexcept
		: m_ParentDirectory(&parent)
		, m_RelativePath(relativePath)
		, m_AbsolutePath(parent.GetAbsolutePath() + "/" + relativePath)
		, m_IsResolvedContent(false)
	{
		FL_CORE_ASSERT(std::find(relativePath.begin(), relativePath.end(), '/') == relativePath.end(), "Specified path is not relative to current node!");

		if (!IsExists())
			Create();
	}

	void Directory::Create() noexcept
	{
		SetResolvedContent(false);

		if (!std::filesystem::create_directory(m_AbsolutePath)) {
			FL_CORE_ASSERT(false, "Current directory cannot be created!");
		}
	}

	Directory& Directory::Create(const std::string& relativeName) noexcept
	{
		SetResolvedContent(false);

		FL_CORE_ASSERT(!relativeName.empty(), "Name cannot be empty!");
		FL_CORE_ASSERT(std::find(relativeName.begin(), relativeName.end(), '/') == relativeName.end(), "Specified path is not relative to current node!");
		FL_CORE_ASSERT(!IsExists(relativeName), "This directory already exists!");

		m_DirectoryMap.emplace(std::piecewise_construct, std::forward_as_tuple(relativeName), std::forward_as_tuple(*this, relativeName));
		return m_DirectoryMap[relativeName];
	}

	Directory& Directory::GetDirectory(const std::string& relativeName) noexcept
	{
		FL_CORE_ASSERT(!relativeName.empty(), "Name cannot be empty!");
		FL_CORE_ASSERT(std::find(relativeName.begin(), relativeName.end(), '/') == relativeName.end(), "Specified path is not relative to current node!");
		FL_CORE_ASSERT(IsExists(relativeName), "This directory is not exists!");

		return m_DirectoryMap[relativeName];
	}

	std::map<std::string, Directory>& Directory::GetDirectoryMap() noexcept
	{
		if (!IsResolvedContent())
			ResolveContent();
		return m_DirectoryMap;
	}

	void Directory::ResolveContent() noexcept
	{
		if (!IsResolvedContent())
		{
			for (auto& p : m_DirectoryMap)
			{
				p.second.ResolveContent();
			}
			std::filesystem::path path(m_AbsolutePath);
			for (const auto& node : std::filesystem::directory_iterator(path))
			{
				if (node.is_directory() && !IsExists(node.path().stem().string()))
				{
					Create(node.path().stem().string());
				}
			}
			SetResolvedContent(true);
		}
	}
}