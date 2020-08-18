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