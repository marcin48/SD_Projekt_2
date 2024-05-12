#pragma once
#include <iostream>
#include "Node.h"
using namespace std;



class PriorityQueueList {
private:
    Node* head;
    Node* tail;

public:
    PriorityQueueList() : head(nullptr), tail(nullptr) {}
    PriorityQueueList(const PriorityQueueList& other) {
        head = nullptr;
        tail = nullptr;
        Node* temp = other.head;
        while (temp != nullptr) {
            this->insert(temp->data, temp->priority);
            temp = temp->next;
        }
    }


    void insert(int data, int priority);

    pair<int, int> extract_max();

    pair<int, int> find_max();
   
    void modify_key(int value, int new_priority);

    int return_size();

    void print_queue();
};
