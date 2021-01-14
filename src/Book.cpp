//
// Created by Ivan Sandev on 1/9/21.
//

#include "../include/Book.h"

const string &Book::getGenre() const {
    return genre;
}

void Book::setGenre(const string &genre) {
    Book::genre = genre;
}

void Book::show() {
    Item::show();
    cout << "GENRE: " << genre << endl;
    Printable::show();
}

void Book::saveToFile(ostream &dataFile) {
    Item::saveToFile(dataFile);
    dataFile << edition << endl;
    dataFile << pages << endl;
    dataFile << publisher << endl;
    dataFile << genre << endl;
    dataFile << "$$" << endl;
}

Book::Book(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
           int stockCounter, int rentedCounter, int edition, int pages, const string &publisher, const string &genre)
        : Item(type, title, authors, language, releaseYear, stockCounter, rentedCounter),
          Printable(edition, pages, publisher), genre(genre) {}
