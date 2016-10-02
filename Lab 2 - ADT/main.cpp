#include <iostream>
#include "ModifiedArrayList.h"
#include "ModifiedListInterface.h"

int main()
{

    int data1 = 24, data2 = 42, data3 = 12;

    ModifiedArrayList <int> myList;
    ModifiedListInterface <int> *myListInterface = &myList;

    std::cout << "Hello, World! ArrayList Test:\n Adding 3 values:" << std::endl;

    myListInterface->insert(1, data1);
    myListInterface->insert(2, data2);
    myListInterface->insert(3, data3);

    std::cout << "\n";

    myListInterface->getEntry(1);

    std::cout << "Is list empty? " << myListInterface->isEmpty() << std::endl;

    std::cout << "Printing all entries: " << myListInterface->getEntry(1)
         << " " << myListInterface->getEntry(2) << " " << myListInterface->getEntry(3);

    myListInterface->clear();


    return 0;
}