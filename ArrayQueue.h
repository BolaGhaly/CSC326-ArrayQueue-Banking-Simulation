#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_

#include "QueueInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 50;
	ItemType items[DEFAULT_CAPACITY]; // Array of queue items
	int front;                 // Index to front of queue
	int back;                  // Index to back of queue
	int count;                 // Number of items currently in the queue

public:
	ArrayQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();

	/** @throw PrecondViolatedExcep if queue is empty. */
	ItemType peekFront() const throw(PrecondViolatedExcep);
}; // end ArrayQueue
#include "ArrayQueue.cpp"
#endif
