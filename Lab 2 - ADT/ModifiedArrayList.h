//
// Created by Rachel Vancleave on 9/30/16.
//

#ifndef LAB_2_ADT_MODIFIEDARRAYLIST_H
#define LAB_2_ADT_MODIFIEDARRAYLIST_H

#include "ModifiedListInterface.h"

template <typename ItemType>
class ModifiedArrayList : public ModifiedListInterface<ItemType>
{
private:    // Private Class Variables
    static const int MAX_LIST = 100;    // Stores the total amount of data in the array list
    ItemType items[MAX_LIST];           // Creates template array for the ArrayList, stores the items
    int itemCount;                      // counts how many items are inside the list currently

public:     // Public class Functions
    ModifiedArrayList();        // Class Constructor

    bool isEmpty() const;       // Checks if the list is empty

    int getLength() const;      // Gets the current length of the list

    void insert (int newPosition, const ItemType &newEntry);        // Inserts data into the ArrayList
    void remove (int position);                                     // removes value from ArrayList
    void clear  ();                                                 // Empties the ArrayList

    ItemType getEntry   (int position) const;                       // Gets the current value in the ArrayList
    void setEntry       (int position, const ItemType &newEntry);   // Replaces old data at a position with new data


    bool isInAscendingOrderIndependent();           // Checks if the current list is in ascending order
                                                    // Using member functions
    bool isInAscendingOrderNoListMemberFunctions();  // Checks if the current list is in ascending order
                                                    // Not using Member Functions
};


// Class Function Declarations //

// Class Constructor
template <typename ItemType>
ModifiedArrayList<ItemType>::ModifiedArrayList() : itemCount(0)
{
    // Initializes itemCount to be 0
}

// Checks if the list is empty
template <typename  ItemType>
bool ModifiedArrayList<ItemType>::isEmpty() const
{
    // Returns true or False if list is empty
    return itemCount == 0;
}


// Gets the current length of the list
template  <typename ItemType>
int ModifiedArrayList<ItemType>::getLength() const
{
    // Returns the current itemCount
    return itemCount;
}

// Inserts new data into the the list
template <typename ItemType>
void ModifiedArrayList<ItemType>::insert(int newPosition, const ItemType &newEntry)
{


    // Make room for new entry by shifting all entries at
    // positions >= newPosition towards the end of the array
    // (no shift if newPosition == itemCount + 1)
    for (int pos = itemCount; pos >= newPosition; pos--)
    {
        items[pos] = items[pos - 1];
    }

    // Inserts new entry
    items[newPosition - 1] = newEntry;
    itemCount++;
}

// Removes a value from the list
template <typename ItemType>
void ModifiedArrayList<ItemType>::remove(int position)
{
    for(int fromIndex = position, toIndex = fromIndex - 1;
            fromIndex < itemCount; fromIndex++, toIndex++)
    {
        items[toIndex] = items[fromIndex];
    }

    itemCount--;
}

// Clears the whole list
template <typename ItemType>
void ModifiedArrayList<ItemType>::clear()
{
   itemCount = 0;   // Effectivley "empties" the list, old values will be overwritten
}

// Returns the current value in the list
template <typename ItemType>
ItemType ModifiedArrayList<ItemType>::getEntry(int position) const
{
    return items[position - 1];
}

// Replaces a location in the list with new data
template <typename ItemType>
void ModifiedArrayList<ItemType>::setEntry(int position, const ItemType &newEntry)
{
    items[position = 1] = newEntry;
}

// Checks if the list is in ascending order, using member functions
template <typename ItemType>
bool ModifiedArrayList<ItemType>::isInAscendingOrderIndependent()
{
    // Loops through the list, checking the list to see if the values are in ascending order
    for (int i = 0; i < getLength(); i++)
    {
        // If i has not met the list length, and if the returned entry is greater than the next entry
        if (i != getLength() && getEntry(i) > getEntry(i + 1))
        {
            // List is currently not in ascending order
            return false;
        }
    }
    // Values are in ascending order
    return true;
}

// Checks if the list is in ascending order, Not using the list member functions
template  <typename ItemType>
bool ModifiedArrayList<ItemType>::isInAscendingOrderNoListMemberFunctions()
{
    // Loops through the list, checking the list to see if the values are in ascending order
    for (int i = 0; i < itemCount; i++)
    {
        // If i has not met itemCount and if the current item is less than the next item
        if (i != itemCount - 1 && items[i] > items[i + 1])
        {
            // Items are not in ascending order
            return false;
        }
    }
    // Items are in ascending order
    return true;
}

#endif //LAB_2_ADT_MODIFIEDARRAYLIST_H






































