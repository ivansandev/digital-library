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
    cout << "GENRE: " << genre << endl;
    cout << "BITRATE: " << audioBitrate << endl;
    cout << "WORDS PER MINUTE: " << wpm << endl;
}

Audiobook::Audiobook(const string &type, const string &title, const string &authors, const string &language,
                     int releaseYear, int stockCounter, int rentedCounter, const string &genre, int audioBitrate,
                     int wpm) : Item(type, title, authors, language, releaseYear, stockCounter, rentedCounter),
                                genre(genre), audioBitrate(audioBitrate), wpm(wpm) {}

void Audiobook::saveToFile(ostream &dataFile) {
    Item::saveToFile(dataFile);
    dataFile << genre << endl;
    dataFile << audioBitrate << endl;
    dataFile << wpm << endl;
    dataFile << "$$" << endl;
}

