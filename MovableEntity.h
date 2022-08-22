#ifndef MOVABLE_ENTITY
#define MOVABLE_ENTITY

#include "Entity.h"
#include <vector>
#include <iostream>

using namespace std;

class MovableEntity : public Entity {

    private:
    vector<float> force{};
    vector<float> acceleration{};
    vector<float> velocity{};

    public:
    MovableEntity();
    MovableEntity(float x, float y);
    MovableEntity(float x, float y, float w);

    vector<float> get_force();
    vector<float> get_acceleration();
    vector<float> get_velocity();
    
    // Energy Application:
    void apply_force(float dtime);
    void move(float dx, float dy);
    void accelerate(int dir, float acceleration, float dseconds);

};

#endif