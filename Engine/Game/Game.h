#ifndef GAME_H
#define GAME_H

#include <string>
#include "../Snake/Snake.h"
#include "../Food/Food.h"

class Game {
public:
    // constructors
    Game();
    Game(int offsetX, int offsetY);
    ~Game();

    Snake snake;
    Food food{ snake.get_body_positions() };

    // setters
    void setOffsetX(int offsetX);
    void setOffsetY(int offsetY);

    // class methods
    void Draw();
    void DrawRestartText(const std::string& message);
    void Update();
    void HandleInput();
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
    void GameOver();

private:
    int offsetX;
    int offsetY;
    bool isRunningGame = true;
    bool isGameOver = false;
    int score = 0;

    Sound wallSound;
    Sound eatSound;

    void DrawGrid() const;
};

#endif //GAME_H
