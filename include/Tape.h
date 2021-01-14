//
// Created by Ivan Sandev on 1/9/21.
//

#ifndef DIGITAL_LIBRARY_TAPE_H
#define DIGITAL_LIBRARY_TAPE_H

#include "Item.h"
using namespace std;

class Tape : public Item {
private:
    int capacityMinutes;
public:
    Tape() : Item()
    {
        setType("tape");

        cout << "Capacity (in minutes): ";
        cin >> capacityMinutes;
    }

    Tape(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
         int stockCounter, int rentedCounter, int capacityMinutes);

    virtual void show();

    // GETTERS / SETTERS
    int getCapacityMinutes() const;
    void setCapacityMinutes(int capacityMinutes);

    void saveToFile(ostream &dataFile);
};


#endif //DIGITAL_LIBRARY_TAPE_H
