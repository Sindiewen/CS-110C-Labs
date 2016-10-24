//
// Created by Rachel Vancleave on 10/7/16.
//

#ifndef LAB_3_POINTER_BASED_ADT_MODIFEDLINKEDLIST_H
#define LAB_3_POINTER_BASED_ADT_MODIFEDLINKEDLIST_H

#include "ModifiedListInterface.h"
#include "Node.h"
#include <iostream>

template <typename ItemType>
class LinkedList : public ModifiedListInterface<ItemType>
{
private:
    Node<ItemType> *headPtr;    // Points to the first node in the chain.
                                // Contains first entry in the list

    int itemCount;              // Counts the total items in the linked list

    Node<ItemType> *getNodeAt(int position) const;  // Locates a specific node in the linked list

public:
    LinkedList();
    LinkedList(const LinkedList<ItemType> &aList);
    virtual  ~LinkedList();

    bool isEmpty() const;       // Returns weather the linked list is full or not
    int getLength() const;      // Returns the length of the linked list

    void insert (int newPosition, const ItemType &newEntry);    // Inserts a value into the list
    void remove (int position);                                 // Removes a value from a given position

    void clear();       // Empties the linked list

    ItemType getEntry(int position) const;                            // Returns the value at the given location

    void setEntry(int position, const ItemType &newEntry);      // Replaces value at location with another value

    // Replaces old values in the linked list with a new value
    int replaceValue(ItemType oldValue, ItemType newValue);

    // Compares 2 linked lists if they're both equal
    bool equals (LinkedList<ItemType> aList);


};

// Class Constructor
template<typename ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
    // Sets the head pointer to null, and the item count to 0
}

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &aList) : itemCount(aList.itemCount)
{
    // Points to nodes in the original chain
    Node<ItemType> *origChainPtr = aList.headPtr;

    if (origChainPtr == nullptr)
    {
        headPtr = nullptr;  // The original list is empty
    }
    else
    {
        // Copy the first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy the remaining nodes
        Node<ItemType> *newChainPtr = headPtr;
        origChainPtr = origChainPtr-> getNext();

        while (origChainPtr != nullptr)
        {
            // Get the next item from the original chain
            ItemType nextItem = origChainPtr -> getItem();

            // Create a new node containing the next item
            Node<ItemType> *newNodePtr = new Node <ItemType>(nextItem);

            // Link new node to the end of new chain
            newChainPtr->setNext(newNodePtr);

            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
    }
}

// Class Destructor
template <typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();    // Clears the linked list
}

// Returns if the list is empty
template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return itemCount == 0;  // Returns if itemCount is 0
}

// Returns the length of the list
template<typename ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;   // Returns the size of the linked list
}

// Inserts a new value into the linked list
template <typename ItemType>
void LinkedList<ItemType>::insert(int newPosition, const ItemType &newEntry)
{
    // Creates new node
    Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry);

    // Attaches new node to the chain
    if (newPosition == 1)
    {
        // Insert new node at the beginning of the chain
        newNodePtr->setNext(headPtr);
        // Assigns the headPtr to the newest node
        headPtr = newNodePtr;
    }
    else
    {
        // Find node that will be before the new node
        Node<ItemType> *prevPtr = getNodeAt(newPosition - 1);

        // Insert new node after node to which prevPtr points
        newNodePtr->setNext(prevPtr->getNext());
        prevPtr->setNext(newNodePtr);
    }
    itemCount++;
}

// Removes a node the user chose
template<typename ItemType>
void LinkedList<ItemType>::remove(int position)
{
    Node<ItemType> *curPtr = nullptr;

    if (position == 1)
    {
        // Remove the first node in the chain
        curPtr = headPtr;   // Saves pointer to node
        headPtr = headPtr->getNext();
    }
    else
    {
        // Find node that is before the one to delete
        Node<ItemType> *prevPtr = getNodeAt(position - 1);

        // Point to node to delete
        curPtr = prevPtr->getNext();

        // Disconnect indicated node from chain by connecting the prior node iwht the one after
        prevPtr->setNext(curPtr->getNext());
    }

    // Returns node to the system
    curPtr->setNext(nullptr);
    delete curPtr;
    curPtr = nullptr;

    itemCount--;
}

