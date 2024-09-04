#include "Struct.h"
#include <iostream>
using namespace std;
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    int choice = 0;
    while (choice != 9) {
        cout << "Меню:" << endl;
        if (employeeCount == 0) {
            displaySmallMenu();
        }
        else {
            displayAllMenu();
        }
    }
    cout << "Виберіть опцію: ";

    cin >> choice;
    cin.ignore();

    if (employeeCount == 0) {
        switch (choice) {
        case 1:
            addSong();
            break;
        case 2:
            return 0;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
    }
    else {
        switch (choice) {
        case 1:
            addSong();
            break;
        case 2:
            removeSong();
            break;
        case 3:
            editSong();
            break;
        case 4:
            displaySong();
            break;
        case 5:
            saveSongToFile();
            break;
        case 6:
            searchByAuthor();
            break;
        case 7:
            searchByWord();
            break;
        case 8:
            return 0;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
    }
}
