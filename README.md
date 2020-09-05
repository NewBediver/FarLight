# FarLight

<a alt="C/C++"> <img src="https://img.shields.io/badge/C%2FC%2B%2B17-MSVC-red" /> </a>
<a alt="GLSL"> <img src="https://img.shields.io/badge/GLSL-4.2-red" /> </a>
<a alt="Premake5"> <img src="https://img.shields.io/badge/Premake-5-red" /> </a>
<a alt="Spdlog"> <img src="https://img.shields.io/badge/SpdLog-gray" /> </a>
<a alt="OpenGL"> <img src="https://img.shields.io/badge/OpenGL-gray" /> </a>
<a alt="Glad"> <img src="https://img.shields.io/badge/Glad-gray" /> </a>
<a alt="GLFW"> <img src="https://img.shields.io/badge/GLFW-gray" /> </a>
<a alt="GLM"> <img src="https://img.shields.io/badge/GLM-gray" /> </a>

<p align="center">
  <img src="/Logo/Logo.png?raw=true">
</p>

FarLight is primarily an early-stage interactive application and rendering engine for Windows. Currently not much is implemented, but I plan to do more convenient features and user-friendly design and in the future :smile:. 

## Getting Started
Visual Studio 2017 or 2019 is recommended with C/C++17 MSVC compiler preinstalled. FarLight is officially untested on other development environments but they can be used because of [premake5](https://github.com/premake/premake-core) support. Main development is running under Visual Studio 2019 and Windows system.

You can clone the repository to a local destination using git:

`git clone --recursive https://github.com/NewBediver/FarLight.git`

Make sure that you do a `--recursive` clone to fetch all of the submodules!

To generate solution you need to execute script Win-GenerateProject.bat which is located inside /scripts directory.

## Dependencies and submodules

- [Premake5](https://github.com/premake/premake-core)
- [GLFW](https://github.com/glfw/glfw)
- [Glad](https://github.com/Dav1dde/glad)
- [ImGui](https://github.com/ocornut/imgui)
- [entt](https://github.com/skypjack/entt)
- [glm](https://github.com/g-truc/glm)
- [spdlog](https://github.com/gabime/spdlog)
- [stb](https://github.com/gabime/spdlog)

## The Plan
The plan for FarLight is two-fold: to create a powerful 2D/3D engine, but also to serve as an education tool for studing game engine design and architecture. Because of this the development inside this repository is rather slow.

### Main features to come:
- Fast 2D rendering (UI, particles, sprites, etc.)
- High-fidelity Physically-Based 3D rendering (this will be later, 2D to come first)
- Support for Mac, Linux, Android and iOS
  - Native rendering API support (DirectX, Vulkan, Metal)
- Fully featured viewer and editor applications
- Fully scripted interaction and behavior
- Integrated 3rd party 2D and 3D physics engine
- Procedural terrain and world generation
- Artificial Intelligence
- Audio system

## Apache 2.0 license synopsis

The Apache 2.0 license is a permissive free software license by the Apache Software Foundation. The 2.0 version requires preservation of the copyright notice and disclaimer. It also allows the user of the software the freedom to use the software for any purpose, modify it, and distribute the modified versions of the software, under the terms of the license, without concern for royalties.

Key points:
```markdown
1. Keep the copyright notice.
2. Your software has to contain a copy of the Apache 2.0 license.
3. You are free to use, modify, distribute, and redistribute the software.
4. If you modify the code, you have to mention your modifications particularly.
5. If there is a text file called NOTICE, take time and read it. It contains further information about the specific parts of the license and the purpose of the software.
6. The NOTICE file has to be included in your software release too.
```

More information on about the Apache 2.0 license can be found [here](https://choosealicense.com/licenses/apache-2.0).
