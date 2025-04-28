#include "Food.h"

#include "../Config.h"
#include <raylib.h>
#include "raymath.h"

Food::Food(const std::deque<Vector2>& snakeBody): position(GenerateRandomPosition(snakeBody)) {
    LoadTexture();
}

Food::~Food() {
    UnloadTexture(texture);
}

void Food::LoadTexture() {
    const Image image = LoadImage("../src/Graphic/food.png");;
    if (image.data == nullptr) {
        TraceLog(LOG_ERROR, "Failed to load image!");
    }
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

void Food::Draw(const int offsetX, const int offsetY, const int cellSize) const {
    // draw food in center of cell
    const int drawX = offsetX + position.x * cellSize + (cellSize - texture.width) / 2;
    const int drawY = offsetY + position.y * cellSize + (cellSize - texture.height) / 2;

    DrawTexture(
        texture,
        drawX,
        drawY,
        WHITE
    );
}

Vector2 Food::get_position() const {
    return position;
}

Vector2 Food::ChangePosition() {
    const int x = GetRandomValue(0,  cellCount - 1);
    const int y = GetRandomValue(0,  cellCount - 1);
    return Vector2{static_cast<float>(x), static_cast<float>(y)};
}

bool Food::FindElementInDeque(const Vector2 position, const std::deque<Vector2> &deque) {
    for (const auto i : deque) {
        if (Vector2Equals(i, position)) {
            return true;
        }
    }
    return false;
}

Vector2 Food::GenerateRandomPosition(const std::deque<Vector2> &snakeBody) {
    const Vector2 newPosition = ChangePosition();
    while (FindElementInDeque(position, snakeBody)) {
        position = ChangePosition();
    }
    return newPosition;
}