#include "MovableEntity.h"

MovableEntity::MovableEntity() : Entity() {}

MovableEntity::MovableEntity(float x, float y) : Entity(x, y) {}

MovableEntity::MovableEntity(float x, float y, float w) : Entity(x, y, w) {}


// ------------------ Energy Application ------------------
void MovableEntity::move(float dx, float dy) {
    pos.x += dx;
    pos.y += dy;
    // TODO: Check for out of bounds here ?! or when drawing field ?
    // IDEA: return != 0 if out of bounds
}

void MovableEntity::apply_force(float dtime) {
    // set force und dann update oder hier direkt accel berechnen? TODO!!
}

/*void MovableEntity::apply_velocity(float dtime) {
    pos.x += velocity[0] * dtime;
    pos.y += velocity[1] * dtime;
}*/

void MovableEntity::accelerate(int dir, float acceleration, float dtime = 1) {
    if (dir >= velocity.size()) return;
    velocity[dir] += acceleration / dtime;
}

vector<float> MovableEntity::get_force() {
    return force;
}

vector<float> MovableEntity::get_acceleration() {
    return acceleration;
}

vector<float> MovableEntity::get_velocity() {
    return velocity;
}
