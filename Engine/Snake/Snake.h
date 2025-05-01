#ifndef SNAKE_H
#define SNAKE_H
#include <deque>

#include "raylib.h"

class Snake {
public:
    // constructors and destructors
    Snake();

    // setters
    void set_direction(Vector2 direction);
    void set_segment(bool state);

    // getters
    Vector2 get_direction() const;

    Vector2 get_head_position() const;
    std::deque<Vector2> get_body_positions() const;

    // class methods
    void Draw(int offsetX, int offsetY, int cellSize) const;
    void Update();
    void ResetPosition();

private:
    std::deque<Vector2> body;
    Vector2 direction;
    bool addSegment = false;
};

#endif //SNAKE_H
