#ifndef GAME_H
#define GAME_H

#include <string>
#include "../Snake/Snake.h"
#include "../Food/Food.h"

class Game {
public:
    // constructors
    Game(int offsetX, int offsetY);

    Snake snake;
    Food food{ snake.get_body_positions() };

    // class methods
    void Draw();
    void DrawRestartText(const std::string& message);
    void Update();
    void HandleInput();
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void GameOver();

private:
    int offsetX;
    int offsetY;
    bool isRunningGame = true;
    bool isGameOver = false;

    void DrawGrid() const;
};

#endif //GAME_H
