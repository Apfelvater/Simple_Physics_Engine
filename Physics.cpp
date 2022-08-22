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

vector<float> Physics::get_distance_by_v(float dtime, vector<float> velocity) {
    vector<float> distance(velocity.size());
    for (int i = 0; i < velocity.size(); i++) {
        distance[i] = velocity[i] * dtime;
    }
    return distance;
}

vector<float> Physics::get_distance_by_a(float dtime, vector<float> acceleration) {
    vector<float> distance(acceleration.size());
    for (int i = 0; i < acceleration.size(); i++) {
        distance[i] = acceleration[i] * dtime * dtime;
    }
    return distance;
}