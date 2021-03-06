project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"

    targetdir (outputBinDir)
    objdir (outputObjDir)

    files
    {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

    includedirs
    {
        "include"
    }

    filter "system:linux"
        pic "on"
        systemversion "latest"

    defines 
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"