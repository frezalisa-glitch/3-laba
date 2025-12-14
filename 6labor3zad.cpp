#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    ofstream testFile("numbers3.txt");
    if (testFile) {
        testFile << "10 5 -3 8 0 -7 15" << endl;
        testFile.close();
        cout << "Тестовый файл создан" << endl;
    }
    ifstream inFile("numbers3.txt");
    if (!inFile) {
        cout << "Ошибка открытия файла numbers3.txt!" << endl;
        return 1;
    }
    int number;
    int minPositive = 1000000;
    bool found = false;
    while (inFile >> number) {
        if (number > 0 && number < minPositive) {
            minPositive = number;
            found = true;
        }
    }
    if (found) {
        cout << "Минимальное положительное число: " << minPositive << endl;
    }
    else {
        cout << "Положительных чисел не найдено" << endl;
    }
    inFile.close();
    return 0;
}