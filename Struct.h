#pragma once
const int MAX_EMPLOYEE = 255;
const int MAX_SURNAME = 255;
const int MAX_NAME = 255;
const int MAX_PHONE_NUMBER = 10;
const int MAX_PAYMENT = 255;

struct Employee {
    char* title[MAX_SURNAME];
    char* author[MAX_NAME];
    double year[MAX_PHONE_NUMBER];
    double text[MAX_PAYMENT];
};

Employee catalog[MAX_EMPLOYEE];
int employeeCount = 0;