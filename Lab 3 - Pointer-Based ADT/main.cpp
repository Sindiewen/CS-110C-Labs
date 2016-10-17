#include <iostream>
#include "ModifedLinkedList.h"
int main()
{
    LinkedList <int>myNode;

    myNode.insert(1, 10);
    myNode.insert(2, 14);
    myNode.insert(3, 10);
    myNode.insert(4, 13);
    myNode.insert(5, 25);
    myNode.insert(6, 10);




    for(int i = 1; i <= myNode.getLength(); i++)
    {
        std::cout << "Value at Node " << i << ": " << myNode.getEntry(i) << std::endl;
    }

    std::cout << "The length of the linked list is " << myNode.getLength() << std::endl;

    // Replacing a node:
    std::cout << "Replacing all nodes with value 9 with 2..." << std::endl;

    std::cout << "Number of items replaced: " << myNode.replaceValue(9, 2) << std::endl;

    for (int i = 1; i <= myNode.getLength(); ++i)
    {
        std::cout << "Value at Node " << i << ": " << myNode.getEntry(i) << std::endl;
    }

    myNode.clear();
    return 0;
}