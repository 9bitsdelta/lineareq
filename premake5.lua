workspace "LinearEq"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

	project "lineareq"
		location "src"
		kind "ConsoleApp"
		language "C"
		staticruntime "on"

		targetdir ("bin/%{cfg.buildcfg}/")
		objdir ("bin-int/")

		files
		{
			"src/**.h",
			"src/**.c"
		}

		includedirs
		{	
			"src/"
		}

		links
		{

		}

		filter "system:windows"
			systemversion "latest"

			defines { "PLATFORM_WINDOWS" }

			filter "system:linux"
			systemversion "latest"
			toolset ("gcc")

			defines { "PLATFORM_LINUX" }

		filter "configurations:Debug"
			defines "CONFIG_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "CONFIG_RELEASE"
			runtime "Release"
			optimize "on"
