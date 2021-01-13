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
using namespace std;

void print_menu();
void menu(vector<unique_ptr<Item>>& items);
void readFromFile();
void writeToFile();
std::unique_ptr<Item> createItem();
std::unique_ptr<Item> searchItem();

int main() {
    // TODO : Load data from file

//    std::vector<unique_ptr<Item>> items;
//
//    menu(items);

    return 0;
}

void menu(vector<unique_ptr<Item>>& items) {
    print_menu();
    cout << "Choice: ";
    short picker;
    cin >> picker;
    switch (picker) {
        case 1: {
            std::cout << "What type of media do you like to add?" << std::endl;
            std::unique_ptr<Item> item = createItem();
            items.push_back(item);
            break;
        }
        case 2: {
            // TODO: Find item -> changeStock
        }
        case 3: {
            // TODO: Find item -> edit
        }
        case 4: {
            // TODO: Find item -> display it
        }
        case 5: {
            // TODO: Show all items
        }
        case 6: {
            // TODO: Show all items on stock
        }
        case 0: {
            // TODO: Exit
        }
        default:
            std::cout << "Chosen option doesn't exist." << std::endl;
    }
}

void print_menu() {
    std::cout << "MENU:\n"
                 "1. Add item\n"
                 "2. Change item stock\n"
                 "3. Edit item\n"
                 "4. Search by\n"
                 "5. Show all mediums\n"
                 "6. Show all free mediums (from selected category)\n"
                 "0. Exit\n";
}

std::unique_ptr<Item> createItem()
{
    std::cout << "1. Book\n"
                 "2. Audiobook\n"
                 "3. Magazine\n"
                 "4. CD\n"
                 "5. AudioCD\n"
                 "6. Tape\n"
                 "7. Videotape\n";
    short choice;
    std::cin >> choice;
    while (choice < 1 || choice > 7)
    {
        std::cout << "Wrong input. Please enter 1-7" << std::endl;
        std::cin >> choice;
    }
    switch(choice)
    {
        case 1:
            return std::make_unique<Book>();
        case 2:
            return std::make_unique<Audiobook>();
        case 3:
            return std::make_unique<Magazine>();
        case 4:
            return std::make_unique<CD>();
        case 5:
            return std::make_unique<AudioCD>();
        case 6:
            return std::make_unique<Tape>();
        case 7:
            return std::make_unique<Videotape>();
        default:
            cout << "Wrong choice, no such object." << endl;
    }
}

void readFromFile() {
    // TODO : Read from file
}

void writeToFile() {
    // TODO : Write to file
}

std::unique_ptr<Item> searchItem() {
    // TODO: Choose whether to search item by title, author, or status
}