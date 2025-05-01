#include "VectorUtils.h"

#include "raymath.h"

namespace VectorUtils {
    bool FindElementInDeque(const Vector2 position, const std::deque<Vector2>& deque) {
        for (const auto& element : deque) {
            if (Vector2Equals(element, position)) {
                return true;
            }
        }
        return false;
    }
}
