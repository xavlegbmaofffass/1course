//Лабораторная работа 8. Полустатические структуры данных : очереди
#include <iostream>
#include "queue.h"

using namespace std;

void showMenu() {
    cout << "\nМеню операций:\n";
    cout << "1. Добавить элемент\n";
    cout << "2. Удалить элемент\n";
    cout << "3. Вывести очередь\n";
    cout << "4. Удалить первый отрицательный элемент\n";
    cout << "5. Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    QueueNode* front, * rear;
    initQueue(front, rear);

    int maxSize, currentSize = 0;
    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    int choice, value;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение: ";
            cin >> value;
            enqueue(front, rear, value, maxSize, currentSize);
            break;
        case 2:
            value = dequeue(front, rear, currentSize);
            if (value != INT_MIN) {
                cout << "Удален элемент: " << value << endl;
            }
            break;
        case 3:
            displayQueue(front);
            break;
        case 4:
            removeFirstNegative(front, rear, currentSize);
            break;
        case 5:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 5);

    // Очистка памяти
    while (!isEmpty(front)) {
        dequeue(front, rear, currentSize);
    }

    return 0;
}