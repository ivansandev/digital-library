//
// Created by Ivan Sandev on 1/9/21.
//

#include "../include/CD.h"

void CD::show() {
    AudioCD::show();
    cout << "Resolution: " << resolution << endl;
}

const string &CD::getResolution() const {
    return resolution;
}

void CD::setResolution(const string &resolution) {
    CD::resolution = resolution;
}

CD::CD(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
       int stockCounter, int rentedCounter, int audioBitrate, float sizeInMb, const string &resolution) : AudioCD(type,
                                                                                                                  title,
                                                                                                                  authors,
                                                                                                                  language,
                                                                                                                  releaseYear,
                                                                                                                  stockCounter,
                                                                                                                  rentedCounter,
                                                                                                                  audioBitrate,
                                                                                                                  sizeInMb),
                                                                                                          resolution(
                                                                                                                  resolution) {}


void CD::saveToFile(ostream &dataFile) {
    AudioCD::saveToFile(dataFile);
    dataFile << resolution << endl;
    dataFile << "$$" << endl;
}
