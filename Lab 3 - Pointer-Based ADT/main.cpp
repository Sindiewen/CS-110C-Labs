#include <iostream>
#include "ModifedLinkedList.h"
int main()
{
    LinkedList <std::string>myNode;

    myNode.insert(1, "bunny");
    myNode.insert(2, "froggy");
    myNode.insert(3, "puppy");
    myNode.insert(4, "Eevee");
    myNode.insert(5, "iPhone");




    for(int i = 1; i <= myNode.getLength(); i++)
    {
        std::cout << "Value at Node " << i << ": " << myNode.getEntry(i) << std::endl;
    }

    std::cout << "The length of the linked list is " << myNode.getLength() << std::endl;

    myNode.remove(3);

    for (int i = 1; i <= myNode.getLength(); ++i)
    {
        std::cout << "The value at node " << i << ": " << myNode.getEntry(i) << std::endl;
    }

    myNode.clear();
    return 0;
}