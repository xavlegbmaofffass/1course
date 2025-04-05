#pragma once
#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode {
    int data;
    QueueNode* next;
};

void initQueue(QueueNode*& front, QueueNode*& rear);
bool isEmpty(QueueNode* front);
void enqueue(QueueNode*& front, QueueNode*& rear, int value, int maxSize, int& currentSize);
int dequeue(QueueNode*& front, QueueNode*& rear, int& currentSize);
void displayQueue(QueueNode* front);
void removeFirstNegative(QueueNode*& front, QueueNode*& rear, int& currentSize);

#endif