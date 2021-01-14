//
// Created by Ivan Sandev on 1/9/21.
//

#ifndef DIGITAL_LIBRARY_AUDIOCD_H
#define DIGITAL_LIBRARY_AUDIOCD_H

#include "Item.h"
using namespace std;

class AudioCD : public Item {
private:
    int audioBitrate;
    float sizeInMB;
public:
    AudioCD() : Item()
    {
        setType("audiocd");

        cout << "Audio bitrate: ";
        cin >> audioBitrate;
        while (cin.fail()) {
            cout << "Audio bitrate should be a whole number.\nAudio bitrate: ";
            cin >> audioBitrate;
        }

        cout << "Size (MB): ";
        cin >> sizeInMB;
        while (cin.fail()) {
            cout << "Size should be a whole number (without MB).\nSize (MB): ";
            cin >> sizeInMB;
        }
    }

    AudioCD(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
            int stockCounter, int rentedCounter, int audioBitrate, float sizeInMb);

    // GETTERS / SETTERS
    int getAudioBitrate() const;
    void setAudioBitrate(int audioBitrate);
    float getSizeInMb() const;
    void setSizeInMb(float sizeInMb);

    virtual void show();

    void saveToFile(ostream &dataFile);
};


#endif //DIGITAL_LIBRARY_AUDIOCD_H
