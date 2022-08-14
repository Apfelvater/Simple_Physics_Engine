#include "Entity.h"
#include <iostream>

using namespace std;

Entity::Entity() : Atom() {}
Entity::Entity(int x, int y) : Atom(x, y) {
    cout << "Entity created at pos (" << x << ":" << y << ")\n";
}