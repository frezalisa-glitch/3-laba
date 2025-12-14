#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    int a, b;
    cout << "Введите границы интервала [a, b]: ";
    cin >> a >> b;

    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = a + rand() % (b - a + 1);
        }
    }
    int maxNegative = numeric_limits<int>::min();
    pair<int, int> maxNegativePos;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i <= j && matrix[i][j] < 0 && matrix[i][j] > maxNegative) {
                maxNegative = matrix[i][j];
                maxNegativePos = { i, j };
            }
        }
    }
    int minPositive = numeric_limits<int>::max();
    pair<int, int> minPositivePos;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > j && matrix[i][j] > 0 && matrix[i][j] < minPositive) {
                minPositive = matrix[i][j];
                minPositivePos = { i, j };
            }
        }
    }
    if (maxNegative != numeric_limits<int>::min() && minPositive != numeric_limits<int>::max()) {
        swap(matrix[maxNegativePos.first][maxNegativePos.second], matrix[minPositivePos.first][minPositivePos.second]);
    }
    cout << "Матрица после перестановки:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}