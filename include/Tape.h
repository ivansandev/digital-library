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
        cout << "Capacity (in minutes): ";
        cin >> capacityMinutes;
    }

    virtual void show();

    // GETTERS / SETTERS
    int getCapacityMinutes() const;
    void setCapacityMinutes(int capacityMinutes);
};


#endif //DIGITAL_LIBRARY_TAPE_H
