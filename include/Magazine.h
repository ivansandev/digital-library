//
// Created by Ivan Sandev on 1/9/21.
//

#ifndef DIGITAL_LIBRARY_MAGAZINE_H
#define DIGITAL_LIBRARY_MAGAZINE_H

#include "Item.h"
#include "Printable.h"

class Magazine : public Item, Printable {
private:
    string owner;
    string monthlySubscribers;
public:
    Magazine() : Item()
    {
        cout << "Owner: ";
        getline(cin, owner);
        cout << "Subscribers: ";
        getline(cin, monthlySubscribers);
    }

    // GETTERS / SETTERS
    const string &getOwner() const;
    void setOwner(const string &owner);
    const string &getMonthlySubscribers() const;
    void setMonthlySubscribers(const string &monthlySubscribers);

    void show();
};


#endif //DIGITAL_LIBRARY_MAGAZINE_H
