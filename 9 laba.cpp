#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum Gender { //Cоздание своего типа данных MALE - 0, FEMALE - 1
    MALE,
    FEMALE
};

enum StorageTerm {
    DAYS_10,
    DAYS_20,
    DAYS_30
};

struct Date {
    int day;
    int month;
    int year;
};

struct LombardItem {
    string surname;    // Фамилия
    string name;       // Имя
    string patronymic; // Отчество
    Gender gender;     // Пол
    string itemName;   // Товар
    double amount;     // Сумма
    Date date;         // Дата
    StorageTerm term;  // Срок
};

//Функция для перевода Enum пола в строку (для вывода)
string getGenderStr(Gender g) {
    if (g == MALE) return "Муж";
    else return "Жен";
}

//Функция для перевода Enum срока в число (для вывода)
int getTermInt(StorageTerm t) {
    if (t == DAYS_10) return 10;
    if (t == DAYS_20) return 20;
    return 30;
}

int main() {
    setlocale(LC_ALL, "rus");

    //Подсчет количества записей в файле
    ifstream fileCount("data.txt");
    if (!fileCount.is_open()) {
        cout << "Ошибка: Файл 'data.txt' не найден!" << endl;
        return 1;
    }

    int n = 0;
    //Временные переменные просто для считывания
    string tempStr;
    double tempDouble;
    int tempInt;

    //Считываем структуру одной строки, чтобы узнать количество записей
    //Формат: Ф И О Пол Товар Сумма Д М Г Срок
    while (fileCount >> tempStr >> tempStr >> tempStr >> tempStr >> tempStr >> tempDouble >> tempInt >> tempInt >> tempInt >> tempInt) {
        ++n;
    }
    fileCount.close();

    if (n == 0) {
        cout << "Файл пуст или имеет неверный формат." << endl;
        return 1;
    }

    //Выделяем память под массив структур
    LombardItem* database = new LombardItem[n];
    ifstream fileRead("data.txt");

    for (int i = 0; i < n; ++i) {
        string gStr; // Для чтения пола
        int d_days;  // Для чтения дней
        //Чтение данных из файла в структуру
        fileRead >> database[i].surname
            >> database[i].name
            >> database[i].patronymic
            >> gStr
            >> database[i].itemName
            >> database[i].amount
            >> database[i].date.day
            >> database[i].date.month
            >> database[i].date.year
            >> d_days;

        //Конвертация пола
        if (gStr == "M" || gStr == "m") database[i].gender = MALE;
        else database[i].gender = FEMALE;

        //Конвертация срока
        if (d_days == 10) database[i].term = DAYS_10;
        else if (d_days == 20) database[i].term = DAYS_20;
        else database[i].term = DAYS_30;
    }
    fileRead.close();

    //Вывод всех объектов
    cout << "Загружено записей: " << n << endl;
    cout << "__________________________________________________" << endl;
    cout << "Ф.И.О.\t\tТовар\tСумма\tСрок\tДата" << endl;
    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i < n; ++i) {
        cout << database[i].surname << " " << database[i].name[0] << "." << database[i].patronymic[0] << ".\t"
            << database[i].itemName << "\t"
            << database[i].amount << "\t"
            << getTermInt(database[i].term) << "\t"
            << database[i].date.day << "." << database[i].date.month << "." << database[i].date.year << endl;
    }

    //Меню
    int choice;
    do {
        cout << "\nМЕНЮ ЛОМБАРДА" << endl;
        cout << "1. Поиск по Фамилии" << endl;
        cout << "2. Поиск по сумме" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 1) {
            string searchSurname;
            cout << "Введите фамилию: ";
            cin >> searchSurname;

            bool found = false;
            cout << "\nРезультаты поиска:" << endl;
            for (int i = 0; i < n; ++i) {
                if (database[i].surname == searchSurname) {
                    cout << database[i].surname << " " << database[i].name << "\t"
                        << database[i].itemName << "\t" << database[i].amount << " руб." << endl;
                    found = true;
                }
            }
            if (!found) cout << "Клиент не найден." << endl;
        }
        else if (choice == 2) {
            double val;
            int mode;
            cout << "Введите сумму: ";
            cin >> val;
            cout << "1 - Искать что БОЛЬШЕ суммы" << endl;
            cout << "2 - Искать что МЕНЬШЕ суммы" << endl;
            cout << "3 - Искать что РАВНО сумме" << endl;
            cout << "Режим: ";
            cin >> mode;

            bool found = false;
            cout << "\nРезультаты фильтрации:" << endl;
            for (int i = 0; i < n; ++i) {
                bool condition = false;
                if (mode == 1 && database[i].amount > val) condition = true;
                if (mode == 2 && database[i].amount < val) condition = true;
                if (mode == 3 && database[i].amount == val) condition = true;
                if (condition) {
                    cout << database[i].surname << "\t" << database[i].itemName << "\t" << database[i].amount << endl;
                    found = true;
                }
            }
            if (!found) cout << "Записи не найдены." << endl;
        }
    } while (choice != 0);

    // Очистка памяти
    delete[] database;

    return 0;
}