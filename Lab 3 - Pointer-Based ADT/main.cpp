/*
 * @name	Rachel Vancleave
 * @date	10/24/16
 * @class	CS 110C
 * 
 * @summary This program using pointer based Abstract Data Types, allows the user to modify
 * up to 2 linked lists with 2 different programs.
 * 
 * Program 1: The user creates a linked list, and replace values inside of the linked list.
 * Program 2: The user creates 2 linked lists and compares both of them weather they have the same values.
 */

#include <iostream>
#include "ModifedLinkedList.h"

// Function prototypes
void replaceLinkedListValues    (LinkedList<int> &list, int &inputNum, int &modifiedNum, int &replaceNum, char &ynSel);		// Replaces values in the list
void compareLinkedListVales     (LinkedList<int> &listA, LinkedList<int> &listB, int &inputNum, char &ynSel);				// Compares values in 2 lists

using namespace std;

int main()
{
    // Function variables
    int     inputNum;       // Stores the value the user enters into the list
    int     modifiedNum;    // Stores value to replace
    int     replaceNum;     // Stores a value that will replace modifiedNum
    int     funcSel;        // Allows user to choose what function they want to run
	
	char	ynSel;			// Allows user to choose wheather they want to run the program again

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
				replaceLinkedListValues(List1, inputNum, modifiedNum, replaceNum, ynSel);
                break;

                // Compare values in 2 linked lists
            case 2:
				compareLinkedListVales(List1, List2, inputNum, ynSel);
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


// Replaces values in a linked list
//		User inputs 6 values into the linked list. The user is given a prompt to enter a number to replace
//	all the occuring numbers in the list, and replaces thoes numbers with a number the user enters.
//		@param Passes 1 int linked list, an integer for input, a number to modify in the list,
//	the number to replace in the list, and a value for selecting y/n.
//		@pre none
//		@post User inputs 6 numbers into the list. It will place them into the linked ist one after another.
//	User inputs a a series of numbers into 'inputNum' placing them into the list. The user enters into
//	modifiedNum a number they want to have modified in the linked list and it's reccuring values. The user
//	enter a number to replace thoes values with. It will iterate through the list and change them accordingly,
//	and print them out to the console.
//		It will ask the user if they would like to replace values into the linked list again after the program has run.
void replaceLinkedListValues(LinkedList<int> &list, int &inputNum, int &modifiedNum, int &replaceNum, char &ynSel)
{
	do
	{
		// Sets default variable values
		inputNum	= 0;
		modifiedNum = 0;
		replaceNum	= 0;
		int ssTemp;
		
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
		
		// Replacing the node values
		std::cout << "Number of items replaced: " << list.replaceValue(modifiedNum, replaceNum) << std::endl;
		
		// Prints the new list
		cout << "Modified List: ";
		for (int i = 6; i >= 1; i--)
		{
			std::cout << list.getEntry(i) << " ";
		}
		
		cout << endl;
		
		// Empties the list after use.
		list.clear();
		
		// Asks the user if they would like to modify another list
		cout << "Would you like to modify another list? [y/n] ";
		cin  >> ynSel;
		cin.ignore();
		
		cout << endl;
	}
	while (ynSel == 'y' || ynSel == 'Y');
	
	

    cout << "------------------------------" << endl << endl;
}


// Compares values in 2 different linked lists
//		The user enters values into 2 linked lists, once entered, the program will output to the
//	console saying weather both lists are equal or are not equal.
//		@param Passes in 2 int linked lists, an int for value input, and a value for selecting y/n
//		@pre none
//		@post The user is given a prompt for the first linked list, and then the second linked ist, asking
//	for values to be put into their repsective lists. After values have been put into both lists, it will
//	go through both linked lists at the same time to see if they both have the same values. It will print
//	accordingly if both the lists have the same values or not.
//		It will ask the user if they would like to compare 2 lists after the program has run.
void compareLinkedListVales (LinkedList<int> &listA, LinkedList<int> &listB, int &inputNum, char &ynSel)
{

	do
	{
		// Sets default variable values
		inputNum = 0;
		
		// Prompts user to enter a list of integers
		cout << "Enter first list of 6 integers followed by the enter/return key: " << endl;
		
		// Gets input for the first linked list
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
		
		// Gets input for the 2nd linked list
		for (int i = 1; i <= 6; i++)
		{
			// Receives input of ints
			cin >> inputNum;
			cin.ignore();
			
			// Inserts value into the linked list
			listB.insert(1, inputNum);
		}
		
		// If the return value is true
		if (listA.equals(listB) == true)
		{
			cout << "The two lists are equal." << endl;
		}
		else // If the return value is false
		{
			cout << "The two lists are not equal." << endl;
		}
		
		// Empties both lists to ensure no leftover data in them.
		listA.clear();
		listB.clear();
		
		// Asks if the user would like to compare 2 more lists
		cout << "Would you like to compare two more lists? [y/n] ";
		cin  >> ynSel;
		cin.ignore();
		
		cout << endl;
		
	}
	while (ynSel == 'y' || ynSel == 'Y');

    cout << "------------------------------" << endl << endl;

}























