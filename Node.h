#pragma once
class Node {
public:
    int data;
    int priority;
    Node* next;
    Node* prev;

    Node(int v, int p) : data(v), priority(p), next(nullptr), prev(nullptr) {}
};