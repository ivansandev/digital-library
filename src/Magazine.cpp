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
    cout << "OWNER: " << owner << endl;
    cout << "SUBSCRIBERS: " << monthlySubscribers << endl;
    Printable::show();
}

Magazine::Magazine(const string &type, const string &title, const string &authors, const string &language,
                   int releaseYear, int stockCounter, int rentedCounter, int edition, int pages,
                   const string &publisher, const string &owner, const string &monthlySubscribers)
                    : Item(type, title, authors, language, releaseYear, stockCounter, rentedCounter),
                      Printable(edition, pages, publisher),
                      owner(owner),monthlySubscribers(monthlySubscribers) {}

void Magazine::saveToFile(ostream &dataFile) {
    Item::saveToFile(dataFile);
    dataFile << edition << endl;
    dataFile << pages << endl;
    dataFile << publisher << endl;
    dataFile << owner << endl;
    dataFile << monthlySubscribers << endl;
    dataFile << "$$" << endl;
}
