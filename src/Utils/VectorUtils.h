#pragma once
#include <deque>
#include <raylib.h>

namespace VectorUtils {

    bool FindElementInDeque(Vector2 position, const std::deque<Vector2>& deque);

}