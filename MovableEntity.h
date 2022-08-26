#ifndef MOVABLE_ENTITY
#define MOVABLE_ENTITY

#include "Entity.h"
#include <vector>
#include <iostream>

using namespace std;

class MovableEntity : public Entity {

    private:
    vector<float> force{}; //TODELETE if energy model works
    vector<float> E_kin{};
    vector<float> acceleration{};
    vector<float> velocity{};

    public:
    MovableEntity();
    MovableEntity(float x, float y);
    MovableEntity(float x, float y, float w);

    vector<float> get_force(); //TODELETE if energy model works
    vector<float> get_energy();
    vector<float> get_acceleration();
    vector<float> get_velocity();
    void set_position(float x, float y);
    void set_force(vector<float> f);
    void set_force(float f, int d = 0);
    void set_velocity(vector<float> v);
    void set_acceleration(vector<float> a);
    
    // Energy Application:
    void apply_force(vector<float>* f, float dtime);
    //void move(float dtime);
    void accelerate(int dir, float acceleration, float dseconds);


};

#endif