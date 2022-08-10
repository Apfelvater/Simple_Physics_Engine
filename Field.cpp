#include "Field.h"
#include <iostream>
#include <vector>
#include <typeinfo> // TODELETE

#define INIT_CHAR 0
#define resolution_factor 1.33 // TODO put this elsewhere and modifiable, 1.33 = 4/3

using namespace std;

Field::Field(int x, int y) {
    cout << "Constructing...\n";
    max_x = x;
    max_y = y;
    field_vector = new  vector<vector<Point>>(y, vector<Point>(x, Point(INIT_CHAR)));
    cout << "...constructed.\n";
}
Field::Field(int size) : Field((int) size * resolution_factor, size) {}
Field::~Field() {
    cout << "Destructing...\n";
    delete field_vector;
    cout << "...destructed.\n";
}

void Field::draw_field() {
    char* cout_string = (char*) malloc(max_y * (max_x + 1)); // #max_size characters + "\n" TODO: Windows "\n\r" ?
    for(int i = 0; i < max_y; i++) {
        for(int j = 0; j < max_x; j++) {
            cout_string[i * (max_x+1) + j] = (char) field_vector->at(i).at(j).toChar();
        }
        cout_string[i * (max_x+1) + max_x] = '\n';
    }
    cout << cout_string;
    cout << typeid(cout_string[0]).name();
    free(cout_string);
}


int main() {
    int size;
    cin>>size;
    Field f(size);
    f.draw_field();
    return 0;
}