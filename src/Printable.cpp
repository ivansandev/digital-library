//
// Created by Ivan Sandev on 1/11/21.
//

#include "../include/Printable.h"

int Printable::getEdition() const {
    return edition;
}

void Printable::setEdition(int edition) {
    Printable::edition = edition;
}

int Printable::getPages() const {
    return pages;
}

void Printable::setPages(int pages) {
    Printable::pages = pages;
}

int Printable::getFontSize() const {
    return fontSize;
}

void Printable::setFontSize(int fontSize) {
    Printable::fontSize = fontSize;
}

const string &Printable::getPublisher() const {
    return publisher;
}

void Printable::setPublisher(const string &publisher) {
    Printable::publisher = publisher;
}

void Printable::show() {
    cout << "Edition: " << edition << endl;
    cout << "Pages: " << pages << endl;
    cout << "Font size: " << fontSize << endl;
    cout << "Publisher: " << publisher << endl;
}