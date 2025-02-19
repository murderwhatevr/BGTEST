cmake_minimum_required(VERSION 3.10)
project(EOF VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

# Specify MinGW as the compiler (if you're using MinGW)
if(NOT DEFINED CMAKE_CXX_COMPILER)
    set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")
endif()

if(NOT DEFINED CMAKE_C_COMPILER)
    set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
endif()

# Enable CMake to use vcpkg toolchain (if running manually, pass it as an argument)
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# Include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories("C:/SFML/SFML-2.6.2/include")

# Set SFML CMake directory
set(SFML_DIR "C:/SFML/SFML-2.6.2/lib/cmake/SFML")

# Set Freetype paths manually (adjust these to your setup)
set(FREETYPE_INCLUDE_DIRS "C:/vcpkg/vcpkg/installed/x64-windows/include/freetype")
set(FREETYPE_LIBRARY "C:/vcpkg/vcpkg/installed/x64-windows/lib/freetype.lib")

# Manually set Freetype include and library paths (ensures linker finds it)
include_directories(${FREETYPE_INCLUDE_DIRS})
link_directories("C:/vcpkg/vcpkg/installed/x64-windows/lib")

# Add SFML link directory (adjust the path to where the SFML libraries are located)
link_directories("C:/SFML/SFML-2.6.2/lib")  # Ensure this is correct

# Collect all .cpp files automatically
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Define the executable
add_executable(EOF ${SRC_FILES})

# Link required libraries (using MinGW-style .a files)
target_link_libraries(EOF
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-network
    ${FREETYPE_LIBRARY}  # Ensure Freetype links correctly
    opengl32
    winmm
    gdi32
    user32
)

# Print debug information
message(STATUS "CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "FREETYPE_INCLUDE_DIRS: ${FREETYPE_INCLUDE_DIRS}")
message(STATUS "FREETYPE_LIBRARY: ${FREETYPE_LIBRARY}")
