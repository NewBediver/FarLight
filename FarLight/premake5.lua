project "FarLight"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir (outputBinDir)
    objdir (outputObjDir)

    pchheader "flpch.h"
    pchsource "src/flpch.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "vendor/Glad/include",
        "vendor/glm",
        "vendor/GLFW/include",
        "vendor/ImGui",
        "vendor/spdlog/include",
        "vendor/stb"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    defines
    {
        "GLFW_INCLUDE_NONE"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines 
        {
            "FL_DEBUG",
            "FL_ENABLE_ASSERTS"
        }
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