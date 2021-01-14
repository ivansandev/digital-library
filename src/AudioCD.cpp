//
// Created by Ivan Sandev on 1/9/21.
//

#include "../include/AudioCD.h"

void AudioCD::show() {
    Item::show();
    cout << "BITRATE: " << audioBitrate << endl;
    cout << "SIZE (MB): " << sizeInMB << endl;
}

int AudioCD::getAudioBitrate() const {
    return audioBitrate;
}

void AudioCD::setAudioBitrate(int audioBitrate) {
    AudioCD::audioBitrate = audioBitrate;
}

float AudioCD::getSizeInMb() const {
    return sizeInMB;
}

void AudioCD::setSizeInMb(float sizeInMb) {
    sizeInMB = sizeInMb;
}

AudioCD::AudioCD(const string &type, const string &title, const string &authors, const string &language,
                 int releaseYear, int stockCounter, int rentedCounter, int audioBitrate, float sizeInMb) : Item(type,
                                                                                                                title,
                                                                                                                authors,
                                                                                                                language,
                                                                                                                releaseYear,
                                                                                                                stockCounter,
                                                                                                                rentedCounter),
                                                                                                           audioBitrate(
                                                                                                                   audioBitrate),
                                                                                                           sizeInMB(
                                                                                                                   sizeInMb) {}

void AudioCD::saveToFile(ostream &dataFile) {
    Item::saveToFile(dataFile);
    dataFile << audioBitrate << endl;
    dataFile << sizeInMB << endl;
    dataFile << "$$" << endl;
}
