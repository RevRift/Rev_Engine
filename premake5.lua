
-- Engine

workspace "Rev"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Rev"
    location "Rev"
    kind "SharedLib"
    language "C++"

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
        "%{prj.name}/vendor/spdlog/include",
        "Rev/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "REV_PLATFORM_WINDOWS",
            "REV_BUILD_DLL"
        }
        
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "REV_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "REV_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "REV_DIST"
        optimize "On"
    


-- Client

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

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
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "REV_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "REV_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "REV_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "REV_DIST"
        optimize "On"