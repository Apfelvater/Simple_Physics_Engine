// Main.cpp

#include <iostream>
#include <unistd.h>
#include <thread>
#include "Field.h"


using namespace std;

int main() {


    // Initialisation
    Field field(25);
    field.draw_field();

    thread builder_thread(field_builder, field);
    //start all the other threads
    builder_thread.join();

    return 0;
}

void field_builder(Field field) {
    while(true) {
        field.draw_updates();
    }
}