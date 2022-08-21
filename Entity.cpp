#include "Entity.h"
#include <iostream>

using namespace std;

Entity::Entity()
{
    weight = 1;
}

Entity::Entity(float x, float y) : Entity() {
    pos = {x, y};
    cout << "Entity created at pos (" << x << ":" << y << ")\n";
}

Entity::Entity(float x, float y, float w) : Entity(x, y) {
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