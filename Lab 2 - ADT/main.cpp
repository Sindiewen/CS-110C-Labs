#include <iostream>
#include "ModifiedArrayList.h"

int main()
{
    // Variables
    const int ARR_SIZE = 5;   // Stores how many values are going to be in the array

    int values[5];      // Stores all the user inputted values

    char ynSelect;

    ModifiedArrayList <int> myList;                         // Creates object of the modifiedArrayList
    ModifiedListInterface <int> *myListInterface = &myList; // Links the modifiedListInterface to the reference to the modifiedArrayList

    do
    {
        // User inputs 5 integers
        std::cout << "Enter 5 integers to test: ";
        for (int i = 0; i < ARR_SIZE; i++)
        {
            std::cin >> values[i];
            myListInterface->insert(i + 1, values[i]);  // Inserts value into list
        }

        // Tests if integers are in ascending order
        if (!myListInterface->isInAscendingOrder())
        {
            std::cout << "Items are not in ascending order." << std::endl;
        }
        else
        {
            std::cout << "Items are in ascending order." << std::endl;
        }
        // Clears list of integers
        myListInterface->clear();

        // Asks if user want to check again
        std::cout << "Do you want to continue (y/n): ";
        std::cin  >> ynSelect;
    }
    while (ynSelect == 'y' || ynSelect == 'Y');



    return 0;
}