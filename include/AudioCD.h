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
        cout << "Audio bitrate: ";
        cin >> audioBitrate;

        cout << "Size (MB): ";
        cin >> sizeInMB;
    }

    // GETTERS / SETTERS
    int getAudioBitrate() const;
    void setAudioBitrate(int audioBitrate);
    float getSizeInMb() const;
    void setSizeInMb(float sizeInMb);

    virtual void show();
};


#endif //DIGITAL_LIBRARY_AUDIOCD_H
