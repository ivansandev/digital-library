//
// Created by Ivan Sandev on 1/9/21.
//

#ifndef DIGITAL_LIBRARY_VIDEOTAPE_H
#define DIGITAL_LIBRARY_VIDEOTAPE_H

#include "Tape.h"

using std::cout;
using std::cin;
using std::endl;

class Videotape : public Tape {
private:
    bool isVHS;
public:
    Videotape() : Tape()
    {
        setType("videotape");

        cout << "Is it a VHS tape? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
            isVHS = true;
        else
            isVHS = false;
    }

    Videotape(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
              int stockCounter, int rentedCounter, int capacityMinutes, bool isVhs);

    void show();

    // GETTERS / SETTERS
    bool isVhs() const;
    void setIsVhs(bool isVhs);

    void saveToFile(ostream &dataFile);
};


#endif //DIGITAL_LIBRARY_VIDEOTAPE_H
