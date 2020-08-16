project "Sandbox"
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
        "../FarLight/src",
        "../FarLight/vendor/Glad/include",
        "../FarLight/vendor/glm",
        "../FarLight/vendor/ImGui",
        "../FarLight/vendor/spdlog/include",
        "../FarLight/vendor/stb"
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