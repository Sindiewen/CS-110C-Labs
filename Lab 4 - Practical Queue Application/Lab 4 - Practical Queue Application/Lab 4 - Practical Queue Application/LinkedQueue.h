//
// Created by Rachel Vancleave on 11/9/16.
//

#ifndef LinkedQueue_h
#define LinkedQueue_h

#include "QueueInterface.h"
#include "Node.h"

using namespace std;

template <typename ItemType>
class LinkedQueue
{
private:
    // The queue is implemented as a chain of lined nodes that has
    // two external pointers, a head pointer for the front of the queue
    // and a tail pointer for the back of the queue.
    Node<ItemType> *backPtr;
    Node<ItemType> *frontPtr;

public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue<ItemType> &aQueue);
    virtual ~LinkedQueue();

    bool isEmpty() const;                       // Returns weather the tree is empty or not.
    void enqueue(const ItemType &newEntry);     // Adds a value to the back of the queue.
    void dequeue();                             // Removes value from the front of the queue.
    ItemType peekFront() const;                 // Returns the item currently at the front of the queue.
};


////    Linked Queue Implementation     ////


// Class Constructor
template <typename ItemType>
LinkedQueue<ItemType>::LinkedQueue() : frontPtr(nullptr), backPtr(nullptr)
{
    // When Linked Queue object is created with no parameters, ensures
    // the front and the back pointers are empty as null
}


template <typename ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType> &aQueue)
{
    // Creates a new node pointing to the front pointer
    Node<ItemType> *origChainPtr = aQueue->frontPtr;

    // If the queue is empty when initializing the queue
    if (origChainPtr == nullptr)
    {
        frontPtr = nullptr;
        backPtr  = nullptr;
    }
    else // If the queue has values in it
    {
        // Copying the first node
        //  Declaring new node
        frontPtr = new Node<ItemType>();
        // Copies the value from the origChainPtr to the front ptr
        frontPtr->setItem(origChainPtr->getItem());
        origChainPtr = origChainPtr->getNext();

        // Copies the remaining nodes
        //  Declares new node
        Node<ItemType> *newChainPtr = frontPtr;

        while (origChainPtr != nullptr)
        {
            ItemType nextItem = origChainPtr->getItem();
            Node<ItemType> *newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr  = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }

        newChainPtr->setNext(nullptr);
        backPtr = newChainPtr;

    }
}


// Class Destructor// 
// Inserts into an empty queue
template <typename ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
    // While the queue is not empty...
    while(!isEmpty())
    {
        // Remove an item from the queue
        dequeue();
    }
}


// Checks if the queue is empty
template <typename ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
    // Returns if frontPtr is either null or not
    return frontPtr == nullptr;
}


// Enqueue - Adds an item to the back of the queue
template <typename ItemType>
void LinkedQueue<ItemType>::enqueue(const ItemType &newEntry)
{
    // Creates a new node
    Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry);

    // Inserts the new node
    //  if queue is empty
    if (isEmpty())
    {
        // Inserts into an empty queue
        frontPtr = newNodePtr;
    }
    else // If queue is not empty
    {
        // Inserts node to the back of the queue
        backPtr->setNext(newNodePtr);
    }
    backPtr = newNodePtr;   // New node is the back node
}


// dequeue - Removes value from the back of the queue
template <typename ItemType>
void LinkedQueue<ItemType>::dequeue()
{
    // Queue is not empty, delete front value
    Node<ItemType> *nodeToDeletePtr = frontPtr;

    // Only 1 value inside the queue
    if (frontPtr == backPtr)
    {
        frontPtr = nullptr;
        backPtr = nullptr;
    }
    else
    {
        frontPtr = frontPtr->getNext();
    }

    // Returns deleted node to the system
    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = nullptr;
}


// PeekFront - Returns the front value in the queue
template <typename ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const
{
    // Returns the front value in the queue
    return frontPtr->getItem();
}

// 

#endif /* LinkedQueue_h */
