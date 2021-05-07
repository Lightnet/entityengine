# EnitityEngine

# LICENSE: MIT

# Created By: Lightnet

# Status:
 * Prototype buiild
 * 

# Packages:
 * glfw
 * vulkan sdk
 * cmake 
 * imgui 
 * glm
 * flecs
 * work in progress...

# Information:
  Work in progress prototype builds. Working toward working vulkan entity engine.

  To develop stand alone editor/game that use format for to read, write and load to game data. It is still in testing phrase and learning about for c and c++ build to keep things simple.

  There are simple test build for opengl for testing the imgui for dev.

# To Do List:
 * builds with vulkan graphic hardware render
 * scene
 * game object
    * player
    * camera
    * mesh
    * animation mesh
 * network
 * zone / cluster simultion
 * loadeding object
 * voxel 
    * pixel
    * mesh
 * Editor
 * Server/Client
 * Http / Rest 
 * module system
 * node system
 * 

# Build:
```bat
:: Create a build directory
mkdir build 
cd build
::get the CMakeLists.txt config
cmake ..
:: build binary and libraries
cmake --build . 
```

```bat
cd build
cd Debug
::start program app 
START /wait eeapp.exe
::START /wait ecme.exe
```
# Base Ideas:
 * https://github.com/farbrausch/fr_public


# Notes:
 * Using the cmake build config is not set compile build correctly.
 * 

# Credits:
 * https://marcelbraghetto.github.io/a-simple-triangle/
 * https://github.com/MarcelBraghetto/a-simple-triangle
 * 
