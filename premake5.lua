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
IncludeDir["Glad"] = "FarLight/vendor/Glad/include"
IncludeDir["ImGui"] = "FarLight/vendor/ImGui"

IncludeDir["FarLightSrc"] = "FarLight/src"

include "FarLight/vendor/GLFW"
include "FarLightTests/vendor/googletest"
include "FarLight/vendor/Glad"
include "FarLight/vendor/ImGui"

project "FarLight"
	location "FarLight"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"FL_PLATFORM_WINDOWS",
			"FL_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
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
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "FL_RELEASE"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "FL_DIST"
		buildoptions "/MD"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		systemversion "latest"

		defines
		{
			"FL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FL_DEBUG"
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "FL_RELEASE"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "FL_DIST"
		buildoptions "/MD"
		optimize "on"

project "FarLightTests"
	location "FarLightTests"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		systemversion "latest"

		defines
		{
			"FL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		buildoptions "/MD"
		optimize "on"