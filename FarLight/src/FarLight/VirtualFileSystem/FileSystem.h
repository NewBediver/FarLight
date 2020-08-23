#pragma once

#include <filesystem>

#include "Directory.h"

namespace FarLight
{
	class FileSystem final
	{
	public:
		FileSystem() = delete;
		FileSystem(const FileSystem&) = delete;
		FileSystem(FileSystem&&) = delete;
		FileSystem& operator=(const FileSystem&) = delete;
		FileSystem& operator=(FileSystem&&) = delete;

		static Directory& GetProjectDirectory() noexcept;

		static Directory& GetAssetsDirectory() noexcept;
		static Directory& GetEditorDirectory() noexcept;
		static Directory& GetResourcesDirectory() noexcept;
	};
}