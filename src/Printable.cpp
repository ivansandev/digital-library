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


const string &Printable::getPublisher() const {
    return publisher;
}

void Printable::setPublisher(const string &publisher) {
    Printable::publisher = publisher;
}

void Printable::show() {
    cout << "EDITION: " << edition << endl;
    cout << "PAGES: " << pages << endl;
    cout << "PUBLISHER: " << publisher << endl;
}

Printable::Printable(int edition, int pages, const string &publisher)
            : edition(edition), pages(pages), publisher(publisher) {}

Printable::Printable() {
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

    cout << "Publisher: ";
    cin.ignore();
    getline(cin, publisher);
    if (publisher.length() == 0) {
        cout << "No publisher given. Defaulting to 'none'" << endl;
        publisher = "none";
    }
}
