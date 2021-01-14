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
        setType("magazine");

        cout << "Owner: ";
        getline(cin, owner);

        cout << "Subscribers: ";
        getline(cin, monthlySubscribers);

        cout << "Edition: ";
        cin >> edition;

        cout << "Pages: ";
        cin >> pages;

        cout << "Publisher: ";
        cin.ignore();
        getline(cin, publisher);
    }

    Magazine(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
             int stockCounter, int rentedCounter, const string &owner, const string &monthlySubscribers);

    // GETTERS / SETTERS
    const string &getOwner() const;
    void setOwner(const string &owner);
    const string &getMonthlySubscribers() const;
    void setMonthlySubscribers(const string &monthlySubscribers);

    void show();

    void saveToFile(ostream &dataFile);
};


#endif //DIGITAL_LIBRARY_MAGAZINE_H
