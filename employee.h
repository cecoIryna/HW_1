#pragma once

void loadEmployeesFromFile() {
    char filename[255];
    cout << "������� ��� ����� ��� �������� ���������� � �����������: ";
    cin.ignore(); 
    cin.getline(filename, 255);

    FILE* file = fopen(filename, "r");
    if (file) {
        while (fscanf(file, "�������: %s\n���: %s\n�������: %s\n��������: %lf\n--------------------------\n",
            employees[employeeCount].surname,
            employees[employeeCount].name,
            employees[employeeCount].phone,
            &employees[employeeCount].salary) == 4) {
            employeeCount++;
        }
        fclose(file);
        cout << "���������� ������� ��������� �� �����." << endl;
    }
    else {
        cout << "������ ��� �������� �����." << endl;
    }
}


void saveEmployeesToFile() {
    char filename[255];
    cout << "������� ��� ����� ��� ���������� ���������� � �����������: ";
    cin.ignore();
    cin.getline(filename, 255);

    FILE* file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < employeeCount; i++) {
            fprintf(file, "�������:\n", employees[i].surname);
            fprintf(file, "���:\n", employees[i].name);
            fprintf(file, "�������:\n", employees[i].phone);
            fprintf(file, "��������: \n", employees[i].salary);
            fprintf(file, "--------------------------\n");
        }
        fclose(file);
        cout << "���������� ������� ��������� � ����." << endl;
    } else {
        cout << "������ ��� �������� �����." << endl;
    }
}

void showAllEmployees() {
    if (employeeCount == 0) {
        cout << "������ ����������� ����.\n";
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        cout << "�������: " << employees[i].surname << endl;
        cout << "���: " << employees[i].name << endl;
        cout << "�������: " << employees[i].phone << endl;
        cout << ",��������: " << employees[i].salary << endl;
        cout << "--------------------------" << endl;
    }
}

void searchEmployeeBySurname() {
    char surname[50];
    cout << "������� ������� ��� ������: ";
    cin >> surname;

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].surname, surname) == 0) {
            cout << "�������: " << employees[i].surname << endl;
            cout << "���: " << employees[i].name << endl;
            cout << "�������: " << employees[i].phone << endl;
            cout << "��������: " << employees[i].salary << endl;
            cout << "--------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "��������� � ����� �������� �� ������.\n";
    }
}

void searchEmployeesBySalaryRange() {
    double minSalary, maxSalary;
    cout << "������� ����������� ��������: ";
    cin >> minSalary;
    cout << "������� ������������ ��������: ";
    cin >> maxSalary;

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) {
            cout << "�������: " << employees[i].surname << endl;
            cout << "���: " << employees[i].name << endl;
            cout << "�������: " << employees[i].phone << endl;
            cout << "��������: " << employees[i].salary << endl;
            cout << "--------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "���������� � ��������� ��������� ������� �� �������.\n";
    }
}

void sortEmployeesBySurname() {
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = i + 1; j < employeeCount; j++) {
            if (strcmp(employees[i].surname, employees[j].surname) > 0) {
                swap(employees[i], employees[j]);
            }
        }
    }
    cout << "���������� ������������� �� �������.\n";
}

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "���������� �������� ������ �����������.\n";
        return;
    }

    employees[employeeCount].surname = new char[50];
    employees[employeeCount].name = new char[50];

    cout << "������� �������: ";
    cin >> employees[employeeCount].surname;

    cout << "������� ���: ";
    cin >> employees[employeeCount].name;

    cout << "������� ����� �������� (� ������� (063) 5635904):";
    cin >> employees[employeeCount].phone;
    /*if (!isPhoneValid(employees[employeeCount].phone)) {
        cout << "�������� ������ ��������. ���������� �����.\n";
        return;
    }*/

    cout << "������� ��������: ";
    cin >> employees[employeeCount].salary;

    employeeCount++;
    cout << "��������� ������� ��������.\n";
    return;
}

void deleteEmployee() {
    char surname[50];
    cout << "������� ������� ���������� ��� ��������: ";
    cin >> surname;

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].surname, surname) == 0) {
            found = true;

            cout << "�� �������, ��� ������ ������� ����������? (1 - ��, 0 - ���): ";
            int confirm;
            cin >> confirm;
            if (confirm == 1) {
                delete[] employees[i].surname;
                delete[] employees[i].name;
                for (int j = i; j < employeeCount - 1; j++) {
                    employees[j] = employees[j + 1];
                }
                employeeCount--;
                cout << "��������� ������� ������.\n";
            }
            return;
        }
    }

    if (!found) {
        cout << "��������� � ����� �������� �� ������.\n";
    }
}

/*bool isPhoneValid(const char* phone) {
// ���������, ��� ����� ����� ������ �����
    if (strlen(phone) != 13) {
        return false;
    }

    // ���������, ��� ����� ������������� ������� (XXX) XXXXXXX
    if (phone[0] != '(' || !isdigit(phone[1]) || !isdigit(phone[2]) || !isdigit(phone[3]) || phone[4] != ')' ||
        phone[5] != ' ' || !isdigit(phone[6]) || !isdigit(phone[7]) || !isdigit(phone[8]) ||
        !isdigit(phone[9]) || !isdigit(phone[10]) || !isdigit(phone[11]) || !isdigit(phone[12])) {
        return false;
    }

    // ���� ��� �������� ��������, ����� �������� ���������
    return true;
}*/