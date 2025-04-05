#include "stack.h"
using namespace std;

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    clear();
}

void Stack::push(int value) {
    Node* newNode = new Node{ value, top };
    top = newNode;
}

void Stack::pop() {
    if (!isEmpty()) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::display() const {
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Stack::split(Stack& stack1, Stack& stack2) const {
    Node* current = top;
    while (current != nullptr) {
        if (current->data > 50) {
            stack1.push(current->data);
        }
        else {
            stack2.push(current->data);
        }
        current = current->next;
    }
}

void Stack::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        Node* current = top;
        while (current != nullptr) {
            outFile << current->data << endl;
            current = current->next;
        }
        outFile.close();
    }
}

void Stack::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        int value;
        while (inFile >> value) {
            push(value);
        }
        inFile.close();
    }
}