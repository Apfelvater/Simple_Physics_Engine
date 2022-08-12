// Main.cpp

#include <iostream>
#include <unistd.h>
#include <thread>
#include <vector>
#include "Field.h"
#include "Entity.h"


#define TEST_FIELD_SIZE 24

using namespace std;

void field_builder(Field field) {
    while(true) {
        field.draw_updates();
    }
}

int main() {

    vector<Entity> movables; // Use this for multiple movables
    Entity MyMovable((int) TEST_FIELD_SIZE/2, (int) TEST_FIELD_SIZE/2);
    Entity M2(1, 2);
    return 0;

    // Initialisation
    Field field(TEST_FIELD_SIZE);
    field.draw_field();

    thread builder_thread(field_builder, field);
    //start all the other threads
    builder_thread.join();

    return 0;
}