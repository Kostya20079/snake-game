#ifndef GAME_H
#define GAME_H

#include "../Snake/Snake.h"
#include "../Food/Food.h"

class Game {
public:
    // constructors
    Game(int offsetX, int offsetY);

    Snake snake;
    Food food;

    // class methods
    void Draw() const;
    void Update();
    void HandleInput();
    bool IsGameOver() const;

private:
    int offsetX;
    int offsetY;

    void DrawGrid() const;
};

#endif //GAME_H
