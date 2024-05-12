#pragma once
class Node {
public:
    int value;
    int priority;
    Node* next;

    Node(int v, int p) : value(v), priority(p), next(nullptr) {}
};
