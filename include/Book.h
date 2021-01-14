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
    Book() : Item(), Printable()
    {
        setType("book");

        cout << "Genre: ";
        cin.ignore();
        getline(cin, genre);
        if (genre.length() == 0) {
            cout << "No genre given. Defaulting to 'non-fiction'" << endl;
            genre = "Non-fiction";
        }
    }

    Book(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
         int stockCounter, int rentedCounter, int edition, int pages, const string &publisher, const string &genre);


    void show();
    void saveToFile(std::ostream &dataFile);

    // GETTERS / SETTERS
    const string &getGenre() const;
    void setGenre(const string &genre);
};


#endif //DIGITAL_LIBRARY_BOOK_H
