#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct Position {
    float x;
    float y;

    string toString() {
        stringstream ss;
        ss << "x=" << x << ", y=" << y;
        return ss.str();
    }
};

class Entity {

    protected:

    float weight;
    Position pos{};

    public:

    Entity();
    Entity(int x, int y);
    Entity(int x, int y, float w);
    
    float getWeight();
    void setWeight(float w);
    Position getPos();

    char toChar();
};

#endif