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

    }
}
