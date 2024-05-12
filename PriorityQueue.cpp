#include "PriorityQueue.h"
#include "Node.h"
#include <iostream>
using namespace std;

void PriorityQueueList::insert(int data, int priority) {
    Node* newNode = new Node(data, priority);
    if (!head || priority > head->priority) {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
        if (!tail)
            tail = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next && (temp->next->priority >= priority)) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        if (!newNode->next)
            tail = newNode;
    }
}

pair<int, int> PriorityQueueList::extract_max() {
    if (!head) {
        cout << "Queue is empty!\n";
        return { -1,-1 };
    }
    int value = head->data;
    int priority = head->priority;
    head = head->next;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;
    return { value,priority };
}

pair<int, int> PriorityQueueList::find_max() {
    if (!head) {
        cout << "Queue is empty!\n";
        return { -1,-1 }; 
    }
    return { head->data, head->priority };
}

void PriorityQueueList::modify_key(int value, int new_priority) {
    Node* temp = head;
    while (temp) {
        if (temp->data == value) {
            temp->priority = new_priority;
            while (temp->prev && (temp->prev->priority < temp->priority)) { //przesuwa element w kierunku head
                Node* prev = temp->prev;
                Node* prevPrev = prev->prev;
                Node* next = temp->next;
                if (prevPrev) //jesli element 2 w tyl nie jest nullptr, to poprzedni element bedzie temp
                    prevPrev->next = temp;
                else
                    head = temp;
                temp->prev = prevPrev;
                temp->next = prev;
                prev->prev = temp;
                prev->next = next;
                if (next)
                    next->prev = prev;
            }
            while (temp->next && (temp->next->priority > temp->priority)) { //przesuwa element w kierunku tail 
                Node* next = temp->next;
                Node* nextNext = next->next;
                Node* prev = temp->prev;
                if (prev)
                    prev->next = next;
                else
                    head = next;
                next->prev = prev;
                next->next = temp;
                temp->prev = next;
                temp->next = nextNext;
                if (nextNext)
                    nextNext->prev = temp;
            }

        }
        temp = temp->next;
    }
}

int PriorityQueueList::return_size() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void PriorityQueueList::print_queue() {
    Node* temp = head;
    while (temp) {
        cout << "Value: " << temp->data << ", Priority: " << temp->priority << endl;
        temp = temp->next;
    }
}