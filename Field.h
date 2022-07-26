/**
 * @file Field.h
 * @author Apfelvater
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 * USAGE:
 * -init_buf() #initiates cout buffer
 * -draw_field() #to draw empty field
 * -update_value(x, y, entity) #to add a value to the field
 * -draw_updates() #to draw if field has changed
 * 
 */

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

    Entity* get_entity_at(Position pos);
    Entity* get_entity_at(float x, float y);
    Entity* get_entity_at(int x, int y);
    void draw_field();
    void draw_updates();
    void init_buf();
    void update_value(Entity* value);
    void update_value_at(int x, int y, Entity* value);
    void update_value_at(Position pos, Entity* value);
    int move_from_to(Position from, Position to);
    void swap_entities(Position p1, Position p2);
};

#endif