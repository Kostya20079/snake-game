#ifndef FOOD_H
#define FOOD_H

#include <deque>
#include <raylib.h>

class Food {
public:
    // constructors and destructors
    explicit Food(const std::deque<Vector2>& snakeBody);
    ~Food();

    // getters
    Vector2 get_position() const;

    // setters
    void set_position(const Vector2& position);

    // class methods
    void Draw(int offsetX, int offsetY, int cellSize) const;
    Vector2 GenerateRandomPosition(const std::deque<Vector2> &snakeBody);

private:
    Vector2 position{};
    Texture2D texture{};

    void LoadTexture();
    static Vector2 ChangePosition();
    bool FindElementInDeque(Vector2 position, const std::deque<Vector2> &deque);
};

#endif //FOOD_H
