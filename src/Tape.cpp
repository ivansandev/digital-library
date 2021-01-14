//
// Created by Ivan Sandev on 1/9/21.
//

#include "../include/Tape.h"

void Tape::show() {
    Item::show();
    cout << "CAPACITY (in minutes): " << capacityMinutes << endl;
}

int Tape::getCapacityMinutes() const {
    return capacityMinutes;
}

void Tape::setCapacityMinutes(int capacityMinutes) {
    Tape::capacityMinutes = capacityMinutes;
}

Tape::Tape(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
           int stockCounter, int rentedCounter, int capacityMinutes)
           : Item(type, title, authors, language, releaseYear, stockCounter, rentedCounter),
           capacityMinutes(capacityMinutes) {}

void Tape::saveToFile(ostream &dataFile) {
    Item::saveToFile(dataFile);
    dataFile << capacityMinutes << endl;
    dataFile << "$$" << endl;
}

