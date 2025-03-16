//Лабораторная работа 6. Динамические структуры данных.Односвязные списки
//Вариант 8
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

//struct Node {
//    int data;
//    Node* next;
//};
//
//void insert(Node*& head, int value);              
//void printList(Node* head);                       
//void toFile(Node* head);                        
//void fromFile(Node*& head);                        
//void menu();                                     
//int sumNegativeMultiplesOfTwo(Node* head);        
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    Node* head = nullptr;
//    int choice, value;
//    menu(); 
//    cout << "? ";
//    cin >> choice;
//
//    while (choice != 5) {
//        switch (choice) {
//        case 1:
//            cout << "Введите значение: ";
//            cin >> value;
//            insert(head, value);
//            printList(head);
//            break;
//        case 2:
//            toFile(head);
//            break;
//        case 3:
//            fromFile(head);
//            printList(head);
//            break;
//        case 4:
//        {
//            int sum = sumNegativeMultiplesOfTwo(head);
//            if (sum != 0) {
//                cout << "Сумма отрицательных элементов, кратных 2: " << sum << endl;
//            }
//            else {
//                cout << "Отрицательных элементов, кратных 2, не найдено.\n";
//            }
//            break;
//        }
//        default:
//            cout << "Неправильный выбор" << endl;
//            menu();
//            break;
//        }
//        cout << "? ";
//        cin >> choice;
//    }
//
//    return 0;
//}
//
//void insert(Node*& head, int value) {
//    Node* newNode = new Node;
//    if (newNode != nullptr) { // есть ли место?
//        newNode->data = value;
//        newNode->next = head;
//        head = newNode;
//    }
//    else {
//        cout << "Операция добавления не выполнена" << endl;
//    }
//}
//
//void printList(Node* head) {
//    if (head == nullptr) {
//        cout << "Список пуст" << endl;
//    }
//    else {
//        cout << "Список:" << endl;
//        while (head != nullptr) {
//            cout << "-->" << head->data;
//            head = head->next;
//        }
//        cout << "-->NULL" << endl;
//    }
//}
//
//void toFile(Node* head) {
//    Node* temp = head;
//    ofstream outFile("list.dat");
//    if (outFile.fail()) {
//        cout << "\nОшибка открытия файла";
//        exit(1);
//    }
//    while (temp) {
//        outFile.write((char*)&temp->data, sizeof(int));
//        temp = temp->next;
//    }
//    outFile.close();
//    cout << "Список записан в файл list.dat\n";
//}
//
//void fromFile(Node*& head) {
//    ifstream inFile("list.dat");
//    if (inFile.fail()) {
//        cout << "\nОшибка открытия файла";
//        exit(1);
//    }
//    int value;
//    while (inFile.read((char*)&value, sizeof(int))) {
//        insert(head, value);
//    }
//    inFile.close();
//    cout << "\nСписок считан из файла list.dat\n";
//}
//
//int sumNegativeMultiplesOfTwo(Node* head) {
//    int sum = 0;
//    bool hasNegative = false;
//    while (head != nullptr) {
//        if (head->data < 0 && head->data % 2 == 0) {
//            sum += head->data;
//            hasNegative = true;
//        }
//        head = head->next;
//    }
//    return hasNegative ? sum : 0;
//}
//
//void menu() {
//    cout << "Сделайте выбор:" << endl;
//    cout << "1 - Ввод значения" << endl;
//    cout << "2 - Запись списка в файл" << endl;
//    cout << "3 - Чтение списка из файла" << endl;
//    cout << "4 - Сумма отрицательных элементов, кратных 2" << endl;
//    cout << "5 - Выход" << endl;
//}



//Доп. +6
//struct Node {
//    int data;
//    Node* next;
//};
//
//void insert(Node*& head, int value);
//void printList(Node* head);
//void toFile(Node* head);
//void fromFile(Node*& head);
//void menu();
//int sumNegativeMultiplesOfFive(Node* head);
//
//int main() {
//    setlocale(LC_CTYPE, "Russian");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    Node* head = nullptr;
//    int choice, value;
//    menu();
//    cout << "? ";
//    cin >> choice;
//
//    while (choice != 5) {
//        switch (choice) {
//        case 1:
//            cout << "Введите значение: ";
//            cin >> value;
//            insert(head, value);
//            printList(head);
//            break;
//        case 2:
//            toFile(head);
//            break;
//        case 3:
//            fromFile(head);
//            printList(head);
//            break;
//        case 4:
//        {
//            int sum = sumNegativeMultiplesOfFive(head);
//            if (sum != 0) {
//                cout << "Сумма отрицательных элементов, кратных 5: " << sum << endl;
//            }
//            else {
//                cout << "Отрицательных элементов, кратных 5, не найдено.\n";
//            }
//            break;
//        }
//        default:
//            cout << "Неправильный выбор" << endl;
//            menu();
//            break;
//        }
//        cout << "? ";
//        cin >> choice;
//    }
//
//    return 0;
//}
//
//void insert(Node*& head, int value) {
//    Node* newNode = new Node;
//    if (newNode != nullptr) { // есть ли место?
//        newNode->data = value;
//        newNode->next = head;
//        head = newNode;
//    }
//    else {
//        cout << "Операция добавления не выполнена" << endl;
//    }
//}
//
//void printList(Node* head) {
//    if (head == nullptr) {
//        cout << "Список пуст" << endl;
//    }
//    else {
//        cout << "Список:" << endl;
//        while (head != nullptr) {
//            cout << "-->" << head->data;
//            head = head->next;
//        }
//        cout << "-->NULL" << endl;
//    }
//}
//
//void toFile(Node* head) {
//    Node* temp = head;
//    ofstream outFile("list.dat");
//    if (outFile.fail()) {
//        cout << "\nОшибка открытия файла";
//        exit(1);
//    }
//    while (temp) {
//        outFile.write((char*)&temp->data, sizeof(int));
//        temp = temp->next;
//    }
//    outFile.close();
//    cout << "Список записан в файл list.dat\n";
//}
//
//void fromFile(Node*& head) {
//    ifstream inFile("list.dat");
//    if (inFile.fail()) {
//        cout << "\nОшибка открытия файла";
//        exit(1);
//    }
//    int value;
//    while (inFile.read((char*)&value, sizeof(int))) {
//        insert(head, value);
//    }
//    inFile.close();
//    cout << "\nСписок считан из файла list.dat\n";
//}
//
//int sumNegativeMultiplesOfFive(Node* head) {
//    int sum = 0;
//    bool hasNegative = false;
//
//    while (head != nullptr) {
//        if (head->data < 0 && head->data % 5 == 0) {
//            sum += head->data;
//            hasNegative = true;
//        }
//        head = head->next;
//    }
//
//    return hasNegative ? sum : 0; 
//}
//
//void menu() {
//    cout << "Сделайте выбор:" << endl;
//    cout << "1 - Ввод значения" << endl;
//    cout << "2 - Запись списка в файл" << endl;
//    cout << "3 - Чтение списка из файла" << endl;
//    cout << "4 - Сумма отрицательных элементов, кратных 5" << endl;
//    cout << "5 - Выход" << endl;
//}