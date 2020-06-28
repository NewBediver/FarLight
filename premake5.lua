workspace "FarLight"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
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
		defines "FL_DEBUG"
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
		"FarLight/vendor/spdlog/include",
		"FarLight/src"
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

project "GoogleTestsCompilation"
	location "GoogleTestsCompilation"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.cc"
	}

	includedirs
	{
		"%{prj.name}/vendor/googletest/googletest",
		"%{prj.name}/vendor/googletest/googletest/include"
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
		"GoogleTestsCompilation/vendor/googletest/googletest",
		"GoogleTestsCompilation/vendor/googletest/googletest/include",
		"FarLight/src"
	}

	libdirs
	{
		"../bin/" .. outputdir .. "/GoogleTestsCompilation"
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
		defines "FL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FL_DIST"
		optimize "On"