#include<iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include<fstream>
#include"Node.h"
#include"Queue_heap.h"

using namespace std;
string cr, cl, cp;


void Test() {
    QueueHeap heap;

    // Test 1: Dodawanie kilku element�w i sprawdzenie najwy�szego priorytetu
    heap.insert(10, 3);
    heap.insert(20, 2);
    heap.insert(30, 1);
    heap.insert(40, 5);
    heap.insert(50, 4);

    cout << "Najwy�szy priorytet: " << heap.findMax() << endl;

    // Test 2: Usuwanie elementu o najwy�szym priorytecie
    cout << "Usuni�ty element o najwy�szym priorytecie: " << heap.extractMax() << endl; 
    cout << "Nowy najwy�szy priorytet: " << heap.findMax() << endl; 

    // Test 3: Modyfikacja priorytetu elementu
    heap.modifyKey(30, 6);
    cout << "Nowy najwy�szy priorytet po modyfikacji: " << heap.findMax() << endl;

    // Test 4: Dodanie elementu o ni�szym priorytecie i sprawdzenie, czy nie zmienia to najwy�szego priorytetu
    heap.insert(60, 3);
    cout << "Najwy�szy priorytet po dodaniu elementu o ni�szym priorytecie: " << heap.findMax() << endl;

    // Test 5: Usuni�cie wszystkich element�w
    while (!heap.isEmpty()) {
        cout << "Usuni�ty element o najwy�szym priorytecie: " << heap.extractMax() << endl;
    }
    cout << "Najwy�szy priorytet po usuni�ciu wszystkich element�w: " << heap.findMax() << endl;

}

void printBT(string sp, string sn, int v, QueueHeap& heap)
{
    if (v < heap.returnSize())
    {
        string s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        printBT(s + cp, cr, 2 * v + 2, heap);

        s = sp.substr(0, sp.length() - 2);

        cout << s << sn << heap.getData(v) << "," << heap.getPriority(v) << endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        printBT(s + cp, cl, 2 * v + 1, heap);
    }
}





void Test_2() {

    QueueHeap heap;

    // Inicjalizacja �a�cuch�w znakowych do rysowania ramki
    cr = cl = cp = "  ";
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;

    // Losowe wstawianie element�w do kopca
    srand(time(NULL));
    for (int i = 0; i < 15; i++)
    {
        int v = rand() % 100;
        heap.insert(v, i);
    }

    // Wy�wietlanie kopca jako drzewa binarnego
    printBT("", "", 0, heap);
    cout << endl << "-----------------------------------" << endl;

    cout << "Size: " << heap.returnSize() << endl;
    int a = heap.returnSize();

    while (a) {
        cout<<"Extracted (data, priority):" << heap.findMax() << ", " << heap.findMaxPriority() << endl;
        heap.extractMax();
        printBT("", "", 0, heap);
        a--;
        cout << endl << "-----------------------------------" << endl;

    }

}




int main() {

    int zmienna;
    while (true) {
        
        cout << endl << "-----------------------------------" << endl;
        cout << "Wybierz opcj�:" << endl;
        cout << "1. Og�lny test" << endl;
        cout << "2. Graficzna interpretacja" << endl;
        cin >> zmienna;
        cout << endl << "-----------------------------------" << endl;

        system("cls");

        switch (zmienna) {
        case 1:
            Test();
            break;
        case 2:
            Test_2();
            break;
        default:
            cout << "Brak takiej opcji!!!!" << endl;
        }
    }
}