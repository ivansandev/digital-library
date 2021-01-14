//
// Created by Ivan Sandev on 1/9/21.
//

#include "../include/Videotape.h"

void Videotape::show()
{
    Tape::show();
    if (isVHS)
        cout << "VHS: yes" << endl;
    else
        cout << "VHS: no" << endl;
}

bool Videotape::isVhs() const {
    return isVHS;
}

void Videotape::setIsVhs(bool isVhs) {
    isVHS = isVhs;
}

Videotape::Videotape(const string &type, const string &title, const string &authors, const string &language,
                     int releaseYear, int stockCounter, int rentedCounter, int capacityMinutes, bool isVhs) : Tape(type,
                                                                                                                   title,
                                                                                                                   authors,
                                                                                                                   language,
                                                                                                                   releaseYear,
                                                                                                                   stockCounter,
                                                                                                                   rentedCounter,
                                                                                                                   capacityMinutes),
                                                                                                              isVHS(isVhs) {}

void Videotape::saveToFile(ostream &dataFile) {
    Tape::saveToFile(dataFile);
    dataFile << isVHS << endl;
    dataFile << "$$" << endl;
}
