#include <cmath>
#include <iostream>
using namespace std;

int sum(int num) {
    int summa = 0;
    while (num > 0) {
        summa += num % 10;
        num /= 10;

    }
    return summa;
}

double circle(int rad) {
    double const kPi = 3.1415;
    double s1 = kPi * rad * rad;
    return s1;
}
double rectangle(int a1, int b1) {
    double s2 = a1 * b1;
    return s2;
}
double triangle(int k_1, int k_2) {
    double s3 = (k_1 * k_2) / 2;
    return s3;
}


bool simple_num(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int fac(int n1) {
    if (n1 < 0) {
        cout << "n должно быть неотрицательным числом" << endl;
        return -1;
    }
    unsigned int res = 1;

    for (int i = 2; i <= n1; ++i)
        res *= i;

    return res;
}

int main()
{
    setlocale(LC_ALL, "rus");
    //Задание 1
    int a, b;
    cout << "введите диапазон " << endl;
    cin >> a >> b;

    cout << "простые числа " << endl;
    bool simplenumber = false;
    for (int num = a; num <= b; ++num) {
        if (simple_num(num)) {
            cout << num << " ";
            simplenumber = true;
        }
    }

    cout << "\nдружественные числа " << endl;
    bool friendlynumber = false;
    for (int num = a; num <= b; ++num) {
        if (simple_num(num) and simple_num(num + 2)) {
            cout << num << " " << num + 2 << " " << endl;
            friendlynumber = true;
        }
    }

    //Задание 2
    cout << "введите число " << endl;
    int n;
    cin >> n;
    int factorial = fac(n);
    cout << "факториал числа " << n << " равен " << factorial << endl;

    //Задание 3
    int num1;
    cout << "введите количество чисел " << endl;
    int minN = 0, maxN = 0;
    int minSum = INT_MAX, maxSum = INT_MIN;
    cin >> num1;
    for (int i = 0; i < num1; ++i) {
        int n;
        cout << "введите число " << i + 1 << endl;
        cin >> n;
        int a1 = sum(n);

        if (a1 < minSum || (a1 == minSum and n < minN)) {
            minSum = a1;
            minN = n;
        }

        if (a1 > maxSum || (a1 == maxSum and n > maxN)) {
            maxSum = a1;
            maxN = n;

        }
    }
    cout << "минимальная сумма: " << minSum << endl;
    cout << "максимальная сумма: " << maxSum << endl;

    //Задание 4
    int y;
    do {
        cout << "выберите номер фигуры " << endl
            << "1. круг" << endl
            << "2. прямоугольник" << endl
            << "3. прямоугольный треугольник" << endl
            << "0. выход из программы " << endl;

        cin >> y;

        if (y == 1) {
            cout << "введите радиус круга " << endl;
            int r;
            cin >> r;
            double sCircle = circle(r);
            cout << "площадь равна " << sCircle << endl;
        }

        if (y == 2) {
            cout << "введите стороны прямоугольника " << endl;
            int a, b;
            cin >> a >> b;
            double sRectangle = rectangle(a, b);
            cout << "площадь равна " << sRectangle << endl;
        }
        if (y == 3) {
            cout << "введите катеты треугольника " << endl;
            int k1, k2;
            cin >> k1 >> k2;
            double sTriangle = triangle(k1, k2);
            cout << "площадь равна " << sTriangle << endl;
        }
    } while (y == 1 || y == 2 || y == 3);
    return 0;
}