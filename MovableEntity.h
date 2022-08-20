#ifndef MOVABLE_ENTITY
#define MOVABLE_ENTITY

#include "Entity.h"
#include <vector>
#include <iostream>

using namespace std;

class MovableEntity : public Entity {

    private:
    
    vector<float> velocity;
    vector<float> force;

    public:

    vector<float> getVelocity();
    vector<float> getForce();
    
    // Energy Application:
    void move(float dx, float dy);
    void accelerate(int dir, float acceleration, float dseconds);

};

#endif