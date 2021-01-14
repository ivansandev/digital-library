//
// Created by Ivan Sandev on 1/9/21.
//

#ifndef DIGITAL_LIBRARY_CD_H
#define DIGITAL_LIBRARY_CD_H

#include "Item.h"
#include "AudioCD.h"

class CD : public AudioCD {
private:
    string resolution;
public:
    CD() : AudioCD()
    {
        setType("cd");

        cout << "Resolution: ";
        cin.ignore();
        getline(cin, resolution);
    }

    CD(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
       int stockCounter, int rentedCounter, int audioBitrate, float sizeInMb, const string &resolution);

    void show();

    // GETTERS / SETTERS
    const string &getResolution() const;
    void setResolution(const string &resolution);

    void saveToFile(ostream &dataFile);
};


#endif //DIGITAL_LIBRARY_CD_H
