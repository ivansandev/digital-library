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
        cout << "Resolution: ";
        cin >> resolution;
    }

    void show();

    // GETTERS / SETTERS
    const string &getResolution() const;
    void setResolution(const string &resolution);
};


#endif //DIGITAL_LIBRARY_CD_H
