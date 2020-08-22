workspace "FarLight"
    architecture "x64"
    startproject "FarLightEditor"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    flags
	{
		"MultiProcessorCompile"
	}

outputObjDir = "%{wks.location}/bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
outputBinDir = "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"

IncludeDir = {}
IncludeDir["FarLight"] = "%{wks.location}/FarLight/src"
IncludeDir["GLFW"] = "%{wks.location}/FarLight/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/FarLight/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/FarLight/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/FarLight/vendor/glm"
IncludeDir["stb"] = "%{wks.location}/FarLight/vendor/stb"
IncludeDir["entt"] = "%{wks.location}/FarLight/vendor/entt/single_include"
IncludeDir["spdlog"] = "%{wks.location}/FarLight/vendor/spdlog/include"

group "Dependencies"
    include "FarLight/vendor/GLFW"
    include "FarLight/vendor/Glad"
    include "FarLight/vendor/ImGui"
group ""

group "Engine"
    include "FarLight"
    include "FarLightEditor"
group ""

group "Addition"
    include "Sandbox"
group ""