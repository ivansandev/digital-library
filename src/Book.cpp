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
    cout << "Genre: " << genre << endl;
    Printable::show();
}
