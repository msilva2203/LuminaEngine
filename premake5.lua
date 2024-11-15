workspace "Lumina"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Distribution"
    }

-- the general output directory for each project
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories
include_dirs = {}
include_dirs["glfw"] = "Engine/Source/ThirdParty/glfw/include"
include_dirs["glad"] = "Engine/Source/ThirdParty/glad/include"

-- premake includes
include "Engine/Source/ThirdParty/glfw"
include "Engine/Source/ThirdParty/glad"

project "Engine"
    location "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("%{prj.name}/Binaries/" .. outputdir)
    objdir ("%{prj.name}/Intermediate/" .. outputdir)

    files
    {
        "%{prj.name}/Source/Lumina/**.h",
        "%{prj.name}/Source/Lumina/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/Source/Lumina/",
        "%{prj.name}/Source/ThirdParty/spdlog/include/",
        "%{include_dirs.glfw}",
        "%{include_dirs.glad}"
    }

    defines
    {
        "LUMINA_CORE"
    }

    links
    {
        "glfw"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "LUMINA_PLATFORM_WINDOWS"
        }

        links
        {
            "opengl32.lib"
        }

    filter "system:linux"
        pic "on"
        systemversion "latest"

        defines
        {
            "LUMINA_PLATFORM_LINUX"
        }

        links
        {
            "glfw",
            "GL",
            "X11",
            "pthread",
            "dl",
            "Xrandr",
            "Xi",
            "Xxf86vm"
        }

    filter "configurations:Debug"
        defines "LUMINA_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "LUMINA_RELEASE"
        runtime "Release"
        symbols "on"
        optimize "Speed"

    filter "configurations:Distribution"
        defines "LUMINA_DISTRIBUTION"
        runtime "Release"
        symbols "off"
        optimize "Speed"

    buildoptions "/utf-8"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("%{prj.name}/Binaries/" .. outputdir)
    objdir ("%{prj.name}/Intermediate/" .. outputdir)

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/Source/",
        "Engine/Source/Lumina/",
        "Engine/Source/ThirdParty/spdlog/include/",
        "%{include_dirs.glfw}",
        "%{include_dirs.glad}"
    }

    links
    {
        "Engine"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "LUMINA_PLATFORM_WINDOWS"
        }

    filter "system:linux"
        pic "on"
        systemversion "latest"

        defines
        {
            "LUMINA_PLATFORM_LINUX"
        }

        links
        {
            "glfw",
            "GL",
            "X11",
            "pthread",
            "dl",
            "Xrandr",
            "Xi"
        }

    filter "configurations:Debug"
        defines "LUMINA_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "LUMINA_RELEASE"
        runtime "Release"
        symbols "on"
        optimize "on"

    filter "configurations:Distribution"
        defines "LUMINA_DISTRIBUTION"
        runtime "Release"
        symbols "off"
        optimize "on"

    buildoptions "/utf-8"
