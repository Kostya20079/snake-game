#include "Snake.h"
#include <deque>
#include <raymath.h>
#include "../Theme/Colors.h"

// example snake body and move
Snake::Snake(): body({Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}}), direction(Vector2 {1, 0}) {}

// setters
void Snake::set_direction(const Vector2 direction) {
    this->direction = direction;
}

void Snake::set_segment(const bool state) {
    this->addSegment = state;
}

// getters
Vector2 Snake::get_direction() const {
    return this->direction;
}

Vector2 Snake::get_head_position() const {
    return body.front();
}

std::deque<Vector2> Snake::get_body_positions() const {
    return body;
}

// class methods
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
            darkGreen
        );
    }
}

void Snake::Update() {
    body.push_front(Vector2Add(body[0], direction));

    if (addSegment) {
        this->addSegment = false;
    } else {
        body.pop_back();
    }
}