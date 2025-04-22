#ifndef FOOD_H
#define FOOD_H

#include <raylib.h>

class Food {
public:
    Vector2 position{};
    Texture2D texture{};

    // constructors and destructors
    Food();
    explicit Food(int maxSize);
    ~Food();

    // class methods
    void Draw(int offsetX, int offsetY, int cellSize) const;

private:
    void LoadTexture();
    static Vector2 GenerateRandomPosition(int maxCountOfCell);
};

#endif //FOOD_H
