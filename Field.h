#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include "Entity.h"

class Field {

    private:
    char * buf_cout;
    bool buf_updated = false; // To determine wether the field-print-buffer was updated since the last drawing of the field
    const float resolution_factor = 1.34;
    int max_y;
    int max_x;
    vector<vector<Entity*>>* field_vector;

    void init(int x, int y);

    public:
    Field(int x, int y);
    Field(int size);
    ~Field();

    void draw_field();
    void draw_updates();
    void init_buf();
    void update_value(int x, int y, Entity* value);
    void update_buf();
};

#endif