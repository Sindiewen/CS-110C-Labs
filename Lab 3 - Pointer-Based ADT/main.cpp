#include <iostream>
#include <sstream>
#include "ModifedLinkedList.h"

// Function prototypes
void replaceLinkedListValues    (LinkedList<int> list, int &inputNum, int &modifiedNum, int &replaceNum);    // Replaces values in the list
void compareLinkedListVales     (LinkedList<int> listA, LinkedList<int> listB, int &inputNum);             // Compares values in 2 lists

using namespace std;
int main()
{
    // Function variables
    int     inputNum;       // Stores the value the user enters into the list
    int     modifiedNum;    // Stores value to replace
    int     replaceNum;     // Stores a value that will replace modifiedNum
    int     funcSel;        // Allows user to choose what function they want to run
    char    ynSel;          // Stores either a y/Y or n/N to select wheather the user wants yes or no

    std::stringstream ss;

    // Creates a linked list object
    LinkedList <int>List1;      // The first linked list
    LinkedList <int>List2;      // The second linked list

    do
    {
        // Prints to the user what functions are avaliable
        cout << "What function would you like to run?" << endl;
        cout << "1 ----- Replace values in a linked list" << endl;
        cout << "2 ----- Compare 2 linked lists" << endl;
        cout << "0 ----- Close program" << endl;
        cout << "> ";

        // User inputs what function to run
        cin  >> funcSel;

        // Allows user to chose what function to run
        switch (funcSel)
        {
                // Replace values in the linked list
            case 1:
                replaceLinkedListValues(List1, inputNum, modifiedNum, replaceNum);
                break;

                // Compare values in 2 linked lists
            case 2:
                compareLinkedListVales(List1, List2, inputNum);
                break;

                // Ends the program
            case 0:
                cout << "Closing program..." << endl;
                break;

                // Default: invalid option
            default:
                cout << "Invalid option selected, please enter a valid selection..." << endl << endl << endl;
        }
    }
    while (funcSel != 0); // Continues running as long as the user input is not 0

    // Clearing the Linked Lists
    List1.clear();
    List2.clear();

    // Ends program
    return 0;
}


// Replaces values in the list
void replaceLinkedListValues(LinkedList<int> list, int &inputNum, int &modifiedNum, int &replaceNum)
{
    // Prompts user to enter a list of integers
    cout << "Enter a list of 6 integers followed by the enter/return key: " << endl;

    for (int i = 1; i <= 6; i++)
    {
        // Receives input of ints
        cin >> inputNum;
        cin.ignore();

        // Inserts value into the linked list
        list.insert(1, inputNum);
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
    std::cout << "Number of items replaced: " << list.replaceValue(modifiedNum, replaceNum) << std::endl;

    // Prints the new list
    cout << "Modified List: ";
    for (int i = 1; i <= list.getLength(); ++i)
    {
        std::cout << list.getEntry(i) << " ";
    }

    cout << endl << endl <<"------------------------------" << endl << endl;
}


// Compares values in 2 lists
void compareLinkedListVales (LinkedList<int> listA, LinkedList<int> listB, int &inputNum)
{
    // Prompts user to enter a list of integers
    cout << "Enter first list of 6 integers followed by the enter/return key: " << endl;

    for (int i = 1; i <= 6; i++)
    {
        // Receives input of ints
        cin >> inputNum;
        cin.ignore();

        // Inserts value into the linked list
        listA.insert(1, inputNum);
    }

    // Prompts user to enter a list of integers
    cout << "Enter second list of 6 integers followed by the enter/return key: " << endl;

    for (int i = 1; i <= 6; i++)
    {
        // Receives input of ints
        cin >> inputNum;
        cin.ignore();

        // Inserts value into the linked list
        listB.insert(1, inputNum);
    }

    listA.equals(listB);
}