// Removes every node in the linked list, clearning it
template <typename ItemType>
void LinkedList<ItemType>::clear()
{
    // While the linked list is not empty
    while (!isEmpty())
    {
        // Remove every node that is currently marked as the first node
        remove(1);
    }
}

// Returns the current entry at a selected node
template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
    Node<ItemType> *nodePtr = getNodeAt(position);
    return  nodePtr->getItem();
}

// Replaces a node with ai different value
template <typename ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType &newEntry)
{
    Node<ItemType> *nodePtr = getNodeAt(position);
    nodePtr->setItem(newEntry);
}

// Returns the current node
template <typename ItemType>
Node<ItemType> *LinkedList<ItemType>::getNodeAt(int position) const
{
    // Count from the beginning of the chain
    Node<ItemType> *curPtr = headPtr;

    for (int skip = 1; skip < position; skip++)
    {
        curPtr = curPtr->getNext();
    }

    return curPtr;
}


///////////////
// Lab 3 Implementation
///////////////

// Replaces old values in the linked list with a new value
//		this funciton is called from the driver program, It will take the object of
// the linked list, pass in 2 values, an old value and a new value, and go through
// each value of the linked list replacing the respective old value with the new value.
//		@param ItemType template value for old value and newValue.
//		@pre none
//		@post A new pointer is created claled replacePtr. Pointing to the headPtr.
//	While the replacePtr is not null, it will check if the current value it's pointing
//	is the same as the old value. If it is, it will replace the value with the new value.
//	If not, it will just move onto the next value untill the replacePtr reaches a nullPtr.
//	When it succssfully replaces an old value, it will iterate the counter by 1. Once finished,
//	it will return the ammount of values it has successfully changed.
template <typename ItemType>
int LinkedList<ItemType>::replaceValue(ItemType oldValue, ItemType newValue)
{
    int counter = 0;

    // Creates a new pointer, replacePtr, pointing to the headPtr
    Node<ItemType> *replacePtr = headPtr;

    // While the replacePtr is not null
    while (replacePtr != nullptr)
    {
        // If the current node value == to the old value
        if (replacePtr->item == oldValue)
        {
            // Replace said item with the new item passed
            replacePtr->item = newValue;

            // Iterates the counter by 1
            counter++;
        }
        // Sets the replacePtr to the next value
        replacePtr = replacePtr->next;
    }

    // Returns the current count of how many items replaced
    return counter;
}

// Compares 2 linked lists if they're both equal
//		This function is called from the driver program. It will take the object of
//	the linked list, and pass in 1 more value, another Linked list. Comparing this
//	current linked list with the passed in Linked List.
//		@param A ItemType template value of a Linked List to compare with.
//		@pre none
//		@post 2 Pointers will be created. equalsPtr pointing to this linkedList headPtr,
//	and aListPtr, pointing to the passed 'aList' headPtr. While both thoes pointers are
//	not nullPtr, it will check weather both lists have the same vaules. If at any moment
//	one of the lists has a different value than the other list, it will terminate and
//	return false. If it successfully completes going through the linked list, at the end
//	It will return true telling the user both lists have the same values in it.
template <typename ItemType>
bool LinkedList<ItemType>::equals(LinkedList<ItemType> aList)
{
	// Declaring new Nodes to test
    Node<ItemType> *equalsPtr = headPtr;		// equalsPtr points to the current list's headPtr
    Node<ItemType> *aListPtr = aList.headPtr;	// aListPtr points to the Passed in lists headPtr
	
	while (equalsPtr != nullptr && aListPtr != nullptr)
	{
		// If the current item of both lists are not false
		if (equalsPtr->item != aListPtr->item) {
			// Returns false. Both lists are not the same
			return false;
		}
		
		// Sets the equalsPtr and the listPtr to the next value to compare
		equalsPtr = equalsPtr->next;
		aListPtr = aListPtr->next;
	}
	// Returns true when the both the list's have been iterated through and tested true
	return true;
}


#endif //LAB_3_POINTER_BASED_ADT_MODIFEDLINKEDLIST_H






















