#pragma once
#include <iostream>
#include "Node.h"
using namespace std;



class PriorityQueueList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    PriorityQueueList() : head(nullptr), tail(nullptr),size(0) {}
    PriorityQueueList(const PriorityQueueList& other);


    void insert(int data, int priority); //insertuje element o zadanej wadze

    pair<int, int> extract_max(); //Usuwa i zwraca element o najwyzszym priorytecie

    pair<int, int> find_max(); //Zwraca element o najwyzszym priorytecie
   
    void modify_key(int value, int new_priority); //Modyfikuje priorytet wszystkich elementów o zadanej wartoœci 

    int return_size(); //Zwraca liczbe elementow w kolejce

    void print_queue();

    int getValue(int index); //zwraca wartosc elementu o zadanym indeksie (liczac od elementu o najwyzszym priorytecie)
};
