#include <iostream>
#include <sstream>
#include "ModifedLinkedList.h"

using namespace std;
int main()
{
    // Function variables
    int     inputNum;       // Stores the value the user enters into the list
    int     modifiedNum;    // Stores value to replace
    int     replaceNum;     // Stores a value that will replace modifiedNum
    char    ynSel;          // Stores either a y/Y or n/N to select wheather the user wants yes or no

    std::stringstream ss;

    // Creates a linked list object
    LinkedList <int>List1;      // The first linked list
    //LinkedList <int>List2;



    // Prompts user to enter a list of integers
    cout << "Enter a list of 6 integers: " << endl;

    for (int i = 1; i <= 6; i++)
    {
        // Recieves input of ints
        cin >> inputNum;
        cin.ignore();

        // Inserts value into the linked list
        List1.insert(1, inputNum);
    }

    // Prompts the user to enter a value to modify
    cout << "Enter a number to be modified: ";
    cin  >> modifiedNum;
    cin.ignore();

    // Prompts the user to enter a number to replace
    cout << "Enter replacement value: ";
    cin  >> replaceNum;
    cin.ignore();

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

    // Replacing the node values
    std::cout << "Number of items replaced: " << List1.replaceValue(modifiedNum, replaceNum) << std::endl;



    // Prints the new list
    cout << "Modified List: ";
    for (int i = 1; i <= List1.getLength(); ++i)
    {
        std::cout << List1.getEntry(i) << " ";
    }

    List1.clear();
    return 0;
}