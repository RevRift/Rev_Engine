project "Glad"
    kind "StaticLib"
    language "C"

    targetdir ("bin/" .. outputdir .. "/%(prj.name)")
    objdir ("bin/" .. outputdir .. "/%(prj.name)")

    files
    {
        "include/glad/glac.h",
		"include/KHR/krhplatform.h",
		"src/glad.c"
    }

	includedirs
	{
		"include"
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"
    
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
        