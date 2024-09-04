#pragma once
void displayAllMenu() {
    cout << "1. Завантажити інформацію з файлу\n";
    cout << "2. Записати інформацію у файл\n";
    cout << "3. Показати всіх співробітників\n";
    cout << "4. Пошук на прізвище\n";
    cout << "5. Пошук по діапазону зарплат\n";
    cout << "6. Сортування за прізвищем\n";
    cout << "7. Додати співробітника\n";
    cout << "8. Видалити співробітника\n";
    cout << "9. Вихід\n";
}

void displaySmallMenu() {
    cout << "1. Завантажити інформацію з файлу\n";
    cout << "2. Додати співробітника\n";
    cout << "3. Вихід\n";
}

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEE) {
        cout << "Каталог переповнений, не можна додати більше робітників." << endl;
        return;
    }

    cout << "Введіть фамілію: ";
    cin.ignore();
    cin.getline(catalog[employeeCount].surname, MAX_SURNAME);

    cout << "Введіть ім'я: ";
    cin.getline(catalog[employeeCount].name, MAX_NAME);

    cout << "Введіть номер телефону: ";
    cin.getline(catalog[employeeCount].phoneNumber, MAX_PHONE_NUMBER);

    cout << "Введіть зарплатню: ";
    cin.getline(catalog[employeeCount].payment, MAX_PAYMENT);

    employeeCount++;
    cout << "Пісня успішно додана." << endl;
}