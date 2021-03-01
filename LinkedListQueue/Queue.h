#ifndef QUEUE_H
#define QUEUE_H
#include "ItemType.h"
#include <cstddef>
#include <new>

class FullQueue {};
class EmptyQueue {};

struct Node
{
	ItemType iData; //Data field of the node.
	Node* pNext; //Pointer to next node.
};

class Queue
{
private:
	Node* pFront;
	Node* pRear;

public:
	//Constructor:
	Queue();

	//Methods:
	void MakeEmpty();
	void Enqueue(ItemType iNewItem);
	void Dequeue(ItemType& iRemovedItem);
	bool IsEmpty() const;
	bool IsFull() const;

	//Destructor:
	~Queue();
};

#endif QUEUE_H