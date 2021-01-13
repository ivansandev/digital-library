//
// Created by Ivan Sandev on 1/9/21.
//

#include "../include/Magazine.h"

// GETTERS / SETTERS

const string &Magazine::getOwner() const {
    return owner;
}

void Magazine::setOwner(const string &owner) {
    Magazine::owner = owner;
}

const string &Magazine::getMonthlySubscribers() const {
    return monthlySubscribers;
}

void Magazine::setMonthlySubscribers(const string &monthlySubscribers) {
    Magazine::monthlySubscribers = monthlySubscribers;
}

// METHODS

void Magazine::show() {
    Item::show();
    cout << "Owner: " << owner << endl;
    cout << "Subscribers: " << monthlySubscribers << endl;
    Printable::show();
}
