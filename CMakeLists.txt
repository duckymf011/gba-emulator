cmake_minimum_required(VERSION 3.10)
project(gba-emulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(SDL2 REQUIRED)

# Include directories
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/src)

# Source files
set(SOURCES
    src/main.cpp
    src/emulator.cpp
    src/cpu/cpu.cpp
    src/memory/memory.cpp
    src/graphics/ppu.cpp
    src/audio/apu.cpp
    src/input/input.cpp
    src/cartridge/cartridge.cpp
)

# Create executable
add_executable(gba-emulator ${SOURCES})

# Link libraries
target_link_libraries(gba-emulator ${SDL2_LIBRARIES})

# Platform-specific settings
if(MSVC)
    target_compile_options(gba-emulator PRIVATE /W4)
else()
    target_compile_options(gba-emulator PRIVATE -Wall -Wextra -Wpedantic)
endif()
