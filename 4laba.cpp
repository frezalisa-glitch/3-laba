#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int findMax(const vector<int>& arr);
int findMin(const vector<int>& arr);
void swapMaxMin(vector<int>& arr);
void replase(const vector<int>& arr);

//общее задание
int main() {
    setlocale(LC_ALL, "rus");
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Элемент [" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Исходный массив: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Максимальный элемент: " << findMax(arr) << endl;
    cout << "Минимальный элемент: " << findMin(arr) << endl;

    swapMaxMin(arr);
    cout << "Массив после перестановки максимального и минимального элементов: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    replase(arr);

    return 0;
}

int findMax(const vector<int>& arr) {
    if (arr.empty()) {
        return -1;
    }
    int maxElement = arr[0];
    for (int x : arr) {
        if (x > maxElement) {
            maxElement = x;
        }
    }
    return maxElement;
}

int findMin(const vector<int>& arr) {
    if (arr.empty()) {
        return -1;
    }
    int minElement = arr[0];
    for (int x : arr) {
        if (x < minElement) {
            minElement = x;
        }
    }
    return minElement;
}

void swapMaxMin(vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    int maxElement = arr[0];
    int minElement = arr[0];
    int maxIndex = 0;
    int minIndex = 0;

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            maxIndex = i;
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
            minIndex = i;
        }
    }
    swap(arr[maxIndex], arr[minIndex]);
}

void replase(const vector<int>& arr) {
    map<int, int> counts;
    for (int x : arr) {
        counts[x]++;
    }
    cout << "Количество каждого элемента в массиве:" << endl;
    for (const auto& pair : counts) {
        cout << "Элемент: " << pair.first << ", Количество: " << pair.second << endl;
    }
}