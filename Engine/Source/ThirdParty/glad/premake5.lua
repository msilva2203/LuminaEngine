project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"
    warnings "off"

    targetdir ("bin/" .. outputdir)
    objdir ("obj/" .. outputdir)

    files
    {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

    includedirs
    {
        "include/"
    }

    filter "system:windows"
        systemversion "latest"

    filter "system:linux"
        pic "on"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        symbols "on"
        optimize "on"

    filter "configurations:Distribution"
        runtime "Release"
        symbols "off"
        optimize "on"