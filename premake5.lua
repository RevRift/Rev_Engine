
-- Engine

workspace "Rev"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["spdlog"] = "Rev/vendor/spdlog/include"
IncludeDir["GLFW"] = "Rev/vendor/GLFW/include"
IncludeDir["Glad"] = "Rev/vendor/Glad/include"
IncludeDir["ImGui"] = "Rev/vendor/imgui"

include "Rev/vendor/GLFW"
include "Rev/vendor/Glad"
include "Rev/vendor/imgui"

project "Rev"
    location "Rev"
    kind "SharedLib"
    language "C++"
    staticruntime "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "revpch.h"
    pchsource "Rev/src/revpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Rev/src",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "REV_PLATFORM_WINDOWS",
            "REV_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }
        
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }
    
    filter "configurations:Debug"
        defines "REV_DEBUG"
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines "REV_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "REV_DIST"
        runtime "Release"
        optimize "On"
    


-- Client

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}");
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}");

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Rev/vendor/spdlog/include",
        "Rev/src"
    }

    links
    {
        "Rev"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "REV_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "REV_DEBUG"
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines "REV_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "REV_DIST"
        runtime "Release"
        optimize "On"