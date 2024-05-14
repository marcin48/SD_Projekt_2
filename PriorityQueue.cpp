#include "PriorityQueue.h"
#include "Node.h"
#include <iostream>
using namespace std;

PriorityQueueList::PriorityQueueList(const PriorityQueueList& other) {
    head = nullptr;
    tail = nullptr;
    size = 0;
    Node* temp = other.head;
    while (temp != nullptr) {
        this->insert(temp->data, temp->priority);
        temp = temp->next;
    }
}

void PriorityQueueList::insert(int data, int priority) {
    Node* newNode = new Node(data, priority);
    if (!head || priority > head->priority) { //jeœli lista jest pusta albo priorytet jest wyzszy od najwyzszego priorytetu
        newNode->next = head; //head ustawiamy jako nastepny od Node
        if (head)
            head->prev = newNode; //jesli head juz jest (lista nie pusta) to ustawiamy prev glowy jako Node
        head = newNode; //nowa head to Node
        if (!tail)
            tail = newNode; //jesli lista byla pusta to ustawiamy Node tez jako tail 
    }
    else {
        Node* temp = head;
        while (temp->next && (temp->next->priority >= priority)) { //Szukanie pozycji do wstawienia - dopoki nie jest ostatnim elementem lub nastepny element >= priorytet
            temp = temp->next; 
        }
        newNode->next = temp->next; //ustawienie znalezionego Node
        if (temp->next) //jesli ten znaleziony nie jest ostatni to zmienia prev znalezionego
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        if (!newNode->next) //jesli Node jest ostatni to ustawia go jako tail 
            tail = newNode;
    }
    size++;
}

pair<int, int> PriorityQueueList::extract_max() {
    if (!head) {
        cout << "Queue is empty!\n";
        return { -1,-1 }; //zwraca blad jesli lista jest pusta
    }
    int value = head->data;
    int priority = head->priority; //przechowuje dane usuwanego elementu
    head = head->next; //head przesuwamy na nastepny element
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;
    size--;
    return { value,priority };
}

pair<int, int> PriorityQueueList::find_max() {
    if (!head) {
        cout << "Queue is empty!\n";
        return { -1,-1 }; //zwraca blad jesli lista jest pusta
    }
    return { head->data, head->priority };
}

void PriorityQueueList::modify_key(int value, int new_priority) {
    Node* temp = head;
    while (temp) { //przechodzi przez wszystkie elementy listy
        if (temp->data == value) { //wykonuje sie jesli znajdzie element o podanej wartosci
            temp->priority = new_priority; //zmienia priorytet
            while (temp->prev && (temp->prev->priority < temp->priority)) { //przesuwa element w kierunku head jesli poprzedni element ma < prio 
                Node* prev = temp->prev;
                Node* prevPrev = prev->prev;
                Node* next = temp->next;
                if (prevPrev) //jesli element 2 w tyl nie jest nullptr, to poprzedni element bedzie temp
                    prevPrev->next = temp;
                else //jesli 2 w tyl jest nullptr, to 1 w tyl jest glowa i podmieniamy je
                    head = temp;
                temp->prev = prevPrev;
                temp->next = prev;
                prev->prev = temp;
                prev->next = next; 
                if (next)
                    next->prev = prev;
            }
            while (temp->next && (temp->next->priority > temp->priority)) { //przesuwa element w kierunku tail jesli nastepny element ma > prio
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
    return size;
}


void PriorityQueueList::print_queue() {
    Node* temp = head;
    while (temp) {
        cout << "Value: " << temp->data << ", Priority: " << temp->priority << endl;
        temp = temp->next;
    }
}

int PriorityQueueList::getValue(int index) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        if (count == index) {
            return temp->data; //zwraca wartosc elementu o zadanym indeksie
        }
        temp = temp->next;
    }
    cout << "Element not found!\n";
    return -1; //zwraca blad jesli nie ma elementu o takim indeksie
}