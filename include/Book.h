//
// Created by Ivan Sandev on 1/9/21.
//

#ifndef DIGITAL_LIBRARY_BOOK_H
#define DIGITAL_LIBRARY_BOOK_H

#include "Item.h"
#include "Printable.h"

using namespace std;

class Book : public Item, Printable {
private:
    string genre;
public:
    Book() : Item()
    {
        cout << "Edition: ";
        cin >> edition;

        cout << "Pages: ";
        cin >> pages;

        cout << "Font size: ";
        cin >> fontSize;

        cout << "Genre: ";
        getline(cin, genre);

        cout << "Publisher: ";
        getline(cin, publisher);
    }

    void show();

    // GETTERS / SETTERS
    const string &getGenre() const;
    void setGenre(const string &genre);
};


#endif //DIGITAL_LIBRARY_BOOK_H
