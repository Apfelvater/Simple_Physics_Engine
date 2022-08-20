#include "Entity.h"
#include <iostream>

using namespace std;

Entity::Entity()
{
    weight = 1;
}

Entity::Entity(int x, int y) : Entity() {
    pos = {(float)x, (float)y};
    cout << "Entity created at pos (" << x << ":" << y << ")\n";
}

Entity::Entity(int x, int y, float w) : Entity(x, y) {
    weight = w;
}

Position Entity::getPos() {
    return pos;
}

float Entity::getWeight() {
    return weight;
}
    
void Entity::setWeight(float w) {
    weight = w;
}

char Entity::toChar() {
    return 'F';
}