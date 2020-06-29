workspace "FarLight"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "FarLight/vendor/GLFW/include"
IncludeDir["spdlog"] = "FarLight/vendor/spdlog/include"
IncludeDir["GoogleTest"] = "FarLightTests/vendor/googletest/googletest/include"

IncludeDir["FarLightSrc"] = "FarLight/src"

include "FarLight/vendor/GLFW"
include "FarLightTests/vendor/googletest"

project "FarLight"
	location "FarLight"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "flpch.h"
	pchsource "FarLight/src/flpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{IncludeDir.FarLightSrc}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"FL_PLATFORM_WINDOWS",
			"FL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/FarLightTests")
		}

	filter "configurations:Debug"
		defines 
		{
			"FL_DEBUG",
			"FL_ENABLE_ASSERTS"
		}
		symbols "On"

	filter "configurations:Release"
		defines "FL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{IncludeDir.FarLightSrc}",
		"%{IncludeDir.spdlog}"
	}

	links
	{
		"FarLight"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"FL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FL_DIST"
		optimize "On"

project "FarLightTests"
	location "FarLightTests"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{IncludeDir.FarLightSrc}",
		"%{IncludeDir.GoogleTest}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GoogleTestsCompilation",
		"FarLight"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"FL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"