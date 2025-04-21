#include "Food.h"
#include <raylib.h>

Food::Food(): position(Vector2(0, 0)) {
    LoadTexture();
}

Food::Food(const int maxSize): position(GenerateRandomPosition(maxSize)) {
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

Vector2 Food::GenerateRandomPosition(const int maxCountOfCell) {
    const float x = GetRandomValue(0, maxCountOfCell - 1);
    const float y = GetRandomValue(0, maxCountOfCell - 1);
    return Vector2{x, y};
}
