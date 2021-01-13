//
// Created by Ivan Sandev on 1/9/21.
//

#include "../include/Tape.h"

void Tape::show() {
    Item::show();
    cout << "Capacity (in minutes): " << capacityMinutes;
}

int Tape::getCapacityMinutes() const {
    return capacityMinutes;
}

void Tape::setCapacityMinutes(int capacityMinutes) {
    Tape::capacityMinutes = capacityMinutes;
}

