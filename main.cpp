#include <iostream>
#include <raylib.h>
#include <deque>

#include "Engine/Theme/Colors.h"
#include "Engine/Food/Food.h"
#include "Engine/Snake/Snake.h"

constexpr int cellSize = 30;
constexpr int cellCount = 20;

int main () {
    using namespace std;

    // create program window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);    // Window configuration flags
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Snake game");
    SetTargetFPS(60); // frequency of refreshing screen


    Food food{cellCount};
    Snake snake{};

    while (!WindowShouldClose()) {
        BeginDrawing();

        // getting current screen size
        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        constexpr int gridSize = cellSize * cellCount;

        // calculating offset
        const int offsetX = (screenWidth - gridSize) / 2;
        const int offsetY = (screenHeight - gridSize) / 2;

        // drawing
        ClearBackground(lightGreen);


        food.Draw(offsetX, offsetY, cellSize);
        snake.Draw(offsetX, offsetY, cellSize);


        for (int i = 0; i <= cellCount; i++) {
            DrawLine(offsetX + i * cellSize, offsetY, offsetX + i * cellSize, offsetY + gridSize, darkGreen);
            DrawLine(offsetX, offsetY + i * cellSize, offsetX + gridSize, offsetY + i * cellSize, darkGreen);
        }

        EndDrawing();
    }

    CloseWindow();
}