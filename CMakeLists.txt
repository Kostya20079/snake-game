cmake_minimum_required(VERSION 3.20)
project(snake_game)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

# Fetch raylib from GitHub
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.5.0
        GIT_SHALLOW TRUE
)

# Make the raylib target available
FetchContent_MakeAvailable(raylib)

# Create your executable
add_executable(snake_game main.cpp
        Engine/Food/Food.cpp
        Engine/Food/Food.h
        Engine/Snake/Snake.cpp
        Engine/Snake/Snake.h
        Engine/Theme/Colors.cpp
        Engine/Theme/Colors.h
        Engine/Game/Game.cpp
        Engine/Game/Game.h
        Engine/Config.h
        src/Utils/VectorUtils.cpp
        src/Utils/VectorUtils.h)

# Link raylib (and its dependencies)
target_link_libraries(snake_game PRIVATE raylib)

# Set output directory path (this is where the binary will run from)
set(OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR})

# Copy the Sounds directory to the output directory
add_custom_command(TARGET snake_game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/Sounds
        ${OUTPUT_DIR}/Sounds
)