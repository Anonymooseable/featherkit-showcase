#include "collisionpoint.h"

CollisionPoint::CollisionPoint()
{
    falling = false;
}

CollisionPoint::CollisionPoint(glm::vec2 position)
{
    point = position;
    falling = false;
}
