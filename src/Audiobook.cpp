//
// Created by Ivan Sandev on 1/9/21.
//

#include "../include/Audiobook.h"

const string &Audiobook::getGenre() const {
    return genre;
}

void Audiobook::setGenre(const string &genre) {
    Audiobook::genre = genre;
}

int Audiobook::getAudioBitrate() const {
    return audioBitrate;
}

void Audiobook::setAudioBitrate(int audioBitrate) {
    Audiobook::audioBitrate = audioBitrate;
}

int Audiobook::getWpm() const {
    return wpm;
}

void Audiobook::setWpm(int wpm) {
    Audiobook::wpm = wpm;
}

void Audiobook::show() {
    Item::show();
    cout << "Genre: " << genre << endl;
    cout << "Bitrate: " << audioBitrate << endl;
    cout << "Words per minute: " << wpm << endl;
}

