#include "Field.h"
#include "Utils.cpp"
#include <iostream>
#include <vector>

#define INIT_CHAR 0

using namespace std;


// --------------- Con/Destructors ---------------
void Field::init(int x, int y) {
    //cout << "Field with max_x = " << x << " and max_y = " << y << "\nResolution_Factor is " << resolution_factor << "\nConstructing...\n";
    max_x = x;
    max_y = y;
    buf_cout = (char*) malloc(y * (x + 1)); // #max_x characters + "\n" TODO: Windows "\n\r" ?
    field_vector = new  vector<vector<Entity *>>(y, vector<Entity *>(x, NULL));
    //cout << "...constructed.\n";
}

Field::Field(int x, int y) {
    this->init(x, y);
}

Field::Field(int size) {
    this->init(size * resolution_factor, size);
}

Field::~Field() {
    //cout << "Destructing...\n";
    free(buf_cout);
    delete field_vector;
    //cout << "...destructed.\n";
}


// --------------- methods ---------------
Entity* Field::get_entity_at(Position pos) {
    return this->get_entity_at(pos.x, pos.y);
}

Entity* Field::get_entity_at(float x, float y) {
    return this->get_entity_at(Utils::round_floatToInt(x), Utils::round_floatToInt(y));
}

Entity* Field::get_entity_at(int x, int y) {
    return (*field_vector)[x][y];
}

void Field::update_value_at(int x, int y, Entity* value) {
    (*field_vector)[x][y] = value;
    buf_cout[y * (max_x + 1) + x] = value->toChar();
    buf_updated = true;
}

void Field::update_value_at(Position pos, Entity* value) {
    int x = Utils::round_floatToInt(pos.x);
    int y = Utils::round_floatToInt(pos.y);
    (*field_vector)[x][y] = value;
    buf_cout[y * (max_x + 1) + x] = value->toChar();
    buf_updated = true;
}

void Field::update_value(Entity* value) {
    if (value == NULL) return;
    Position pos = value->getPos();
    int x = Utils::round_floatToInt(pos.x);
    int y = Utils::round_floatToInt(pos.y);
    this->update_value_at(x, y, value);
}

int Field::move_from_to(Position from, Position to) {
    // Stores Entity found at Position from at Position to and leaves a NULL (or background Entity* (TODO)) at Position from.
    // @return Indicator for what is at Position to: 
    // 0 - NULL / BackgroundEntity
    // 1 - Any other Entity
    int returncode = 0;
    if (this->get_entity_at(to) != NULL) returncode = 1;
    this->update_value_at(to, this->get_entity_at(from));
    this->update_value_at(from, NULL);
    return returncode;
}

void Field::swap_entities(Position p1, Position p2) {
    Entity* tmp = this->get_entity_at(p2);
    this->update_value_at(p2, this->get_entity_at(p1));
    this->update_value_at(p1, tmp);
}

void Field::init_buf() {
    for(int i = 0; i < max_y; i++) {
        for(int j = 0; j < max_x; j++) {
            if (field_vector->at(i).at(j) != NULL)
                buf_cout[i * (max_x+1) + j] = field_vector->at(i).at(j)->toChar();
            else 
                buf_cout[i * (max_x+1) + j] = '0';
        }
        buf_cout[i * (max_x+1) + max_x] = '\n';
    }
}

void Field::draw_field() {
    cout << buf_cout;
    buf_updated = false;
}

void Field::draw_updates() {
    if (buf_updated) draw_field();
}