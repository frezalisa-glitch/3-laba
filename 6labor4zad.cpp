#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    ofstream file("numbers4.bin", std::ios::binary);
    int nums[] = { 1, 2, 3, 4, 5 };
    file.write((char*)nums, sizeof(nums));
    file.close();

    ofstream outFile("numbers4.bin", ios::binary);
    if (!outFile) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }
    int numbers[] = { 1, 7, 3, 9, 6, 3, 8, 1, 10, 5 };
    int size = 10;
    outFile.write((char*)numbers, size * sizeof(int));
    outFile.close();
    ifstream inFile("numbers4.bin", ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }
    int sum = 0;
    int number;
    while (inFile.read((char*)&number, sizeof(int))) {
        if (number % 2 == 0) {
            sum += number;
        }
    }
    cout << "Сумма четных чисел: " << sum << endl;
    inFile.close();
    return 0;
}