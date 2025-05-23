#include "Game.h"

#include <raylib.h>
#include "raymath.h"
#include <string>
#include <deque>
#include "../Config.h"
#include "../../src/Utils/VectorUtils.h"
#include "../Theme/Colors.h"
#include "../Snake/Snake.h"
#include "../Food/Food.h"

Game::Game(): offsetX(0), offsetY(0) {
    InitAudioDevice(); // Initializes audio system

    this->wallSound = LoadSound("Sounds/wall.mp3");
    this->eatSound = LoadSound("Sounds/eat.mp3");
}

Game::Game(const int offsetX, const int offsetY) :
    offsetX(offsetX),
    offsetY(offsetY)
{}

Game::~Game() {
    UnloadSound(this->wallSound);
    UnloadSound(this->eatSound);
    CloseAudioDevice();
}

// setters
void Game::setOffsetX(const int offsetX) {
    this->offsetX = offsetX;
}

void Game::setOffsetY(const int offsetY) {
    this->offsetY = offsetY;
}

// class methods
void Game::Draw() {
    const auto gameTitle = "Snake game";
    const int titleWidth = MeasureText(gameTitle, fontSize);
    DrawText(gameTitle, offsetX + (gridSize - titleWidth) / 2, offsetY - 20 - fontSize, fontSize, darkGreen);

    DrawText(TextFormat("Score: %i", score), offsetX, offsetY + (gridSize + 20), fontSize, darkGreen);

    DrawGrid();
    snake.Draw(offsetX, offsetY, cellSize);
    food.Draw(offsetX, offsetY, cellSize);

    if (isGameOver) {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.5f)); // blur effect
        DrawRestartText("Press ENTER to continue...");
    }
}

void Game::DrawRestartText(const std::string& message) {
    const int textWidth = MeasureText(message.c_str(), fontSize);
    const int x = (GetScreenWidth() - textWidth) / 2;
    const int y = GetScreenHeight() / 2;

    DrawText(message.c_str(), x, y, fontSize, RAYWHITE);
}

void Game::DrawGrid() const {
    for (int i = 0; i <= cellCount; i++) {
        DrawLine(offsetX + i * cellSize, offsetY, offsetX + i * cellSize, offsetY + gridSize, darkGreen);
        DrawLine(offsetX, offsetY + i * cellSize, offsetX + gridSize, offsetY + i * cellSize, darkGreen);
    }
}

void Game::Update() {
    if (isRunningGame) {
        snake.Update();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
    }
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

    // restart game after enter key is pressed
    if (IsKeyPressed(KEY_ENTER) && isGameOver) {
        isRunningGame = true;
        isGameOver = false;
        snake.ResetPosition();
        food.set_position(food.GenerateRandomPosition(snake.get_body_positions()));
    }
}

void Game::CheckCollisionWithFood() {
    if (Vector2Equals(snake.get_head_position(), food.get_position())) {
        food.GenerateRandomPosition(snake.get_body_positions());
        snake.set_segment(true);
        score++;

        PlaySound(this->eatSound);
    }
}

void Game::CheckCollisionWithEdges() {
    auto [x, y] = snake.get_head_position();

    if ((x < 0 || x >= cellCount) || (y < 0 || y >= cellCount)) {
        GameOver();
    }
}

void Game::CheckCollisionWithTail() {
    std::deque<Vector2> headlessBody = snake.get_body_positions();
    headlessBody.pop_front();

    if (VectorUtils::FindElementInDeque(snake.get_head_position(), headlessBody)) {
        GameOver();
    }
}

void Game::GameOver() {
    snake.ResetPosition();
    food.set_position(food.GenerateRandomPosition(snake.get_body_positions()));
    isRunningGame = false;
    isGameOver = true;
    score = 0;

    PlaySound(wallSound);
}