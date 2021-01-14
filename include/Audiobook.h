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
        setType("audiobook");

        cout << "Genre: ";
        getline(cin, genre);
        if (genre.length() == 0) {
            cout << "No genre given. Defaulting to 'non-fiction'" << endl;
            genre = "Non-fiction";
        }

        cout << "Audio bitrate: ";
        cin >> audioBitrate;
        while (cin.fail()) {
            cout << "Audio bitrate should be a whole number.\nAudio bitrate: ";
            if (!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cin >> audioBitrate;
        }

        cout << "Words per minute: " << wpm;
        cin >> wpm;
        while (cin.fail()) {
            cout << "Words per minute should be a whole number.\nWords per minute: ";
            if (!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cin >> wpm;
        }
    }

    Audiobook(const string &type, const string &title, const string &authors, const string &language, int releaseYear,
              int stockCounter, int rentedCounter, const string &genre, int audioBitrate, int wpm);

    const string &getGenre() const;
    void setGenre(const string &genre);
    int getAudioBitrate() const;
    void setAudioBitrate(int audioBitrate);
    int getWpm() const;
    void setWpm(int wpm);

    void show();
    void saveToFile(std::ostream &dataFile);
};


#endif //DIGITAL_LIBRARY_AUDIOBOOK_H
