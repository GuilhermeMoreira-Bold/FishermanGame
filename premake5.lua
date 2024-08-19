workspace "FishermanLife"
    architecture "x64"
    startproject "Sandbox"
    configurations { "Debug", "Release" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    project "GLFW"
        location "GLFW"
        kind "StaticLib"
        language "C"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "vendor/GLFW/src/**.h",
            "vendor/GLFW/src/**.c"
        }

        includedirs
        {
            "vendor/GLFW/include"
        }

        filter "system:windows"
            systemversion "latest"
            defines { "_GLFW_WIN32", "_CRT_SECURE_NO_WARNINGS" }

        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            runtime "Release"
            optimize "on"

    -- Projeto GLAD
    project "GLAD"
        location "GLAD"
        kind "StaticLib"
        language "C"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "vendor/GLAD/src/**.h",
            "vendor/GLAD/src/**.c"
        }

        includedirs
        {
            "vendor/GLAD/include"
        }

        filter "system:windows"
            systemversion "latest"

        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            runtime "Release"
            optimize "on"

    -- Projeto ImGui
    project "ImGui"
        location "ImGui"
        kind "StaticLib"
        language "C++"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "vendor/ImGui/*.cpp",
            "vendor/ImGui/*.h"
        }

        includedirs
        {
            "vendor/ImGui",
            "vendor/GLFW/include"
        }

        links
        {
            "GLFW"
        }

        filter "system:windows"
            systemversion "latest"

        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            runtime "Release"
            optimize "on"

    -- Projeto Gear
    project "Gear"
        location "Gear"
        kind "StaticLib"
        language "C++"
        cppdialect "C++20"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "Gear/src/**.cpp",
            "Gear/src/**.h"
        }

        includedirs
        {
            "Gear/src",
            "vendor/GLFW/include",
            "vendor/GLAD/include",
            "vendor/GLM",
            "vendor/ImGui"
        }

        links
        {
            "GLFW",
            "GLAD",
            "ImGui"
        }

        defines
        {
            "GEAR_EXPORTS"
        }

        postbuildcommands
        {
            ("{COPY}\"%{cfg.buildtarget.relpath}\" \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

        filter "system:windows"
            systemversion "latest"

        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            runtime "Release"
            optimize "on"

    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++20"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "Sandbox/src/**.cpp",
            "Sandbox/src/**.h"
        }

        includedirs
        {
            "Gear/src"
        }

        links
        {
            "Gear"
        }

        filter "system:windows"
            systemversion "latest"

        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            runtime "Release"
            optimize "on"
