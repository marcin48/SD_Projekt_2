#include"Queue_heap.h"
#include"Node.h"
#include<iostream>

using namespace std;

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

QueueHeap::~QueueHeap() {
	delete[] heap;

}

int QueueHeap::parent(int id) {
	return (id - 1) / 2;
}

int QueueHeap::leftChild(int id) {
	return 2 * id + 1;
}

int QueueHeap::rightChild(int id) {
	return 2 * id + 2;
}

void QueueHeap::resize() {

	Node* newHeap = new Node[capacity * 2];
	for (int i = 0; i < capacity; i++) {
		newHeap[i] = heap[i];
	}
	delete[] heap;
	heap = newHeap;
	capacity = capacity * 2;
}


void QueueHeap::Siftup(int id) {

	while (id > 0 and heap[parent(id)].priority < heap[id].priority) {
		swap(heap[parent(id)], heap[id]);
		id = parent(id);
	}
}

void QueueHeap::Siftdown(int id) {

	int left = leftChild(id);
	int right = rightChild(id);
	int max = id;

	if (left<size and heap[left].priority>heap[max].priority) {
		max = left;
	}

	if (right<size and heap[right].priority>heap[max].priority) {
		max = right;
	}

	if (id != max) {
		swap(heap[id], heap[max]);
		Siftdown(max);
	}

}

void QueueHeap::insert(int data, int priority) {
	if (size == capacity) {
		resize();
	}
	heap[size].data = data;
	heap[size].priority = priority;

	size++;
	Siftup(size - 1);


}

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

void QueueHeap::modifyKey(int data, int new_priority) {
	for (int i = 0; i < size; i++) {
		if (heap[i].data == data) {
			int old_P = heap[i].priority;
			heap[i].priority = new_priority;
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

int QueueHeap::returnSize() const {
	return size;
}

int QueueHeap::extractMax() {
	if (size == 0) {
		cerr << "Brak elementów w kopcu" << endl;
		return -1;
	}
	int maxData = heap[0].data;
	heap[0] = heap[size - 1];
	size--;
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

