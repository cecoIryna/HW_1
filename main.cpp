#include "Struct.h"

#include <iostream>
#include <Windows.h>
#pragma warning(disable : 4996)
#include <cstring>
#include <fstream>

using namespace std;

#include "employee.h"
#include "menu.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice = 0;
    while (choice != 8) {
        cout << "\nМеню:\n";
        if (employeeCount == 0) {
            displaySmallMenu();
        }
        else{
            displayFullMenu();
        }

        cout << "Выберите опцию: ";
        cin >> choice;
        cin.ignore();

        if (employeeCount == 0) {
            switch (choice) {
            case 1:
                loadEmployeesFromFile();
                break;
            case 2:
                addEmployee();
                break;
            case 3:
                return 0;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
        else{
            switch (choice) {
            case 1:
                loadEmployeesFromFile();
                break;
            case 2:
                saveEmployeesToFile();
                break;
            case 3:
                showAllEmployees();
                break;
            case 4:
                searchEmployeeBySurname();
                break;
            case 5:
                searchEmployeesBySalaryRange();
                break;
            case 6:
                sortEmployeesBySurname();
                break;
            case 7:
                addEmployee();
                break;
            case 8:
                deleteEmployee();
                break;
            case 9:
                return 0;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
    }

    return 0;
}