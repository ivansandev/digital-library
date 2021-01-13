//
// Created by Ivan Sandev on 1/11/21.
//
#include <iostream>
#ifndef DIGITAL_LIBRARY_PRINTABLE_H
#define DIGITAL_LIBRARY_PRINTABLE_H
using namespace std;


class Printable {
private:
    int edition;
    int pages;
    int fontSize;
    string publisher;
public:
    int getEdition() const;
    void setEdition(int edition);
    int getPages() const;
    void setPages(int pages);
    int getFontSize() const;
    void setFontSize(int fontSize);
    const string &getPublisher() const;
    void setPublisher(const string &publisher);
    virtual void show();
    friend class Book;
    friend class Magazine;
};


#endif //DIGITAL_LIBRARY_PRINTABLE_H
