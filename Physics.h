#ifndef PHYSICS_H
#define PHYSICS_H

using namespace std;

class Physics {

    static float get_distance_by_v(float dtime, float velocity);

    static float get_distance_by_a(float dtime, float acceleration);

};

#endif