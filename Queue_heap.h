#pragma once
#include"Node.h"

class QueueHeap {

private:
	Node* heap;
	int capacity;
	int size;

	int parent(int id);
	int leftChild(int id);
	int rightChild(int id);

	void resize();
	void Siftup(int id);
	void Siftdown(int id);

public:
	QueueHeap();
	QueueHeap(const QueueHeap& other);
	~QueueHeap();

	bool isEmpty() const;
	void insert(int data, int priority);
	int extractMax();
	int findMax() const;
	void modifyKey(int data, int new_priority);
	int returnSize() const;
	int getData(int id)const;
	int getPriority(int id)const;
	int findMaxPriority() const;
};
