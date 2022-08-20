// Main.cpp

#include <iostream>
#include <unistd.h>
#include <thread>
#include <vector>
#include "Field.h"
#include "Entity.h"


#define TEST_FIELD_SIZE 6

using namespace std;

void field_builder(Field field) {
    while(true) {
        field.draw_updates();
    }
}

int main() {
/**
    // System Test Start <>
    vector<Entity> movables; // Use this for multiple movables
    Entity MyMovable((int) TEST_FIELD_SIZE/2, (int) TEST_FIELD_SIZE/2);
    Entity M2(1, 2);
    movables.push_back(MyMovable);
    movables.push_back(M2);

    for (Entity e : movables) {
        // Draw each
    }

    return 0;
    // System Test End </>
**/

    // Initialisation
    Field field(TEST_FIELD_SIZE);
    field.init_buf();
    field.draw_field();
    return 0;

    thread builder_thread(field_builder, field);
    //start all the other threads
    builder_thread.join();

    return 0;
}