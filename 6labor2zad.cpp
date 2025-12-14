#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    ofstream testFile("numbers2.txt");
    if (testFile) {
        testFile << "10 5 -3 8 0 -7 15" << endl;
        testFile.close();
        cout << "Тестовый файл создан" << endl;
    }
    ifstream inFile("numbers2.txt");
    if (!inFile) {
        cout << "Ошибка открытия файла numbers2.txt!" << endl;
        return 1;
    }
    int number;
    int sum = 0;
    while (inFile >> number) {
        if (number % 2 == 0) {
            sum += number;
        }
    }
    cout << "Сумма четных чисел: " << sum << endl;
    inFile.close();
    return 0;
}