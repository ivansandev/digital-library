#include <iostream>
#include <string>
#include <vector>

using std::string;

#ifndef DIGITAL_LIBRARY_MEDIA_H
#define DIGITAL_LIBRARY_MEDIA_H

// enum MEDIA_TYPE{"Book", "Audiobook", "Magazine", "CD", "Audio-CD", "Tape", "Videotape"};

class Item {
private:
    string mediaType;
    string title;
    string authors;
    string category;
    string language;
    int releaseYear;
    int stockCounter;
    int rentedCounter;
    int rating[5] = {0};
    // Item *next;
public:
    Item();

    // Constructor with all parameters (used for reading from file)

    virtual void show();
    void changeStock();
    bool checkAvailability() const;
    void rentItem();
    void returnItem();
    Item operator--(int notused);
    Item operator++(int notused);

    virtual string formatDataForFile();

    // GETTERS / SETTERS
    const string &getMediaType() const;
    void setMediaType(const string &mediaType);
    const string &getTitle() const;
    void setTitle(const string &title);
    const string &getAuthors() const;
    void setAuthors(const string &authors);
    const string &getCategory() const;
    void setCategory(const string &category);
    const string &getLanguage() const;
    void setLanguage(const string &language);
    int getReleaseYear() const;
    void setReleaseYear(int releaseYear);
    int getStockCounter() const;
    void setStockCounter(int stockCounter);
    int getRentedCounter() const;
    void setRentedCounter(int rentedCounter);

    // TODO: Overload << operator
};


#endif //DIGITAL_LIBRARY_MEDIA_H
