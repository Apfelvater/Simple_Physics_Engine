#include "MovableEntity.h"
#include "Physics.h"

MovableEntity::MovableEntity() : Entity() {}

MovableEntity::MovableEntity(float x, float y) : Entity(x, y) {}

MovableEntity::MovableEntity(float x, float y, float w) : Entity(x, y, w) {}


// ------------------ Energy Application ------------------
/*void MovableEntity::move(float dtime) {
    pos.x += dx;
    pos.y += dy;
    // TODO: Check for out of bounds here ?! or when drawing field ?
    // IDEA: return != 0 if out of bounds
}*/

void MovableEntity::apply_force(vector<float>* f, float dtime) {
    
}

void MovableEntity::accelerate(int dir, float acceleration, float dtime = 1) {
    if (dir >= velocity.size()) return;
    velocity[dir] += acceleration / dtime;
}

vector<float> MovableEntity::get_force() { //TODELETE if energy model works
    return force;
}

vector<float> MovableEntity::get_energy() {
    return E_kin;
}

vector<float> MovableEntity::get_acceleration() {
    return acceleration;
}

vector<float> MovableEntity::get_velocity() {
    return velocity;
}

void MovableEntity::set_position(float x, float y) {
    this->pos.x = x;
    this->pos.y = y;
}

void MovableEntity::set_force(vector<float> f) { //TODELETE if energy model works
    this->force = f;
}

void MovableEntity::set_velocity(vector<float> v) {
    this->velocity = v;
}

void MovableEntity::set_acceleration(vector<float> a) {
    this->acceleration = a;
}

