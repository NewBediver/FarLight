// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FileSystem.h"

namespace FarLight
{
	Directory& FileSystem::GetAssetsDirectory() noexcept
	{
		if (!GetProjectDirectory().IsExists("Assets"))
			GetProjectDirectory().Create("Assets");
		return GetProjectDirectory().GetDirectory("Assets");
	}

	Directory& FileSystem::GetEditorDirectory() noexcept
	{
		if (!GetProjectDirectory().IsExists("Editor"))
			GetProjectDirectory().Create("Editor");
		return GetProjectDirectory().GetDirectory("Editor");
	}

	Directory& FileSystem::GetResourcesDirectory() noexcept
	{
		if (!GetProjectDirectory().IsExists("Resources"))
			GetProjectDirectory().Create("Resources");
		return GetProjectDirectory().GetDirectory("Resources");
	}

	Directory& FileSystem::GetProjectDirectory() noexcept
	{
		static Directory s_ProjectDirectory(std::filesystem::current_path().string());
		if (!s_ProjectDirectory.IsExists())
			s_ProjectDirectory.Create();
		return s_ProjectDirectory;
	}
}