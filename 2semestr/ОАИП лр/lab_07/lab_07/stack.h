#pragma once
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack();
    ~Stack();
    void push(int value);
    void pop();
    bool isEmpty() const;
    void clear();
    void display() const;
    void split(Stack& stack1, Stack& stack2) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif 