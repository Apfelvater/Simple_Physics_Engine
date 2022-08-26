// Main.cpp

#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <vector>
#include "Field.h"
#include "MovableEntity.h"


#define TEST_FIELD_SIZE 6

using namespace std;

void field_builder(Field field) {
    while(true) {
        field.draw_updates();
        usleep(50);
    }
}

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}

int main() {
//TODO: System Test mit Field!

    // System Test Start <>
    vector<MovableEntity> movables; // Use this for multiple movables
    MovableEntity MyMovable(TEST_FIELD_SIZE/2, TEST_FIELD_SIZE/2);
    MovableEntity M2(1.5, 2.7);
    movables.push_back(MyMovable);
    movables.push_back(M2);

    clear();
    cout << "\n\n\t- Simple Physics Engine -\n";
    usleep(5000000);
    clear();
    // Initialisation
    Field field(TEST_FIELD_SIZE);
    field.init_buf();
    field.draw_field();

    usleep(1000000);

    for (int isec = 0; isec < 10; isec++) {
        for (MovableEntity e : movables) {
            clear();
            field.update_value(&e);
            field.draw_updates();

            usleep(1000000);
        }
    }

    return 0;
    // System Test End </>

/**
    // Initialisation
    Field field(TEST_FIELD_SIZE);
    field.init_buf();
    field.draw_field();
    return 0;

    thread builder_thread(field_builder, field);
    //start all the other threads
    builder_thread.join();

    return 0;**/
}