//
// Created by Ivan Sandev on 1/9/21.
//

#ifndef DIGITAL_LIBRARY_AUDIOBOOK_H
#define DIGITAL_LIBRARY_AUDIOBOOK_H


#include "Item.h"
using namespace std;

class Audiobook : public Item {
private:
    string genre;
    int audioBitrate;
    int wpm; // words per minute
public:
    Audiobook() : Item()
    {
        cout << "Genre: ";
        getline(cin, genre);
        cout << "Audio bitrate: ";
        cin >> audioBitrate;
        cout << "Words per minute: " << wpm;
        cin >> wpm;
    }

    const string &getGenre() const;
    void setGenre(const string &genre);
    int getAudioBitrate() const;
    void setAudioBitrate(int audioBitrate);
    int getWpm() const;
    void setWpm(int wpm);

    void show();
};


#endif //DIGITAL_LIBRARY_AUDIOBOOK_H
