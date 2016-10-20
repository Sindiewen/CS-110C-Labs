#include <iostream>
#include <sstream>
#include "ModifedLinkedList.h"

using namespace std;
int main()
{
    // Function variables
    string      inputNum;       // Stores the value the user enters into the list
    char        ynSel;          // Stores either a y/Y or n/N to select wheather the user wants yes or no
    int         i = 0;
    int         num;

    std::stringstream ss;

    // Creates a linked list object
    LinkedList <int>List1;      // The first linked list
    //LinkedList <int>List2;



    // Prompts user to enter a list of integers
    cout << "Enter a list of 6 integers: " << endl;

    for (int i = 0; i < 6; i++)
    {

    }

    /*
    // While the user continues to enter number into the stringstream
    while (getline(cin, inputNum))
    {
        ss.clear();
        ss.str(" ");
        ss << inputNum; // Stores values into the string of numbers

        while (List1.insert(i, (int)ss))
        {
            i++;
        }
    }
*/
/*
    List1.insert(1, 10);
    List1.insert(2, 14);
    List1.insert(3, 10);
    List1.insert(4, 13);
    List1.insert(5, 25);
    List1.insert(6, 10);

    List2.insert(1, 10);
    List2.insert(2, 14);
    List2.insert(3, 10);
    List2.insert(4, 13);
    List2.insert(5, 25);
    List2.insert(6, 10);
*/



    for(int i = 1; i <= List1.getLength(); i++)
    {
        std::cout << "Value at Node " << i << ": " << List1.getEntry(i) << std::endl;
    }

    std::cout << "The length of the linked list is " << List1.getLength() << std::endl;

    // Replacing a node:
    std::cout << "Replacing all nodes with value 10 with 2..." << std::endl;

    std::cout << "Number of items replaced: " << List1.replaceValue(10, 2) << std::endl;

    for (int i = 1; i <= List1.getLength(); ++i)
    {
        std::cout << "Value at Node " << i << ": " << List1.getEntry(i) << std::endl;
    }

    List1.clear();
    return 0;
}