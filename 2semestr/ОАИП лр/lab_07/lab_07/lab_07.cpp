//Лабораторная работа 7. Полустатические структуры данных : стеки
#include <iostream>
#include "stack.h"

void menu() {
    cout << "Меню:\n";
    cout << "1. Добавить элемент в стек\n";
    cout << "2. Очистить стек\n";
    cout << "3. Показать стек\n";
    cout << "4. Сохранить стек в файл\n";
    cout << "5. Загрузить стек из файла\n";
    cout << "6. Разделить стек\n";
    cout << "7. Выход\n";
}

int main() {
    setlocale(LC_ALL, "ru");
    Stack stack;
    Stack stack1, stack2;
    int choice, value;
    string filename = "stack_data.txt";

    do {
        menu();
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите элемент: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.clear();
            cout << "Стек очищен." << endl;
            break;
        case 3:
            cout << "Элементы стека: ";
            stack.display();
            break;
        case 4:
            stack.saveToFile(filename);
            cout << "Стек сохранён в файл: " << filename << endl;
            break;
        case 5:
            stack.loadFromFile(filename);
            cout << "Стек загружен из файла: " << filename << endl;
            break;
        case 6:
            stack.split(stack1, stack2);
            cout << "Stack1 (values > 50): ";
            stack1.display();
            cout << "Stack2 (values <= 50): ";
            stack2.display();
            break;
        case 7:
            cout << "Выход." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 7);

    return 0;
}