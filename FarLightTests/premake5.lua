project "FarLightTests"
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
        "vendor/googletest/googletest/include",
        "../FarLight/src",
        "../FarLight/vendor/GLFW/include",
        "../FarLight/vendor/spdlog/include"
    }

    links
    {
        "GoogleTestsCompilation",
        "FarLight"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"