#include <iostream>
#include <raylib.h>

#include "Engine/Config.h"
#include "Engine/Theme/Colors.h"
#include "Engine/Game/Game.h"

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

    // getting current screen size
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    // calculating offset
    const int offsetX = (screenWidth - gridSize) / 2;
    const int offsetY = (screenHeight - gridSize) / 2;

    Game game{offsetX, offsetY};

    while (!WindowShouldClose()) {
        BeginDrawing();

        // drawing
        ClearBackground(lightGreen);

        game.Draw();

        // read action for move
        game.HandleInput();

        // update snake's move every 200 ms
        if (eventTriggered(0.2)) {
            game.Update();
        }

        EndDrawing();
    }

    CloseWindow();
}