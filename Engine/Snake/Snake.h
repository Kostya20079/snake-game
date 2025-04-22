#ifndef SNAKE_H
#define SNAKE_H
#include <deque>

#include "raylib.h"

class Snake {
public:
    // constructors and destructors
    Snake();

    // class methods
    void Draw(int offsetX, int offsetY, int cellSize) const;

private:
    std::deque<Vector2> body;
};

#endif //SNAKE_H
