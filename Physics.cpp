#include "Physics.h"

using namespace std;

float Physics::get_distance_by_v(float dtime, float velocity) {
    // Get Distance traveled in dtime with constant velocity
    return dtime * velocity;
}

float Physics::get_distance_by_a(float dtime, float acceleration) {
    // Get Distance traveled in dtime with constant acceleration
    return dtime * dtime * acceleration;
}