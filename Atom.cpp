#include "Atom.h"
#include <iostream>

using namespace std;


// ------------------ Constructors ------------------
Atom::Atom() {
    pos = Position();
    pos.x = pos.y = -1;
    velocity = {0, 0};
    weight = 1;
}

Atom::Atom(Position p) {
    pos = Position();
    pos.x = p.x;
    pos.y = p.y;
    velocity = {0, 0};
    weight = 1;
}

Atom::Atom(int x, int y) {
    pos = Position();
    pos.x = (float) x;
    pos.y = (float) y;
    velocity = {0, 0};
    weight = 1;
}

Atom::Atom(int x, int y, float w) {
    pos = Position();
    pos.x = (float) x;
    pos.y = (float) y;
    velocity = {0, 0};
    weight = w;
}


// ------------------ Getter/Setter ------------------
Position Atom::getPos() {
    return pos;
}

vector<float> Atom::getVelocity() {
    return velocity;
}

vector<float> Atom::getForce() {
    return force;
}

void Atom::setWeight(float w) {
    weight = w;
}

char Atom::toChar() {
    return 'F';
}

string Atom::toString() {
    stringstream ss;
    ss << "Atom at pos. " << pos.toString() << " with weight: " << weight << "and velocity: (" << velocity[0] << " " << velocity[1] << ")\n";
    return ss.str();
}


// ------------------ Energy Application ------------------
void Atom::move(float dx, float dy) {
    pos.x += dx;
    pos.y += dy;
    // TODO: Check for out of bounds here ?! or when drawing field ?
    // IDEA: return != 0 if out of bounds
}

void Atom::accelerate(int dir, float acceleration, float dtime = 1) {
    if (dir >= velocity.size()) return;
    velocity[dir] += acceleration / dtime;
}

