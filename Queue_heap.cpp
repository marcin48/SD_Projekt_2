#include"Queue_heap.h"
#include"Node.h"
#include<iostream>

using namespace std;

//Tworzymy kopiec po początkowej wielkości 0
QueueHeap::QueueHeap() : capacity(1), size(0) {
	heap = new Node[capacity];
}
QueueHeap::QueueHeap(const QueueHeap& other) {
	capacity = other.capacity;
	size = other.size;
	heap = new Node[capacity];
	for (int i = 0; i < size; i++) {
		heap[i] = other.heap[i];
	}
}
//Destruktor usuwa przydzieloną pamięć na kopiec
QueueHeap::~QueueHeap() {
	delete[] heap;

}

//numer ojca = [(k - 1) / 2], dla k > 0
int QueueHeap::parent(int id) {
	return (id - 1) / 2;
}

//numer lewego syna = 2k + 1
int QueueHeap::leftChild(int id) {
	return 2 * id + 1;
}

//numer prawego syna = 2k + 2
int QueueHeap::rightChild(int id) {
	return 2 * id + 2;
}

//Gdzy kopiec jest za mały tworzymy nowy o rozmiarze 2*stary
void QueueHeap::resize() {

	Node* newHeap = new Node[capacity * 2];
	for (int i = 0; i < capacity; i++) {
		newHeap[i] = heap[i];
	}
	delete[] heap;
	heap = newHeap;
	capacity = capacity * 2;
}

//Funkcja potrzebna do przesuwania elementu "w dół" kopca
void QueueHeap::Siftup(int id) {

	while (id > 0 and heap[parent(id)].priority < heap[id].priority) {
		swap(heap[parent(id)], heap[id]);
		id = parent(id);
	}
}

//Funkcja potrzebna do przesuwania elementu "w górę" kopca
void QueueHeap::Siftdown(int id) {

	int left = leftChild(id);
	int right = rightChild(id);
	int max = id;

	//Porównujemy priorytet rodzica  dziećmi jak jest mniejszy zbieramy id dziecka
	if (left<size and heap[left].priority>heap[max].priority) {
		max = left;
	}

	if (right<size and heap[right].priority>heap[max].priority) {
		max = right;
	}

	//Jak id początkowe się róz i znaczy że jesteśmy na złym miejscu; zamiana miejsca
	if (id != max) {
		swap(heap[id], heap[max]);
		Siftdown(max);
	}

}

//Dodawanie elemetu do kopca
void QueueHeap::insert(int data, int priority) {
	if (size == capacity) {
		resize();
	}
	heap[size].data = data;
	heap[size].priority = priority;

	size++;

	//Dodajemy na koniec więc musimy sprawdzic czy jest na właściwym miejscu
	Siftup(size - 1);


}

//Zbieramy korzeń kopca
int QueueHeap::findMax() const {
	if (size == 0) {
		cerr << "Brak elementów w kopcu" << endl;
		return -1;
	}

	//LIFO
	//int maxPriority = heap[0].priority;
	//int maxID = 0;

	//for (int i = 0; i < size; i++) {
	//	if (heap[i].priority > maxPriority or heap[i].priority == maxPriority) {
	//		maxPriority = heap[i].priority;
	//		maxID = i;
	//	}
	//}

	return heap[0].data;
}

//Modyfikujemy priorytet zadanego elementu
void QueueHeap::modifyKey(int data, int new_priority) {
	for (int i = 0; i < size; i++) {
		if (heap[i].data == data) {
			int old_P = heap[i].priority;
			heap[i].priority = new_priority;

			//W zależności od wartości priorytetu idziemy "w górę" lub "w dół"
			if (new_priority > old_P) {
				Siftup(i);
			}
			else {
				Siftdown(i);

			}
			return;

		}
	}
	cerr << "Nie znaleziono elementu w kopcu" << endl;
}

//Zwracamy rozmiar kopca
int QueueHeap::returnSize() const {
	return size;
}

//Usuwamy korzeń i go zwracamy
int QueueHeap::extractMax() {
	if (size == 0) {
		cerr << "Brak elementów w kopcu" << endl;
		return -1;
	}

	//Na miejsce korzenia wskakuje oststni element
	int maxData = heap[0].data;
	heap[0] = heap[size - 1];
	size--;

	//Trzeba ustawić strukturę kopca na nowo
	Siftdown(0);

	//LIFO

	//int maxPriority = heap[0].priority;
	//int maxID = 0;

	//for (int i = 0; i < size; i++) {
	//	if (heap[i].priority > maxPriority or heap[i].priority == maxPriority) {
	//		maxPriority = heap[i].priority;
	//		maxData = heap[i].data;
	//		maxID = i;
	//	}
	//}

	//swap(heap[maxID], heap[size - 1]);
	//size--;
	//Siftdown(maxID);

	return maxData;


}

//Kilka prostych funkcji pomocniczych
bool QueueHeap::isEmpty() const {
	return size == 0;
}

int QueueHeap::getData(int id)const {
	return heap[id].data;
}

int QueueHeap::getPriority(int id)const {
	return heap[id].priority;
}
int QueueHeap::findMaxPriority() const {
	if (size == 0) {
		cerr << "Brak elementów w kopcu" << endl;
		return -1;
	}
	return heap[0].priority;

}

