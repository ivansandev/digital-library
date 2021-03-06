#include <iostream>
#include "include/Item.h"
#include "include/Book.h"
#include "include/Audiobook.h"
#include "include/Magazine.h"
#include "include/CD.h"
#include "include/AudioCD.h"
#include "include/Tape.h"
#include "include/Videotape.h"
#include <memory>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

void printStartMenu();

void menu(vector<Item *> &items);

void readFromFile(vector<Item *> &);

void writeToFile(vector<Item *> &items);

void newItemWizard(vector<Item *> &items);

void freeItems(vector<Item *> &items);

void printCategories();

void showAll(vector<Item *> &items);

void showAllDetailed(vector<Item *> &items);

void showAllCategory(vector<Item *> &items);

void showAllAvailable(vector<Item *> &items);

void showAllAvailableCategory(vector<Item *> &items);

vector<Item *> searchItems(vector<Item *> &items);

int main() {

    std::vector<Item *> items;

//    TODO : Load data from file
    readFromFile(items);

    menu(items);

    writeToFile(items);
    freeItems(items);
    return 0;
}

void printStartMenu() {
    std::cout << "MENU:\n"
                 "1. Show item(s)\n"
                 "2. Rent item\n"
                 "3. Return item\n"
                 "4. Add item\n"
                 "5. Delete item\n"
                 "0. Exit\n";
}

void printShowMenu() {
    std::cout << "SHOW\n"
                 "\t1. Search item\n"
                 "\t2. Show all items\n"
                 "\t3. Show all items by category\n"
                 "\t4. Show all items in-stock\n"
                 "\t5. Show all items in stock by category\n"
                 "\t0. Back\n"
                 "Choice: ";
}

void printCategories() {
    std::cout << "1. Book\n"
                 "2. Audiobook\n"
                 "3. Magazine\n"
                 "4. CD\n"
                 "5. AudioCD\n"
                 "6. Tape\n"
                 "7. Videotape\n"
                 "Choice: ";
}

std::string categoryPickerToString() {
    short picker = -1;
    cin >> picker;
    while (picker < 1 || picker > 7) {
        cout << "Pick between choice 1 and 7." << endl << "Choice: " << endl;
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cin >> picker;
    }
    switch (picker) {
        case 1:
            return "book";
        case 2:
            return "audiobook";
        case 3:
            return "magazine";
        case 4:
            return "cd";
        case 5:
            return "audiocd";
        case 6:
            return "tape";
        case 7:
            return "videotape";
        default:
            return "";
    }
}

