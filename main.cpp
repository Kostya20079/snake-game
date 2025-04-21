#include <iostream>
#include <raylib.h>

// game's color theme
Color lightGreen = {173, 204, 96, 25};
Color DarkGreen = {43, 51, 24, 255};

int main () {
    using namespace std;

    // getting player's screen size
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    // create program window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);    // Window configuration flags
    InitWindow(screenWidth, screenHeight, "Snake game");
    SetTargetFPS(60); // frequency of refreshing screen

    while (WindowShouldClose() == false) {
        BeginDrawing();

        // drawing
        ClearBackground(lightGreen);

        EndDrawing();
    }

    CloseWindow();
}