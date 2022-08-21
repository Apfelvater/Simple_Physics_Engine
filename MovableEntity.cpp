#include "MovableEntity.h"

// ------------------ Energy Application ------------------
void MovableEntity::move(float dx, float dy) {
    pos.x += dx;
    pos.y += dy;
    // TODO: Check for out of bounds here ?! or when drawing field ?
    // IDEA: return != 0 if out of bounds
}

void MovableEntity::apply_velocity(float dtime) {
    pos.x += velocity[0] * dtime;
    pos.y += velocity[1] * dtime;
}

void MovableEntity::accelerate(int dir, float acceleration, float dtime = 1) {
    if (dir >= velocity.size()) return;
    velocity[dir] += acceleration / dtime;
}