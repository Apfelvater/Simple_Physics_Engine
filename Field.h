#ifndef FIELD_H
#define FIELD_H

#include <vector>
#inlcude "Point.h"

class Field {

    private:
    float resolution_factor = 4/3;
    int max_y;
    int max_x;
    vector<vector<Point>>* field_vector;

    public:
    Field(int x, int y);
    Field(int size);
    ~Field();

    void draw_field();
}

#endif