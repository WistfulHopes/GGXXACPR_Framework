# Almost all CMake files should start with this
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
cmake_minimum_required(VERSION 3.15...4.0)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
  GGXXACPR_Framework
  VERSION 1.0
  LANGUAGES C CXX)

set(CMAKE_C_FLAGS "-m32")
set(CMAKE_CXX_FLAGS "-m32")

# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)

# Find packages go here.

# You should usually split this into folders, but this is a simple example

# Find source files
set(SOURCES src/Console.cpp src/dllmain.cpp src/GGFramework.cpp src/safetyhook.cpp src/Zydis.c)
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/**.h")

# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
add_library(GGXXACPR_Framework SHARED ${SOURCES})

# Set C++23 standard 
target_compile_features(GGXXACPR_Framework PUBLIC cxx_std_23)
set_target_properties(GGXXACPR_Framework PROPERTIES LINK_FLAGS "/machine:x86")
set_target_properties(GGXXACPR_Framework PROPERTIES LINKER_LANGUAGE CXX)

# Add include directories
target_include_directories(GGXXACPR_Framework PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Add headers as sources for IDE integration
target_sources(GGXXACPR_Framework PUBLIC
    FILE_SET headers TYPE HEADERS
    BASE_DIRS include
    FILES ${HEADERS}
)

# Add defines
target_compile_definitions(GGXXACPR_Framework PRIVATE DLL_EXPORTS)

# Organize in IDE
source_group(TREE "${CMAKE_CURRENT_LIST_DIR}" FILES ${SOURCES} ${HEADERS})
