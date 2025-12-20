#include <iostream>
#include <string>

using namespace std;

bool palindrom(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
unsigned int strLen(const char* input) {
    unsigned int count = 0;
    while (input[count] != '\0') {
        count++;
    }
    return count;
}
bool checkPassword(string password) {
    if (password.length() < 8 || password.length() > 14) {
        return false;
    }

    bool Upper = false;
    bool Lower = false;
    bool Digit = false;
    bool Special = false;

    for (char c : password) {
        if (c >= 33 || c <= 126) {
            if (isupper(c)) {
                Upper = true;
            }
            else if (islower(c)) {
                Lower = true;
            }
            else if (isdigit(c)) {
                Digit = true;
            }
            else {
                Special = true;
            }
        }
        else {
            return false;
        }
    }

    return Upper || Lower || Digit || Special;
}

int main() {
    setlocale(LC_ALL, "rus");

    //задание 1
    string input;
    cout << "Введите строку: ";
    cin >> input;
    if (palindrom(input)) {
        cout << "Является палиндромом" << endl;
    }
    else {
        cout << "Не является палиндромом" << endl;
    }
    //задание 3
    cout << "Длина строки: " << strLen(input.c_str()) << endl;

    //задание 2
    string password;
    cout << "Введите пароль: ";
    cin >> password;

    if (checkPassword(password)) {
        cout << "Пароль соответствует" << endl;
    }
    else {
        cout << "Пароль не соответствует" << endl;
    }
    return 0;
}

