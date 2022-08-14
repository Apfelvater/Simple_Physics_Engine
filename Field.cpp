#include "Field.h"
#include "Point.h"
#include <iostream>
#include <vector>

#define INIT_CHAR 0

using namespace std;

// --------------- Con/Destructors ---------------
Field::Field(int x, int y) {
    cout << "Constructing...\n";
    max_x = x;
    max_y = y;
    field_vector = new  vector<vector<Point>>(y, vector<Point>(x, Point()));
    cout << "...constructed.\n";
}
Field::Field(int size) : Field((int) size * resolution_factor, size) {}
Field::~Field() {
    cout << "Destructing...\n";
    delete field_vector;
    cout << "...destructed.\n";
}


// --------------- methods ---------------
void Field::update_spot(int x, int y, Point value) {
    (*field_vector)[x][y] = Point(value);
}

void Field::draw_field() {
    char* cout_string = (char*) malloc(max_y * (max_x + 1)); // #max_size characters + "\n" TODO: Windows "\n\r" ?
    for(int i = 0; i < max_y; i++) {
        for(int j = 0; j < max_x; j++) {
            cout_string[i * (max_x+1) + j] = field_vector->at(i).at(j).toChar();
        }
        cout_string[i * (max_x+1) + max_x] = '\n';
    }
    cout << cout_string;
    free(cout_string);
    updated = false;
}

void Field::draw_updates() {
    if (updated) draw_field();
}