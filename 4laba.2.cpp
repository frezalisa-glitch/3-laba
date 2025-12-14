#include <iostream>
#include <cmath>

int findMinAbs(int* arr, int n);
int sumAbsAfterFirstZero(int* arr, int n);
void transformMassiv(int* arr, int n);
void printMassiv(int* arr, int n);

int main() {
    setlocale(LC_ALL, "rus");
    int n;

    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Исходный массив: ";
    printMassiv(arr, n);

    //1
    int minAbs = findMinAbs(arr, n);
    cout << "Минимальный по модулю элемент: " << minAbs << endl;

    //2
    int sumAfterZero = sumAbsAfterFirstZero(arr, n);
    cout << "Сумма модулей элементов после первого нуля: " << sumAfterZero << endl;

    //3
    transformMassiv(arr, n);
    cout << "Преобразованный массив: ";
    printMassiv(arr, n);

    delete[] arr;
    arr = nullptr;

    return 0;
}

int findMinAbs(int* arr, int n) {
    if (n <= 0) {
        return 0;
    }

    int minAbs = abs(arr[0]);
    for (int i = 1; i < n; ++i) {
        if (abs(arr[i]) < minAbs) {
            minAbs = abs(arr[i]);
        }
    }
    return minAbs;
}

int sumAbsAfterFirstZero(int* arr, int n) {
    int sum = 0;
    bool zeroFound = false;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            zeroFound = true;
            continue;
        }

        if (zeroFound) {
            sum += abs(arr[i]);
        }
    }
    return sum;
}

void transformMassiv(int* arr, int n) {
    int* temp = new int[n];
    int evenIndex = 0;
    int oddIndex = n / 2;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            temp[evenIndex++] = arr[i];
        }
        else {
            temp[oddIndex++] = arr[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = temp[i];
    }

    delete[] temp;
    temp = nullptr;
}

void printMassiv(int* arr, int n) {
    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}