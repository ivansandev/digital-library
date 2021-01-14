#include "../include/Item.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Item::Item() {
    rentedCounter = 0;
    string new_title;
    string new_authors;
    string new_category;
    string new_language;
    int new_releaseYear;
    int new_stock;

    // TODO: Input data validation
    cin.ignore();

    cout << "Title: ";
    getline(cin, title);
    while (title.length() == 0) {
        cout << "No title given. Please enter a title.\nTitle: ";
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        getline(cin, title);
    }

    cout << "Authors: ";
    getline(cin, authors);
    while (authors.length() == 0) {
        cout << "No authors given. Please enter authors.\nAuthors: ";
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        getline(cin, authors);
    }

    cout << "Language: ";
    getline(cin, language);
    if (language.length() == 0) {
        cout << "No language set. Language defaulted for 'English'" << endl;
        language = "English";
    }

    cout << "Release year: ";
    cin >> releaseYear;
    while (releaseYear < 1000 || releaseYear > 2100 || cin.fail()) {
        cout << "Incorrect release year entered. Please enter a correct year\nRelease year: ";
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cin >> releaseYear;
    }

    cout << "Stock: ";
    cin >> stockCounter;
    while (stockCounter < 0) {
        cout << "Incorrect stock number entered. Stock should be 0 or above.\nStock: ";
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cin >> stockCounter;
    }
    cin.ignore();
}

void Item::changeStock() {
    show();
    cout << "New stock: ";
    cin >> stockCounter;
    while (stockCounter < 0) {
        cout << "Stock number should be 0 or above 0. Try again..." << endl;
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cin >> stockCounter;
    }
}

std::string Item::getAvailability() const {
    if (isStock())
        return "available";
    return "unavailable";
}

bool Item::isStock() const {
    if (stockCounter > 0)
        return true;
    return false;
}

void Item::show() {
    cout << "TITLE: " << title << endl;
    cout << "AUTHOR: " << authors << endl;
    cout << "YEAR: " << releaseYear << endl;
    cout << "STATUS: ";
    if (stockCounter > 0)
        cout << "Available." << endl;
    else
        cout << "Unavailable." << endl;
    cout << "LANGUAGE: " << language << endl;
    cout << "DOWNLOADS / RENTS: " << rentedCounter << endl;
    cout << "STOCK: " << stockCounter << endl;
}

void Item::rentItem() {
    if (stockCounter > 0) {
        stockCounter--;
        rentedCounter++;
        cout << "Item rented." << endl << "Current stock: " << stockCounter << endl;
    } else {
        cout << "There is no stock of the selected item." << endl;
    }
}

void Item::returnItem() {
    stockCounter++;
    cout << "Item returned." << endl << "Current stock: " << stockCounter << endl;
}

bool Item::isItem(string criteria) {
    std::string lowerTitle = title;
    std::string lowerAuthors = authors;

    transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
    transform(lowerAuthors.begin(), lowerAuthors.end(), lowerAuthors.begin(), ::tolower);
    transform(criteria.begin(), criteria.end(), criteria.begin(), ::tolower);

    if (lowerTitle.find(criteria) != std::string::npos) {
        return true;
    }
    if (lowerAuthors.find(criteria) != std::string::npos) {
        return true;
    }
    return false;
}

Item Item::operator--(int notused) {
    rentItem();
    return *this;
}

Item Item::operator++(int notused) {
    returnItem();
    return *this;
}

void Item::saveToFile(std::ostream& dataFile) {
    dataFile << type << endl;
    dataFile << title << endl;
    dataFile << authors << endl;
    dataFile << language << endl;
    dataFile << releaseYear << endl;
    dataFile << stockCounter << endl;
    dataFile << rentedCounter << endl;
}

std::ostream &operator<<(std::ostream &os, const Item &item) {
    os << item.type << "  >  " << item.title << ", " << item.authors << ", " << item.releaseYear << ", "
       << item.getAvailability() << endl;
    return os;
}

// GETTERS / SETTERS
const string &Item::getType() const {
    return type;
}

void Item::setType(const string &type) {
    Item::type = type;
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

Item::Item(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
           int stockCounter, int rentedCounter) : type(type), title(title), authors(authors), language(language),
                                                  releaseYear(releaseYear), stockCounter(stockCounter),
                                                  rentedCounter(rentedCounter) {}


