#include <iostream>
#include <climits>
#include "queue.h"

using namespace std;

void initQueue(QueueNode*& front, QueueNode*& rear) {
    front = rear = nullptr;
}

bool isEmpty(QueueNode* front) {
    return front == nullptr;
}

void enqueue(QueueNode*& front, QueueNode*& rear, int value, int maxSize, int& currentSize) {
    if (currentSize >= maxSize) {
        cout << "Очередь переполнена!" << endl;
        return;
    }

    QueueNode* newNode = new QueueNode;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty(front)) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    currentSize++;
    cout << "Добавлен элемент: " << value << endl;
}

int dequeue(QueueNode*& front, QueueNode*& rear, int& currentSize) {
    if (isEmpty(front)) {
        cout << "Очередь пуста!" << endl;
        return INT_MIN;
    }

    QueueNode* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    currentSize--;
    return value;
}

void displayQueue(QueueNode* front) {
    if (isEmpty(front)) {
        cout << "Очередь пуста!" << endl;
        return;
    }

    cout << "Содержимое очереди: ";
    QueueNode* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void removeFirstNegative(QueueNode*& front, QueueNode*& rear, int& currentSize) {
    if (isEmpty(front)) {
        cout << "Очередь пуста!" << endl;
        return;
    }

    if (front->data < 0) {
        cout << "Удален отрицательный элемент: " << dequeue(front, rear, currentSize) << endl;
        return;
    }

    QueueNode* current = front;
    QueueNode* prev = nullptr;

    while (current != nullptr && current->data >= 0) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Отрицательных элементов не найдено." << endl;
    }
    else {
        prev->next = current->next;
        if (current == rear) {
            rear = prev;
        }
        cout << "Удален отрицательный элемент: " << current->data << endl;
        delete current;
        currentSize--;
    }
}