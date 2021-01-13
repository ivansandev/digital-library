#include "../include/Item.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Item * Item::link(Item *item) {
//    item->next = this;
//    next = item;
//    return item;
//}

void Item::changeStock() {
    show();
    cout << "New stock: ";
    cin >> stockCounter;
    while (stockCounter < 0)
    {
        cout << "Stock number should be 0 or above 0. Try again..." << endl;
        cin >> stockCounter;
    }
}

bool Item::checkAvailability() const {
    if (stockCounter > 0)
        return true;
    return false;
}

void Item::show() {
    cout << "TITLE: " << title << endl;
    cout << "AUTHOR: " << authors << endl;
    cout << "CATEGORY: " << category << endl;
    cout << "YEAR: " << releaseYear << endl;
    cout << "STATUS: ";
    if (stockCounter > 0)
        cout << "Available." << endl;
    else
        cout << "Unavailable." << endl;
    cout << "LANGUAGE: " << language << endl;
}

void Item::rentItem() {
    if (stockCounter > 0) {
        stockCounter--;
        rentedCounter++;
        cout << "Item rented." << endl << "Current stock: " << stockCounter;
    } else {
        cout << "There is no stock of the selected item." << endl;
    }
}

void Item::returnItem() {
    cout << "Please rate this item (from 1 to 5, 0 for dismissing)." << endl;
    int newRating = 0;
    cin >> newRating;
    if (newRating != 0)
    {
        while(newRating < 1 || newRating > 5)
        {
            cout << "Invalid rating. Please input rating from 1 to 5, or 0 for dismissing." << endl;
            cin >> newRating;
        }
        rating[newRating]++;
    }
    stockCounter++;
}

Item Item::operator--(int notused) {
    rentItem();
    return *this;
}

Item Item::operator++(int notused) {
    returnItem();
    return *this;
}

Item::Item() {
    string new_title;
    string new_authors;
    string new_category;
    string new_language;
    int new_releaseYear;
    int new_stock;

    // TODO: Input data validation
    cout << "Title: ";
    getline(cin, new_title);
    title = new_title;

    cout << "Authors: ";
    getline(cin, new_authors);
    authors = new_authors;

    cout << "Category: ";
    getline(cin, new_category);
    category = new_category;

    cout << "Language: ";
    getline(cin, new_language);
    language = new_language;

    cout << "Release year: ";
    cin >> new_releaseYear;
    releaseYear = new_releaseYear;

    cout << "Stock: ";
    cin >> new_stock;
    stockCounter = new_stock;
}

string Item::formatDataForFile() {
    // TODO : Format data for file depending on item type
    return "";
}

// GETTERS / SETTERS
const string &Item::getMediaType() const {
    return mediaType;
}

void Item::setMediaType(const string &mediaType) {
    Item::mediaType = mediaType;
}

const string &Item::getTitle() const {
    return title;
}

void Item::setTitle(const string &title) {
    Item::title = title;
}

const string &Item::getAuthors() const {
    return authors;
}

void Item::setAuthors(const string &authors) {
    Item::authors = authors;
}

const string &Item::getCategory() const {
    return category;
}

void Item::setCategory(const string &category) {
    Item::category = category;
}

const string &Item::getLanguage() const {
    return language;
}

void Item::setLanguage(const string &language) {
    Item::language = language;
}

int Item::getReleaseYear() const {
    return releaseYear;
}

void Item::setReleaseYear(int releaseYear) {
    Item::releaseYear = releaseYear;
}

int Item::getStockCounter() const {
    return stockCounter;
}

void Item::setStockCounter(int stockCounter) {
    Item::stockCounter = stockCounter;
}

int Item::getRentedCounter() const {
    return rentedCounter;
}

void Item::setRentedCounter(int rentedCounter) {
    Item::rentedCounter = rentedCounter;
}


