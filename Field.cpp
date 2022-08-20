#include "Field.h"
#include <iostream>
#include <vector>

#define INIT_CHAR 0

using namespace std;

// --------------- Con/Destructors ---------------
void Field::init(int x, int y) {
    cout << "Field with max_x = " << x << " and max_y = " << y << "\nResolution_Factor is " << resolution_factor << "\nConstructing...\n";
    max_x = x;
    max_y = y;
    buf_cout = (char*) malloc(y * (x + 1)); // #max_x characters + "\n" TODO: Windows "\n\r" ?
    field_vector = new  vector<vector<Entity *>>(y, vector<Entity *>(x, NULL));
    cout << "...constructed.\n";
}

Field::Field(int x, int y) {
    this->init(x, y);
}

Field::Field(int size) {
    this->init(size * resolution_factor, size);
}

Field::~Field() {
    cout << "Destructing...\n";
    free(buf_cout);
    delete field_vector;
    cout << "...destructed.\n";
}


// --------------- methods ---------------
void Field::update_value(int x, int y, Entity* value) {
    (*field_vector)[x][y] = value;
    buf_cout[y * (max_x + 1) + x] = value->toChar();
}

void Field::init_buf() {
    cout << "max_y:" << max_y << '\n';
    for(int i = 0; i < max_y; i++) {
        cout << "i:" << i << ":";
        for(int j = 0; j < max_x; j++) {
            cout << "j:" << j;
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