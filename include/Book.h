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
        setType("book");

        cout << "Edition: ";
        cin >> edition;
        while (cin.fail()) {
            cout << "Edition should be a number only.\nEdition: ";
            if (!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cin >> edition;
        }

        cout << "Pages: ";
        cin >> pages;
        while (cin.fail()) {
            cout << "Pages should be a number.\nPages: ";
            if (!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cin >> pages;
        }

        cout << "Genre: ";
        cin.ignore();
        getline(cin, genre);
        if (genre.length() == 0) {
            cout << "No genre given. Defaulting to 'non-fiction'" << endl;
            genre = "Non-fiction";
        }

        cout << "Publisher: ";
        getline(cin, publisher);
        if (publisher.length() == 0) {
            cout << "No publisher given. Defaulting to 'none'" << endl;
            genre = "none";
        }
    }


    void show();
    void saveToFile(std::ostream &dataFile);

    // GETTERS / SETTERS
    const string &getGenre() const;
    void setGenre(const string &genre);
};


#endif //DIGITAL_LIBRARY_BOOK_H
