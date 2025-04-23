#include <iostream>
#include <raylib.h>

#include "Engine/Theme/Colors.h"
#include "Engine/Food/Food.h"
#include "Engine/Snake/Snake.h"

constexpr int cellSize = 30;
constexpr int cellCount = 20;

double lastUpdateTime = 0.0;

// functions
bool eventTriggered(const double interval) {
    double currentTime = GetTime();

    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}


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

        // update snake's move every 200 ms
        if (eventTriggered(0.2)) {
            snake.Update();
        }

        if (IsKeyPressed(KEY_UP) && snake.get_direction().y != 1) {
            snake.set_direction({0, -1});
        }
        if (IsKeyPressed(KEY_DOWN) && snake.get_direction().y != -1) {
            snake.set_direction({0, 1});
        }
        if (IsKeyPressed(KEY_LEFT) && snake.get_direction().x != 1) {
            snake.set_direction({-1, 0});
        }
        if (IsKeyPressed(KEY_RIGHT) && snake.get_direction().x != -1) {
            snake.set_direction({1, 0});
        }

        // !temporarily!
        if (snake.get_head_position().x < 0 || snake.get_head_position().x >= cellCount) {
            break;
        }

        if (snake.get_head_position().y < 0 || snake.get_head_position().y >= cellCount) {
            break;
        }

        for (int i = 0; i <= cellCount; i++) {
            DrawLine(offsetX + i * cellSize, offsetY, offsetX + i * cellSize, offsetY + gridSize, darkGreen);
            DrawLine(offsetX, offsetY + i * cellSize, offsetX + gridSize, offsetY + i * cellSize, darkGreen);
        }

        EndDrawing();
    }

    CloseWindow();
}