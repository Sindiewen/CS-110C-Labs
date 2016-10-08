//
// Created by rachie on 10/7/16.
//

#ifndef LAB_3_POINTER_BASED_ADT_MODIFEDLINKEDLIST_H
#define LAB_3_POINTER_BASED_ADT_MODIFEDLINKEDLIST_H

#include "ModifiedListInterface.h"
#include "Node.h"

template <typename ItemType>
class LinkedList : public ModifiedListInterface<ItemType>
{
private:
    Node<ItemType> *headPrt;    // Points to the first node in the chain.
                                // Contains first entry in the list

    int itemCount;              // Counts the total items in the linked list

    Node<ItemType> *getNodeAt(int position) const;  // Locates a specific node in the linked list

public:
    LinkedList();
    LinkedList(const LinkedList<ItemType> &aList);
    virtual  ~LinkedList();


};

#endif //LAB_3_POINTER_BASED_ADT_MODIFEDLINKEDLIST_H
