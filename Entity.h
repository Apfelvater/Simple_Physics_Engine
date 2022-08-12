#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include "Atom.h"

class Entity: public Atom {

    private:
    int size_x;
    int size_y;

    public:
    Entity();
    Entity(int x, int y);
    
};

#endif