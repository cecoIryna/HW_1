#pragma once
void displayAllMenu() {
    cout << "1. ����������� ���������� � �����\n";
    cout << "2. �������� ���������� � ����\n";
    cout << "3. �������� ��� �����������\n";
    cout << "4. ����� �� �������\n";
    cout << "5. ����� �� �������� �������\n";
    cout << "6. ���������� �� ��������\n";
    cout << "7. ������ �����������\n";
    cout << "8. �������� �����������\n";
    cout << "9. �����\n";
}

void displaySmallMenu() {
    cout << "1. ����������� ���������� � �����\n";
    cout << "2. ������ �����������\n";
    cout << "3. �����\n";
}

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEE) {
        cout << "������� ������������, �� ����� ������ ����� ��������." << endl;
        return;
    }

    cout << "������ �����: ";
    cin.ignore();
    cin.getline(catalog[employeeCount].surname, MAX_SURNAME);

    cout << "������ ��'�: ";
    cin.getline(catalog[employeeCount].name, MAX_NAME);

    cout << "������ ����� ��������: ";
    cin.getline(catalog[employeeCount].phoneNumber, MAX_PHONE_NUMBER);

    cout << "������ ���������: ";
    cin.getline(catalog[employeeCount].payment, MAX_PAYMENT);

    employeeCount++;
    cout << "ϳ��� ������ ������." << endl;
}