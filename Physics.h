#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>

using namespace std;

class Physics {

    static float get_distance_by_v(float dtime, float velocity);
    static float get_distance_by_a(float dtime, float acceleration);

    static vector<float> get_distance_by_v(float dtime, vector<float> velocity);
    static vector<float> get_distance_by_a(float dtime, vector<float> acceleration);

};

#endif