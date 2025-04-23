#include "Game.h"

#include "../Config.h"
#include "../Theme/Colors.h"
#include "../Snake/Snake.h"
#include "../Food/Food.h"

Game::Game(const int offsetX, const int offsetY) :
    offsetX(offsetX),
    offsetY(offsetY)
{}

// class methods
void Game::Draw() const {
    DrawGrid();
    snake.Draw(offsetX, offsetY, cellSize);
    food.Draw(offsetX, offsetY, cellSize);
}

void Game::DrawGrid() const {
    for (int i = 0; i <= cellCount; i++) {
        DrawLine(offsetX + i * cellSize, offsetY, offsetX + i * cellSize, offsetY + gridSize, darkGreen);
        DrawLine(offsetX, offsetY + i * cellSize, offsetX + gridSize, offsetY + i * cellSize, darkGreen);
    }
}

void Game::Update() {
    snake.Update();
}

void Game::HandleInput() {
    Vector2 currentDirection = snake.get_direction();

    if (IsKeyPressed(KEY_LEFT) && currentDirection.x != 1) {
        snake.set_direction({-1, 0});
    }
    if (IsKeyPressed(KEY_RIGHT) && currentDirection.x != -1) {
        snake.set_direction({1, 0});
    }
    if (IsKeyPressed(KEY_UP) && currentDirection.y != 1) {
        snake.set_direction({0, -1});
    }
    if (IsKeyPressed(KEY_DOWN) && currentDirection.y != -1) {
        snake.set_direction({0, 1});
    }
}

bool Game::IsGameOver() const {
    auto [x, y] = snake.get_head_position();

    return (x < 0 || x >= cellCount) || (y < 0 || y >= cellCount);
}
