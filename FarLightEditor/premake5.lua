project "FarLightEditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir (outputBinDir)
    objdir (outputObjDir)

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{IncludeDir.FarLight}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.stb}",
		"%{IncludeDir.entt}",
        "%{IncludeDir.cereal}",
        "%{IncludeDir.boost}"
    }

    libdirs
    {
        "%{IncludeDir.boost}/stage/lib"
    }

    links
    {
        "FarLight"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "FL_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "FL_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "FL_DIST"
        runtime "Release"
        optimize "on"
