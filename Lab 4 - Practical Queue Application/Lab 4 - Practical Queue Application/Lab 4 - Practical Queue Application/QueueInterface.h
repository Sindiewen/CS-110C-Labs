//
// Created by Rachel Vancleave on 11/9/16.
//

#ifndef QueueInterface_h
#define QueueInterface_h

template <typename ItemType>
class QueueInterface
{
public:
	// Checks if queue is empty
	virtual bool isEmpty() const = 0;
	
	// Enqueue - Adds a value to the back of the queue
	virtual void enqueue (const ItemType& newEntry) = 0;
	
	// Dequeue - Removes value from the front of the queue
	virtual void dequeue() = 0;
	
	// Returns the first value from the front of the queue
	virtual ItemType peekFront() const = 0;
	
	
};

#endif /* QueueInterface_h */
