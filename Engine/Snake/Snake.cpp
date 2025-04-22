#include "Snake.h"
#include <deque>

Snake::Snake(): body({Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}}) {}

void Snake::Draw(const int offsetX, const int offsetY, const int cellSize) const{
    for (auto & i : body) {
        const int positionX = i.x;
        const int positionY = i.y;

        Rectangle segment = Rectangle(
            offsetX + positionX * cellSize,
            offsetY + positionY * cellSize,
            cellSize,
            cellSize);

        DrawRectangleRounded(
            segment,
            0.4f,
            cellSize,
            {43, 51, 24, 255}
        );
    }
}