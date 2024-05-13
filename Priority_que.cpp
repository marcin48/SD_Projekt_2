#include <iostream>
#include "PriorityQueue.h"
#include"Queue_heap.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <chrono>

using namespace std;

void test() {
    PriorityQueueList pq;
    pq.insert(1, 2);
    pq.insert(2, 2);
    pq.insert(3, 2);
    pq.insert(4, 2);
    pq.insert(5, 2);
    

    cout << "Queue:\n";
    pq.print_queue();
    cout << "Max priority: " << pq.find_max().first << " " << pq.find_max().second << endl;
    cout << "Size " << pq.return_size() << endl;
    cout << endl;

    pq.modify_key(5, 10);
    cout << "Queue after modification:\n";
    pq.print_queue();
    cout << "Max priority: " << pq.find_max().first << " " << pq.find_max().second << endl;
    cout << "Size " << pq.return_size() << endl;
    cout << endl;

    pair<int, int> extracted = pq.extract_max();
    cout << "Extracted: " << extracted.first << " " << extracted.second << endl;
    

    cout << "Queue after extraction:\n";
    pq.print_queue();
    cout << "Max priority: " << pq.find_max().first << " " << pq.find_max().second << endl;
    cout << "Size " << pq.return_size() << endl;
    cout << endl;
    extracted = pq.extract_max();
    pq.print_queue();
    cout << endl;
    extracted = pq.extract_max();
    pq.print_queue();
    cout << endl;
}   
void load_from_file(const std::string& filename, QueueHeap& pq, int x) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout<< "Unable to open file " << filename << endl;
        return;
    }

    int value, priority;
    int count = 0;
    while (file >> value >> priority && count < x) {
        pq.insert(value, priority);
        ++count;
    }

    file.close();
}
void generate_values(int count, const std::string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout<< "Unable to open file " << filename << endl;
        return;
    }

    srand(time(nullptr)); 

    for (int i = 0; i < count; ++i) {
        int value = rand() % INT_MAX + 1;
        int priority = rand() % INT_MAX+1; 
        file << value << " " << priority <<endl;
    }

    file.close();
}
int main() {
    /*test();*/

    /*PriorityQueue pq;
    load_from_file("1000.txt", pq, 10);
    pq.print_queue();*/
    /*generate_values(50000, "50k_3.txt");*/
    int final_time1[15], final_time2[15], final_time3[15];
    
    for (int x = 2000; x <= 30000; x = x + 2000) {
        QueueHeap original1, original2, original3;
        load_from_file("50k_1.txt", original1, x);
        load_from_file("50k_2.txt", original2, x);
        load_from_file("50k_3.txt", original3, x);
        std::chrono::time_point<std::chrono::steady_clock> t1, t2;
        double czasy1[10], czasy2[10], czasy3[10];
        long int czas1 = 0, czas2 = 0, czas3 = 0;
        srand(time(nullptr));
        for (int i = 0; i < 10; i++) {
            QueueHeap* copy = new QueueHeap(original1);
            t1 = std::chrono::steady_clock::now();
            copy->modifyKey(1000,rand()%INT_MAX+1);
            t2 = std::chrono::steady_clock::now();
            czasy1[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 10;
            czas1 = czas1 + czasy1[i];
            cout << i << "  " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;
            delete copy;
        }
        srand(time(nullptr));
        for (int i = 0; i < 10; i++) {
            QueueHeap* copy = new QueueHeap(original2);
            t1 = std::chrono::steady_clock::now();
            copy->modifyKey(1000, rand() % INT_MAX + 1);
            t2 = std::chrono::steady_clock::now();
            czasy2[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 10;
            czas2 = czas2 + czasy2[i];
            cout << i << "  " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;
            delete copy;
        }
        srand(time(nullptr));
        for (int i = 0; i < 10; i++) {
            QueueHeap* copy = new QueueHeap(original3);
            t1 = std::chrono::steady_clock::now();
            copy->modifyKey(1000, rand() % INT_MAX + 1);
            t2 = std::chrono::steady_clock::now();
            czasy3[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 10;
            czas3 = czas3 + czasy3[i];
            cout << i << "  " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;
            delete copy;
        }
        final_time1[(x / 2000) - 1] = czas1;
        final_time2[(x / 2000) - 1] = czas2;
        final_time3[(x / 2000) - 1] = czas3;
    }
    cout<<endl << "Plik 1\n";
    for (int i = 0; i < 15; i++)
    {
        cout << final_time1[i] << endl;
    }
    cout << endl << "Plik 2\n";

    for (int i = 0; i < 15; i++)
    {
        cout << final_time2[i] << endl;
    }
    cout << endl << "Plik 3\n";
    for (int i = 0; i < 15; i++)
    {
        cout << final_time3[i] << endl;
    }
    return 0;
}
