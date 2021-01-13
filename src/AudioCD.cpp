//
// Created by Ivan Sandev on 1/9/21.
//

#include "../include/AudioCD.h"

void AudioCD::show() {
    Item::show();
    cout << "Bitrate: " << audioBitrate << endl;
    cout << "Size (MB): " << sizeInMB << endl;
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
