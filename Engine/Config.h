#pragma once
#include <deque>

constexpr int fontSize = 40;

constexpr int cellSize = 40;
constexpr int cellCount = 15;
constexpr int gridSize = cellSize * cellCount;

// Start body positions for something like a snake game
constexpr Vector2 startBodyArray[] = { {5, 4}, {4, 4}};
const std::deque startBodyPosition(startBodyArray, startBodyArray + std::size(startBodyArray));

// Initial direction of movement (e.g., to the right)
constexpr Vector2 directionOfMoving = {1, 0};