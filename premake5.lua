workspace "pigImGui"
    architecture "ARM64"
    configurations { "Debug", "Release" }
    startproject "pigImGui"

project "pigImGui"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++23"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin-int/%{cfg.buildcfg}"

    buildoptions { "-std=c++23" }

    prebuildcommands {
        "mkdir -p bin-int/Debug && cp src/headers/pch.hpp bin-int/Debug/pch.hpp",
        "mkdir -p bin-int/Release && cp src/headers/pch.hpp bin-int/Release/pch.hpp",
    }

    files {
        "src/**.cpp",
        "src/headers/**.hpp",
        "src/headers/**.h"
    }

    libdirs { os.getenv("HOME") .. "/cppProjects/cppEngine/build/obj" }

    includedirs {
        "src/headers",
        "/opt/homebrew/include",
        os.getenv("HOME") .. "/cppProjects/cppEngine/include"
    }

    links {
        "sfml-graphics",
        "sfml-window",
        "sfml-system",
        "CppEngine"
    }

    pchheader "src/headers/pch.hpp"
    pchsource "src/controller/pch.cpp"

    filter "system:macosx"
        links { "OpenGL.framework" }
        linkoptions { "-Wl,-rpath," .. os.getenv("HOME") .. "/cppProjects/cppEngine/build/obj" }
        libdirs { "/opt/homebrew/Cellar/sfml/3.0.2/lib" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
    postbuildcommands {
        "mkdir -p bin/%{cfg.buildcfg}/pigImGui.app/Contents/MacOS",
        "mkdir -p bin/%{cfg.buildcfg}/pigImGui.app/Contents/Resources",
        "cp bin/%{cfg.buildcfg}/pigImGui bin/%{cfg.buildcfg}/pigImGui.app/Contents/MacOS/pigImGui",
        "cp Info.plist bin/%{cfg.buildcfg}/pigImGui.app/Contents/Info.plist",
        "rm -rf bin/%{cfg.buildcfg}/pigImGui.app/Contents/Frameworks",
        "mkdir -p bin/%{cfg.buildcfg}/pigImGui.app/Contents/Frameworks",
        "cp /opt/homebrew/Cellar/sfml/3.0.1/lib/libsfml-graphics.3.0.1.dylib bin/%{cfg.buildcfg}/pigImGui.app/Contents/Frameworks/",
        "cp /opt/homebrew/Cellar/sfml/3.0.1/lib/libsfml-window.3.0.1.dylib bin/%{cfg.buildcfg}/pigImGui.app/Contents/Frameworks/",
        "cp /opt/homebrew/Cellar/sfml/3.0.1/lib/libsfml-system.3.0.1.dylib bin/%{cfg.buildcfg}/pigImGui.app/Contents/Frameworks/",
    }

    filter {}
