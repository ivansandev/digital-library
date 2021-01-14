#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::string;

#ifndef DIGITAL_LIBRARY_MEDIA_H
#define DIGITAL_LIBRARY_MEDIA_H

// enum MEDIA_TYPE{"Book", "Audiobook", "Magazine", "CD", "Audio-CD", "Tape", "Videotape"};

class Item {
private:
    string type;
    string title;
    string authors;
    string language;
    int releaseYear;
    int stockCounter;
    int rentedCounter;
public:
    Item();

    Item(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
         int stockCounter, int rentedCounter);
    // Constructor with all parameters (used for reading from file)

    virtual void show();
    void changeStock();
    std::string getAvailability() const;
    void rentItem();
    void returnItem();
    Item operator--(int notused);
    Item operator++(int notused);
    friend std::ostream &operator<<(std::ostream &os, const Item &item);
    bool isItem(string criteria);
    virtual void saveToFile(std::ostream &dataFile);

    // GETTERS / SETTERS
    const string &getType() const;
    void setType(const string &type);
    const string &getTitle() const;
    void setTitle(const string &title);
    const string &getAuthors() const;
    void setAuthors(const string &authors);
    const string &getLanguage() const;
    void setLanguage(const string &language);
    int getReleaseYear() const;
    void setReleaseYear(int releaseYear);
    int getStockCounter() const;
    void setStockCounter(int stockCounter);
    int getRentedCounter() const;
    void setRentedCounter(int rentedCounter);

    // TODO: Overload << operator
    bool isStock() const;

};


#endif //DIGITAL_LIBRARY_MEDIA_H
