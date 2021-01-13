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

