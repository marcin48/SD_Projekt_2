#pragma once

class Node {
public:
    int data;
    int priority;
    Node* next;
    Node* prev;

    Node(int data, int priority) : data(data), priority(priority), next(nullptr), prev(nullptr) {};
    Node() : data(0), priority(0), next(nullptr), prev(nullptr) {}
    ~Node() {};
};

