#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    cout << "Задание 1" << endl;
    int n, m;
    cout << "Введите количество четных чисел для записи (n): ";
    cin >> n;
    cout << "Введите количество чисел для чтения (m): ";
    cin >> m;

    ofstream outFile("numbers1.txt");
    if (!outFile) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        outFile << 2 * i;
        if (i < n) {
            outFile << " ";
        }
    }
    outFile.close();

    ifstream inFile("numbers1.txt");
    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }
    cout << "Прочитанные числа: ";
    int number;
    int count = 0;
    while (count < m && inFile >> number) {
        cout << number << " ";
        count++;
    }
    if (count < m) {
        cout << "В файле только " << count << " чисел" << endl;
    }
    inFile.close();


    return 0;
}