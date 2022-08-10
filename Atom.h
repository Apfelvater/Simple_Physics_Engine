#ifndef ATOM_H
#define ATOM_H

#include <vector>

struct Position {
    float x;
    float y;
};

class Atom {

    private:

    Position pos;
    std::vector<float> velocity;
    std::vector<float> force;
    float weight;


    public:

    Atom(Position p);
    Atom(int x, int y);
    Atom(int x, int y, float w);

    // Getter/Setter:
    float getWeight();
    void setWeight(float w);
    Position getPos();
    std::vector<float> getVelocity();
    std::vector<float> getForce();

    // Energy Application:
    void move(float dx, float dy);
    void accelerate(int dir, float acceleration, float dseconds);
    

};

#endif