workspace "Lumina"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Distribution"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine"
    location "Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("%{prj.name}/Binaries/" .. outputdir)
    objdir ("%{prj.name}/Intermediate/" .. outputdir)

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "{prj.name}/Source/"
    }

    defines
    {
        "LUMINA_CORE"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LUMINA_PLATFORM_WINDOWS"
        }

        postbuildcommands
        {
            ""
        }

    filter "configurations:Debug"
        defines "LUMINA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LUMINA_RELEASE"
        optimize "On"

    filter "configurations:Distribution"
        defines "LUMINA_DISTRIBUTION"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    links
    {
        "Engine"
    }

    targetdir ("%{prj.name}/Binaries/" .. outputdir)
    objdir ("%{prj.name}/Intermediate/" .. outputdir)

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "{prj.name}/Source/",
        "Engine/Source/"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LUMINA_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "LUMINA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LUMINA_RELEASE"
        optimize "On"

    filter "configurations:Distribution"
        defines "LUMINA_DISTRIBUTION"
        optimize "On"