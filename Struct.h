#pragma once
const int MAX_EMPLOYEES = 100;
const int PHONE_LENGTH = 15;

struct Employee {
    char* surname;
    char* name;
    char phone[PHONE_LENGTH];
    double salary;
};

Employee employees[MAX_EMPLOYEES];
int employeeCount=0;

// Функции
void loadEmployeesFromFile();
void saveEmployeesToFile();
void showAllEmployees();
void searchEmployeeBySurname();
void searchEmployeesBySalaryRange();
void sortEmployeesBySurname();
void addEmployee();
void deleteEmployee();
bool isPhoneValid(const char* phone);