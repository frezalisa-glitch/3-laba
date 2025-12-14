#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    ofstream outFile("numbers5.bin", ios::binary);
    if (!outFile) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }
    int numbers[] = { -5, -3, -2, 7, 6, -8, 4, 9, -1, 2 };
    int size = 10;
    outFile.write((char*)numbers, size * sizeof(int));
    outFile.close();
    ifstream inFile("numbers5.bin", ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }
    int minPositive = 1000000;
    int number;
    bool found = false;
    while (inFile.read((char*)&number, sizeof(int))) {
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