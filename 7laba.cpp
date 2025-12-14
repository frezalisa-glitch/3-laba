#include <iostream>
#include <cmath>

using namespace std;
//1
void task1() {
    int value1 = 100;
    int* ptr = &value1;
    cout << "значение через указатель: " << *ptr << endl;
    int value2 = 200;
    int* ptr2 = &value2;
    cout << "значение через указатель: " << *ptr2 << endl;
    cout << "адрес переменной value1: " << &value1 << endl;
    cout << "адрес переменной value2: " << &value2 << endl;
}
//2
double triangleArea(double side, double height) {
    return 0.5 * side * height;
}
//3
int maxOfThree(int a, int b, int c) {
    return max(a, max(b, c));
}
//4
void task4() {
    int a = 10;
    int b = 20;
    int* pa = &a;
    int* pb = &b;
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    cout << "a после обмена: " << a << endl;
    cout << "b после обмена: " << b << endl;
}
//5
int maxElement(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int minElement(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
int main() {
    setlocale(LC_ALL, "rus");
    cout << "Задание 1" << endl;
    task1();

    cout << "Задание 2" << endl;
    double side = 5.0;
    double height = 10.0;
    double area = triangleArea(side, height);
    cout << "площадь треугольника: " << area << endl;

    cout << "Задание 3" << endl;
    int a = 10;
    int b = 20;
    int c = 30;
    int maxValue = maxOfThree(a, b, c);
    cout << "максимальное из трех чисел: " << maxValue << endl;

    cout << "Задание 4" << endl;
    task4();

    cout << "Задание 5" << endl;
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int max = maxElement(arr, size);
    int min = minElement(arr, size);
    cout << "макс элемент массива: " << max << endl;
    cout << "мин элемент массива: " << min << endl;

    return 0;
}