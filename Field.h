#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include "Point.h"

class Field {

    private:
    bool updated = false; // To determine wether the matrix was updated since the last drawing of the field
    float resolution_factor = 4/3;
    int max_y;
    int max_x;
    vector<vector<Atom>>* field_vector;

    public:
    Field(int x, int y);
    Field(int size);
    ~Field();

    void draw_field();
    void draw_updates();
    void update_spot(int x, int y, Atom value);
};

#endif