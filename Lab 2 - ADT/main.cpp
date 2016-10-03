#include <iostream>
#include "ModifiedArrayList.h"

int main()
{

    int data1 = 24, data2 = 42, data3 = 12;

    ModifiedArrayList <int> myList;
    ModifiedArrayList <int> myList2;
    ModifiedListInterface <int> *myListInterface = &myList;
    ModifiedListInterface <int> *myListInterface2 = &myList2;

    std::cout << "Hello, World! ArrayList Test:\n Adding 3 values:" << std::endl;

    myListInterface->insert(1, data3);
    myListInterface->insert(2, data1);
    myListInterface->insert(3, data2);

    std::cout << "\n";

    std::cout << "Getting the first entry: " << myListInterface->getEntry(1) << std::endl;

    std::cout << "Testing isInAscendingOrder(): " << myListInterface->isInAscendingOrder() << std::endl;

    myListInterface->clear();


    return 0;
}