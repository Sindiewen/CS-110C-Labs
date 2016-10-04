#include <iostream>
#include "ModifiedArrayList.h"

int main()
{
    // Variables
    const int ARR_SIZE = 5;   // Stores how many values are going to be in the array

    int values[5];      // Stores all the user inputted values

    char ynSelect;

    ModifiedArrayList <int> listNoMemberFunc;               // Creates object of the modifiedArrayList
    ModifiedArrayList <int> listIndependent;

    ModifiedListInterface <int> *listA = &listIndependent;  // Links the modifiedListInterface to the reference
                                                            // to the modifiedArrayList: ...Independent
    ModifiedListInterface <int> *listB = &listNoMemberFunc; // Links the modifiedListInterface to the reference
                                                            // to the modifiedArrayList: ...NoListMemberFunctions

    do
    {
        std::cout << "Using Independent Lists:\nEnter 5 integers to test: ";
        for(int i = 0; i < ARR_SIZE; i++)
        {
            std::cin >> values[i];
            listA->insert(i + 1, values[i]);

        }

        if (!listA->isInAscendingOrderIndependent())
        {
            std::cout << "Items are not in ascending order." << std::endl;
        }
        else
        {
            std::cout << "Items are in ascending order." << std::endl;
        }

        listA->clear();

        std::cout << "Do you want to continue (y/n): ";
        std::cin  >> ynSelect;
    }
    while (ynSelect == 'y' || ynSelect == 'Y');

    do
    {
        // User inputs 5 integers
        std::cout << "Using No List Member Functions:\nEnter 5 integers to test: ";
        for (int i = 0; i < ARR_SIZE; i++)
        {
            std::cin >> values[i];
            listB->insert(i + 1, values[i]);  // Inserts value into list
        }

        // Tests if integers are in ascending order
        if (!listB->isInAscendingOrderNoListMemberFunctions())
        {
            std::cout << "Items are not in ascending order." << std::endl;
        }
        else
        {
            std::cout << "Items are in ascending order." << std::endl;
        }

        // Clears list of integers
        listB->clear();

        // Asks if user want to check again
        std::cout << "Do you want to continue (y/n): ";
        std::cin  >> ynSelect;
    }
    while (ynSelect == 'y' || ynSelect == 'Y');



    return 0;
}