void menu(vector<Item *> &items) {
    while (true) {
        printStartMenu();
        cout << "Choice: ";
        short picker = -1;
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cin >> picker;
        switch (picker) {
            // +--------------+
            // | SHOW ITEM(s) |
            // +--------------+
            case 1: {
                printShowMenu();
                int picker2 = -1;
                if (!cin) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                cin >> picker2;
                while (picker2 < 0 || picker2 > 5) {
                    cout << "Pick between option 0-5.\nChoice: ";
                    if (!cin) {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    cin >> picker2;
                }
                switch (picker2) {
                    case 1: {
                        vector<Item *> foundItems = searchItems(items);
                        showAllDetailed(foundItems);
                        break;
                    }
                    case 2: {
                        showAll(items);
                        break;
                    }
                    case 3: {
                        showAllCategory(items);
                        break;
                    }
                    case 4: {
                        showAllAvailable(items);
                        break;
                    }
                    case 5: {
                        showAllAvailableCategory(items);
                        break;
                    }
                    default: {
                        cout << "Wrong option." << endl;
                    }
                }
                break;
            }
                // +-----------+
                // | RENT ITEM |
                // +-----------+
            case 2: {
                vector<Item *> foundItems;
                foundItems = searchItems(items);
                if (foundItems.empty()) {
                    cout << "No items found. Please change your search criteria." << endl;
                    break;
                } else if (foundItems.size() == 1) {
                    (*foundItems[0])--;
                } else {
                    cout << "More than one result found. Please be more specific." << endl;
                }
                writeToFile(items);
                break;
            }
                // +-------------+
                // | RETURN ITEM |
                // +-------------+
            case 3: {
                vector<Item *> foundItems;
                foundItems = searchItems(items);
                if (foundItems.empty()) {
                    cout << "No items found. Please change your search criteria." << endl;
                    break;
                } else if (foundItems.size() == 1) {
                    (*foundItems[0])++;
                } else {
                    cout << "More than one result found. Please be more specific." << endl;
                }
                writeToFile(items);
                break;
            }
                // +----------+
                // | ADD ITEM |
                // +----------+
            case 4: {
                std::cout << "What type of media do you like to add?" << std::endl;
                newItemWizard(items);
                writeToFile(items);
                break;
            }
                // +-------------+
                // | DELETE ITEM |
                // +-------------+
            case 5: {
                vector<Item *> foundItems;
                foundItems = searchItems(items);
                if (foundItems.empty()) {
                    cout << "No items found. Please change your search criteria." << endl;
                    break;
                } else if (foundItems.size() == 1) {
                    for (auto it = items.begin(); it != items.end(); ++it) {
                        if ((*it)->getTitle() == foundItems[0]->getTitle()
                            && (*it)->getAuthors() == foundItems[0]->getAuthors()) {
                            items.erase(it);
                            break;
                        }
                    }
                    foundItems[0];
                } else {
                    cout << "More than one result found. Please be more specific." << endl;
                }
                break;
            }
            case 0: {
                return;
            }
            default:
                std::cout << "Chosen option doesn't exist. Try again" << std::endl;
        }
    }
}

void newItemWizard(vector<Item *> &items) {
    printCategories();
    short picker = -1;
    std::cin >> picker;
    while (picker < 1 || picker > 7) {
        std::cout << "Wrong input. Please enter 1-7: ";
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin >> picker;
    }
    switch (picker) {
        case 1:
            items.push_back(new Book);
            break;
        case 2:
            items.push_back(new Audiobook);
            break;
        case 3:
            items.push_back(new Magazine);
            break;
        case 4:
            items.push_back(new CD);
            break;
        case 5:
            items.push_back(new AudioCD);
            break;
        case 6:
            items.push_back(new Tape);
            break;
        case 7:
            items.push_back(new Videotape);
            break;
        default:
            cout << "Wrong picker, no such object." << endl;
    }
}

void readFromFile(vector<Item *> &items) {
    ifstream dataFile("data.txt");
    vector<string> lines;
    string line;
    if (dataFile.is_open()) {
        while (getline(dataFile, line)) {
            if (line != "$$") {
                lines.push_back(line);
            } else {
                // TODO: Insert new object into items;
                string type = lines[0];
                string title = lines[1];
                string authors = lines[2];
                string language = lines[3];
                int releaseYear = stoi(lines[4]);
                int stockCounter = stoi(lines[5]);
                int rentedCounter = stoi(lines[6]);
                if (type == "audiobook")
                    items.push_back(
                            new Audiobook(type, title, authors, language, releaseYear, stockCounter, rentedCounter,
                                          lines[7], stoi(lines[8]), stoi(lines[9])));
                if (type == "audiocd")
                    items.push_back(
                            new Audiobook(type, title, authors, language, releaseYear, stockCounter, rentedCounter,
                                          lines[7], stoi(lines[8]), stoi(lines[9])));
                if (type == "book")
                    items.push_back(
                            new Book(type, title, authors, language, releaseYear, stockCounter, rentedCounter,
                                     stoi(lines[7]), stoi(lines[8]), lines[9], lines[10]));
                if (type == "cd")
                    items.push_back(
                            new Audiobook(type, title, authors, language, releaseYear, stockCounter, rentedCounter,
                                          lines[7], stoi(lines[8]), stoi(lines[9])));
                if (type == "magazine")
                    items.push_back(
                            new Magazine(type, title, authors, language, releaseYear, stockCounter, rentedCounter,
                                         stoi(lines[7]), stoi(lines[8]), lines[9],
                                         lines[10], lines[11]));
                if (type == "tape")
                    items.push_back(
                            new Tape(type, title, authors, language, releaseYear, stockCounter, rentedCounter,
                                     stoi(lines[7])));

                if (type == "videotape")
                    items.push_back(
                            new Videotape(type, title, authors, language, releaseYear, stockCounter, rentedCounter,
                                          stoi(lines[7]), "1" == lines[8]));

                lines.clear();

            }
        }
    } else {
        cout << "Cannot open file for reading. Exiting..." << endl;
    }
}

void writeToFile(vector<Item *> &items) {
    ofstream dataFile("data.txt");
    if (dataFile.is_open()) {
        for (auto &item : items) {
            item->saveToFile(dataFile);
        }
        dataFile.close();
    } else {
        cout << "Cannot open file for writing. Exiting..." << endl;
    }
}

void showAll(vector<Item *> &items) {
    cout << endl << "RESULTS:" << endl;
    cout << "---------------------" << endl;
    if (items.empty())
        cout << "No items to display." << endl;
    else
        for (auto &item : items)
            cout << *item;
    cout << "---------------------" << endl << endl;
}

void showAllDetailed(vector<Item *> &items) {
    cout << endl << "RESULTS:" << endl;
    if (items.empty()) {
        cout << "No items to display." << endl;
    } else {
        for (auto &item : items) {
            cout << "---------------------" << endl;
            item->show();
        }
    }
    cout << "---------------------" << endl << endl;
}

void showAllCategory(vector<Item *> &items) {
    printCategories();
    std::string category = categoryPickerToString();
    cout << endl << "RESULTS:" << endl;
    cout << "---------------------" << endl;
    for (auto &item : items)
        if (item->getType() == category)
            cout << *item;
    cout << "---------------------" << endl << endl;
}

void showAllAvailable(vector<Item *> &items) {
    cout << endl << "RESULTS:" << endl;
    cout << "---------------------" << endl;
    if (items.empty())
        cout << "No items to display." << endl;
    else
        for (auto &item : items)
            if (item->isStock())
                cout << *item;
    cout << "---------------------" << endl << endl;
}

void showAllAvailableCategory(vector<Item *> &items) {
    printCategories();
    std::string category = categoryPickerToString();
    cout << endl << "RESULTS:" << endl;
    cout << "---------------------" << endl;
    for (auto &item : items)
        if ((item->getType() == category) && (item->isStock()))
            cout << *item;
    cout << "---------------------" << endl << endl;
}

vector<Item *> searchItems(vector<Item *> &items) {
    string criteria;
    cout << "Search: ";
    cin >> criteria;
    vector<Item *> foundItems;
    for (auto &item : items) {
        if (item->isItem(criteria)) {
            foundItems.push_back(item);
        }
    }
    return foundItems;
}

void freeItems(vector<Item *> &items) {
    for (auto &item : items) {
        if (item->getType() == "book")
            delete ((Book *) item);
        if (item->getType() == "audiobook")
            delete ((Audiobook *) item);
        if (item->getType() == "magazine")
            delete ((Magazine *) item);
        if (item->getType() == "cd")
            delete ((CD *) item);
        if (item->getType() == "audiocd")
            delete ((AudioCD *) item);
        if (item->getType() == "tape")
            delete ((Tape *) item);
        if (item->getType() == "videotape")
            delete ((Videotape *) item);
    }
}