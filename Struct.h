#pragma once
const int MAX_EMPLOYEE = 255;
const int MAX_SURNAME = 255;
const int MAX_NAME = 255;
const int MAX_PHONE_NUMBER = 10;
const int MAX_PAYMENT = 255;

struct Employee {
    char* surname[MAX_SURNAME];
    char* name[MAX_NAME];
    double phoneNumber[MAX_PHONE_NUMBER];
    double payment[MAX_PAYMENT];
};

Employee catalog[MAX_EMPLOYEE];
int employeeCount = 0;