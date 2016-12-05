#include <iostream>
#include <iomanip>
#include <fstream>
#include "BSTImplementation.h"

using namespace std;

// Opens file to read and sort from
bool OpenFile(BinarySearchTree &sortMonthsBST);

int main()
{
	// Objects
	BinarySearchTree sortMonthsBST;		// Creates BinarySearchTree
	
	// Variables
	bool flag = false;					// Stores flag, either true or false
	
	// Run loop while the flag is false
	do
	{
		// Assigns flag to the return type of OpenFile()
		// Checks if it's true
		if((flag = OpenFile(sortMonthsBST)))
		{
			// Exits loop, loop succeeded
			break;
		}
		
		// Input failed
		cout << "File failed to open. Please enter a valid filename with file extention" << endl;
	}
	while (!flag);
	
	// Prints Tree as a tree in the console, and in order for alphabetical ordering
	cout << endl << "Printing Tree: " << endl;;
	sortMonthsBST.printTreeHorizontalToConsole(6);
	cout << endl << "Printing Tree In Alphabetical Order: " << endl;
	sortMonthsBST.inOrderPrint();

	// Ends program
	return 0;
}


bool OpenFile(BinarySearchTree &sortMonthsBST)
{
	
	// Objects
	fstream fin;
	
	// Local Variables
	string inputValue;		// Stores line from file
	
	// Opens file
	cout << "Welcome to the Tree Sort program!\n";
	cout << "Enter name of a file you want sorted or type 0 to exit: ";
	cin  >> inputValue;
	
	// Opens file from entered filename
	fin.open(inputValue);
	
	// If the input does not fail, or the input value is "0"
	if (!fin.fail() || inputValue == "0")
	{
		
		// Loops through each line of the file
		// read each line of the file and stores it into the BST
		while (getline(fin, inputValue))
		{
			// Stores each line into the tree
			sortMonthsBST.insertValue(inputValue);
		}
		
	}
	
	// Returns either true or false, weather the file successfully opened or not
	return fin.fail();
}

