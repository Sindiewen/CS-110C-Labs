//
// Created by rachie on 10/7/16.
//
/*
 * Node.h
 *
 */
#ifndef LAB_3_POINTER_BASED_ADT_NODE_H
#define LAB_3_POINTER_BASED_ADT_NODE_H

template <typename ItemType>
class Node
{
public:
    ItemType        item;   // A Data item - Stores value in a node
    Node<ItemType> *next;   // Pointer to the next node in the chain


    Node();                                                     // Node class Constructor
                                                                // Default constructoii - no values passed
    Node(const ItemType &anItem);                               // Node Class Constructor
                                                                // Only a item has been passed in
    Node(const ItemType &anItem, Node<ItemType> *nextNodePtr);  // Node Class Constructor
                                                                // Item passed in, and a location for the next node

    void setItem(const ItemType& anItem);       // Sets a value into the node
    void setNext(Node<ItemType> *nextNodePtr);  // Sets the next node on the list

    ItemType getItem() const;   // Returns the value stores in the node

    Node<ItemType> *getNext() const;    // Gets the next node in the list


};

// Linked List Implementation //

template <typename ItemType>
Node<ItemType>::Node() : next(nullptr)
{
    // Sets the next node to nullptr
    // End Default Constructor
}

template <typename ItemType>
Node<ItemType>::Node(const ItemType &anItem) : item(anItem), next(nullptr)
{
    // Stores the passed anItem into the item value
    // Sets the next node to nullptr
}

template <typename ItemType>
Node<ItemType>::Node(const ItemType &anItem, Node<ItemType> *nextNodePtr) : item(anItem), next(nextNodePtr)
{
    // Sets item to the passed anItem
    // Sets next to the nextNodePtr passed
}

template <typename ItemType>
void Node<ItemType>::setItem(const ItemType &anItem)
{
    // stores the passed anItem to item
    item = anItem;
}

template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr)
{
    // stores the passed nextNodePtr to next
    next = nextNodePtr;
}

template <typename ItemType>
ItemType Node<ItemType>::getItem() const
{
    // Returns the stored item
    return item;
}

template <typename ItemType>
Node<ItemType> *Node<ItemType>::getNext() const
{
    // Returns the next node in the list
    return next;
}

#endif //LAB_3_POINTER_BASED_ADT_NODE_H












