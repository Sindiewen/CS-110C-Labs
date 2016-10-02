//
// Created by Rachel Vancleave on 9/30/16.
//

#ifndef LAB_2_ADT_MODIFIEDLISTINTERFACE_H
#define LAB_2_ADT_MODIFIEDLISTINTERFACE_H

template <typename ItemType>
class ModifiedListInterface
{
public: // Public class functions

    // Abstract data types

    // Virtual Function: Checks to see if list if empty
    virtual bool isEmpty() const = 0;

    // Virtual Function: Returns the current list length
    virtual int getLength() const = 0;

    // Virtual Function: Inserts a new entry value into the list
    virtual void insert(int newPosition, const ItemType &newEntry) = 0;

    // Virtual Function: Removes a value from the list at a specific location
    virtual void remove(int position) = 0;

    // Virtual Function: removes all entries from the list
    virtual void clear() = 0;

    // Virtual Function: Gets the data at a specific location in the list
    virtual ItemType getEntry(int position) const = 0;

    // Virtual function: replaces the specified entry with a new value
    virtual void setEntry(int position, const ItemType &newEntry) = 0;

    // Compares the values inside the list, checking if it's in ascending order
    virtual bool isInAscendingOrder() = 0;
};

#endif //LAB_2_ADT_MODIFIEDLISTINTERFACE_H
