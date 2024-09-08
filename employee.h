#pragma once

void loadEmployeesFromFile() {
    char filename[255];
    cout << "Введите имя файла для загрузки информации о сотрудниках: ";
    cin.ignore(); 
    cin.getline(filename, 255);

    FILE* file = fopen(filename, "r");
    if (file) {
        while (fscanf(file, "Фамилия: %s\nИмя: %s\nТелефон: %s\nЗарплата: %lf\n--------------------------\n",
            employees[employeeCount].surname,
            employees[employeeCount].name,
            employees[employeeCount].phone,
            &employees[employeeCount].salary) == 4) {
            employeeCount++;
        }
        fclose(file);
        cout << "Информация успешно загружена из файла." << endl;
    }
    else {
        cout << "Ошибка при открытии файла." << endl;
    }
}


void saveEmployeesToFile() {
    char filename[255];
    cout << "Введите имя файла для сохранения информации о сотрудниках: ";
    cin.ignore();
    cin.getline(filename, 255);

    FILE* file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < employeeCount; i++) {
            fprintf(file, "Фамилия:\n", employees[i].surname);
            fprintf(file, "Имя:\n", employees[i].name);
            fprintf(file, "Телефон:\n", employees[i].phone);
            fprintf(file, "Зарплата: \n", employees[i].salary);
            fprintf(file, "--------------------------\n");
        }
        fclose(file);
        cout << "Информация успешно сохранена в файл." << endl;
    } else {
        cout << "Ошибка при открытии файла." << endl;
    }
}

void showAllEmployees() {
    if (employeeCount == 0) {
        cout << "Список сотрудников пуст.\n";
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        cout << "Фамилия: " << employees[i].surname << endl;
        cout << "Имя: " << employees[i].name << endl;
        cout << "Телефон: " << employees[i].phone << endl;
        cout << ",Зарплата: " << employees[i].salary << endl;
        cout << "--------------------------" << endl;
    }
}

void searchEmployeeBySurname() {
    char surname[50];
    cout << "Введите фамилию для поиска: ";
    cin >> surname;

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].surname, surname) == 0) {
            cout << "Фамилия: " << employees[i].surname << endl;
            cout << "Имя: " << employees[i].name << endl;
            cout << "Телефон: " << employees[i].phone << endl;
            cout << "Зарплата: " << employees[i].salary << endl;
            cout << "--------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Сотрудник с такой фамилией не найден.\n";
    }
}

void searchEmployeesBySalaryRange() {
    double minSalary, maxSalary;
    cout << "Введите минимальную зарплату: ";
    cin >> minSalary;
    cout << "Введите максимальную зарплату: ";
    cin >> maxSalary;

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) {
            cout << "Фамилия: " << employees[i].surname << endl;
            cout << "Имя: " << employees[i].name << endl;
            cout << "Телефон: " << employees[i].phone << endl;
            cout << "Зарплата: " << employees[i].salary << endl;
            cout << "--------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Сотрудники в указанном диапазоне зарплат не найдены.\n";
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
    cout << "Сотрудники отсортированы по фамилии.\n";
}

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "Невозможно добавить больше сотрудников.\n";
        return;
    }

    employees[employeeCount].surname = new char[50];
    employees[employeeCount].name = new char[50];

    cout << "Введите фамилию: ";
    cin >> employees[employeeCount].surname;

    cout << "Введите имя: ";
    cin >> employees[employeeCount].name;

    cout << "Введите номер телефона (в формате (063) 5635904):";
    cin >> employees[employeeCount].phone;
    /*if (!isPhoneValid(employees[employeeCount].phone)) {
        cout << "Неверный формат телефона. Попробуйте снова.\n";
        return;
    }*/

    cout << "Введите зарплату: ";
    cin >> employees[employeeCount].salary;

    employeeCount++;
    cout << "Сотрудник успешно добавлен.\n";
    return;
}

void deleteEmployee() {
    char surname[50];
    cout << "Введите фамилию сотрудника для удаления: ";
    cin >> surname;

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].surname, surname) == 0) {
            found = true;

            cout << "Вы уверены, что хотите удалить сотрудника? (1 - Да, 0 - Нет): ";
            int confirm;
            cin >> confirm;
            if (confirm == 1) {
                delete[] employees[i].surname;
                delete[] employees[i].name;
                for (int j = i; j < employeeCount - 1; j++) {
                    employees[j] = employees[j + 1];
                }
                employeeCount--;
                cout << "Сотрудник успешно удален.\n";
            }
            return;
        }
    }

    if (!found) {
        cout << "Сотрудник с такой фамилией не найден.\n";
    }
}

/*bool isPhoneValid(const char* phone) {
// Проверяем, что номер имеет нужную длину
    if (strlen(phone) != 13) {
        return false;
    }

    // Проверяем, что номер соответствует формату (XXX) XXXXXXX
    if (phone[0] != '(' || !isdigit(phone[1]) || !isdigit(phone[2]) || !isdigit(phone[3]) || phone[4] != ')' ||
        phone[5] != ' ' || !isdigit(phone[6]) || !isdigit(phone[7]) || !isdigit(phone[8]) ||
        !isdigit(phone[9]) || !isdigit(phone[10]) || !isdigit(phone[11]) || !isdigit(phone[12])) {
        return false;
    }

    // Если все проверки пройдены, номер телефона корректен
    return true;
}*/