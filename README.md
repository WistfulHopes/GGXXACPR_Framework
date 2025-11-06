# GGXXACPR_Framework
A modding framework for Guilty Gear XX Accent Core Plus R. Currently supports adding custom characters.

## Usage

This project requires CMake 3.15 or newer.

1. Make a new folder.
2. Add this repo as a submodule to that folder: `git submodule add https://github.com/WistfulHopes/GGXXACPR_Framework.git`
3. Add a CMakeLists.txt file to your folder with the following contents:
```
// Replace CustomChara with your desired project name.
cmake_minimum_required(VERSION 3.22)
project(PlusRMods)

add_subdirectory(GGXXACPR_Framework)
add_subdirectory(CustomChara)
```
4. Set up a folder for your mod named after your project name.
5. Add a CMakeLists.txt file to the project folder with the following contents:
```
// Replace CustomChara with your desired project name.
project(CustomChara)

set(TARGET CustomChara)
project(${TARGET})

// Add source files as needed.
set(${TARGET}_Sources
        "${CMAKE_CURRENT_SOURCE_DIR}/src/dllmain.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/CustomChara.cpp"
        )

add_library(${TARGET} SHARED ${${TARGET}_Sources})
target_include_directories(${TARGET} PRIVATE "include")
target_link_libraries(${TARGET} PUBLIC GGXXACPR_Framework)
```
6. Create the necessary headers and sources.
7. Create a folder called `build` in your root folder.
8. Open a command line in the build folder, and enter the command `cmake ..`.
