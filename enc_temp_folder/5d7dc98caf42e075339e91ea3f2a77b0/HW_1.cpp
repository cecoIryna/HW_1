#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Ukrainian");

    void displayAllMenu(); {
        cout << "1. Загрузить информацию из файла\n";
        cout << "2. Записать информацию в файл\n";
        cout << "3. Показать всех сотрудников\n";
        cout << "4. Поиск по фамилии\n";
        cout << "5. Поиск по диапазону зарплат\n";
        cout << "6. Сортировка по фамилии\n";
        cout << "7. Добавить сотрудника\n";
        cout << "8. Удалить сотрудника\n";
        cout << "9. Выход\n";
    }
    void displaySmallMenu(); {
        cout << "1. Загрузить информацию из файла\n";
        cout << "2. Добавить сотрудника\n";
        cout << "3. Выход\n";
    }

}
