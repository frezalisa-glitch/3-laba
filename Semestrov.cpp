#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Описание конфеты
struct Candy {
    string name;     //Название
    int weight;      //Вес
    double price;    //Цена
    bool filling;    //Есть ли начинка
};

//Узел связного списка
struct Node {
    Candy data;
    Node* next;
};

void addNode(Node*& head) {
    Node* newNode = new Node;

    cout << "\n Добавление новой конфеты \n";
    cout << "Введите название (например: Truffle,Raffaello,Iris,Snickers): ";
    cin >> newNode->data.name;
    cout << "Введите вес (г): ";
    cin >> newNode->data.weight;
    cout << "Введите цену: ";
    cin >> newNode->data.price;
    cout << "Начинка? (1 - yes, 0 - no): ";
    cin >> newNode->data.filling;

    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << "Товар успешно добавлен\n";
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "\nСписок товаров пуст\n";
        return;
    }

    cout << "\n Список конфет \n";
    cout << "\tНазвание\tВес\tЦена\tНачинка\n";
    cout << "------------------------------------------------------\n";

    Node* current = head;
    int counter = 1;
    while (current != nullptr) {
        cout << counter << ".\t"
            << current->data.name << "\t\t"
            << current->data.weight << "\t"
            << current->data.price << "\t"
            << (current->data.filling ? "Да" : "Нет") << endl;

        current = current->next;
        ++counter;
    }
    cout << "------------------------------------------------------\n";
}

//Функция удаления элемента по номеру
void deleteNode(Node*& head) {
    if (head == nullptr) {
        cout << "\nСписок пуст\n";
        return;
    }

    printList(head);
    int index;
    cout << "Введите номер удаляемого элемента: ";
    cin >> index;

    if (index < 1) {
        cout << "Неверный номер\n";
        return;
    }

    //Удаление первого элемента
    if (index == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;       //Освобождаем память
        cout << "Элемент удален\n";
        return;
    }

    //Удаление элемента
    Node* current = head;
    for (int i = 1; i < index - 1; ++i) {
        if (current->next == nullptr) {
            cout << "Элемент не найден\n";
            return;
        }
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Элемент не найден\n";
        return;
    }

    Node* toDelete = current->next; //Запоминаем узел для удаления
    current->next = toDelete->next;
    delete toDelete;                //Освобождение памяти
    cout << "Элемент удален\n";
}

//Функция очистки списка
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Список очищен\n";
}

void saveToFile(Node* head) {
    ofstream file("C:\\Users\\freza\\OneDrive\\Desktop\\Semestrov\\data.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!\n";
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        file << current->data.name << " "
            << current->data.weight << " "
            << current->data.price << " "
            << current->data.filling << endl;
        current = current->next;
    }
    file.close();
    cout << "Данные сохранены в файл\n";
}

void loadFromFile(Node*& head) {
    ifstream file("C:\\Users\\freza\\OneDrive\\Desktop\\Semestrov\\data.txt");
    if (!file.is_open()) {
        cout << "Файл не найден\n";
        return;
    }

    //Очистка текущего списока
    clearList(head);

    Candy tempCandy;
    while (file >> tempCandy.name >> tempCandy.weight >> tempCandy.price >> tempCandy.filling) {
        //Новый узел
        Node* newNode = new Node;
        newNode->data = tempCandy;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    file.close();
    cout << "Список загружен из файла\n";
}

int main() {
    setlocale(LC_ALL, "rus");
    Node* head = nullptr;
    int choice;

    do {
        cout << "\n МЕНЮ \n";
        cout << "1. Вывести список товаров\n";
        cout << "2. Добавить товар\n";
        cout << "3. Удалить товар\n";
        cout << "4. Очистить список\n";
        cout << "5. Сохранить в файл\n";
        cout << "6. Загрузить из файла\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: printList(head); break;
        case 2: addNode(head); break;
        case 3: deleteNode(head); break;
        case 4: clearList(head); break;
        case 5: saveToFile(head); break;
        case 6: loadFromFile(head); break;
        case 0: cout << "Выход\n"; break;
        default: cout << "Неверный ввод\n";
        }
    } while (choice != 0);

    //Очистка памяти
    clearList(head);

    return 0;
}