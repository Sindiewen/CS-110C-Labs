/*
 * @name Rachel Vancleave
 * @date 11/28/16
 * @class CS 110C
 *
 * @file main.cpp
 *
 * @Summary This program uses a binary search tree. It takes input from a file and
 * sorts the contents in alphabetical order.
 
 *		It reads the input file line by line, and stores each value in a binary
 *	search tree. Once each value has been stored inside the Binary Search Tree,
 *	the program will print each line of the BST In reversed InOrder
 *	(right node, print node, left node), printing each line ordered like a BST
 *	inside the console.
 *	
 *		After that, it will print each line of the BST InOrder to print each month
 *	alphabetically.
 *
 */

#include <iostream>
#include <fstream>
#include "BSTImplementation.h"

using namespace std;

// Opens file to read and sort from
bool OpenFile(BinarySearchTree &sortMonthsBST, int &indent);

// Main function
int main()
{
	// Objects
	BinarySearchTree sortMonthsBST;		// Creates BinarySearchTree
	
	// Variables
	bool flag = false;					// Stores flag, either true or false
	int indent = 0;
	
	// Run loop while the flag is false
	do
	{
		// Assigns flag to the return type of OpenFile()
		// Checks if it's true
		if((flag = OpenFile(sortMonthsBST, indent)))
		{
			// Exits loop, loop succeeded
			break;
		}
		
		// Input failed
		cout << "File failed to open. Please enter a valid filename with file extention" << endl << endl;
	}
	while (!flag);
	
	// If the flag is true, print the tree
	if (flag)
	{
		// Prints Tree as a tree in the console, and in order for alphabetical ordering
		cout << endl << "Printing Tree: " << endl;
		sortMonthsBST.printTreeHorizontalToConsole(indent * 0.5);
		cout << endl << "Printing Tree In Alphabetical Order: " << endl;
		sortMonthsBST.inOrderPrint();
	}
	
	// Ends program
	return 0;
}

/*	Opens file - Returns bool
 *	@Summary This function reads an input of a file, stores each line of the file inside a
 *	Binary Search Tree.
 *
 *	@param	Passing a reference BinarySearchTree, and a reference for an indent int.
 *	@pre	The reference for BinarySearchTree sortMonthsBST to insert values into the
 *	BST. indent stores how many times the file has been read. It will be primarilly be
 *	used for printing the tree in the console
 *	@post The function reads a file the user inputs. Using getline(), it stores each value 
 *	inside a temporary variable, which then stores that value into a Binary Search Tree.
 *	It will keep running untill the eof has been reached.
 *		After each read and write to the BST, it will increment the indent by 1. This will
 *	be used to count how many times to indent each value in the BST when printing to the
 *	console.
 *	Returns true if successfull, false if unsuccessful.
 */
bool OpenFile(BinarySearchTree &sortMonthsBST, int &indent)
{
	
	// Objects
	fstream fin;
	
	// Local Variables
	string inputValue;		// Stores line from file
	bool flag = false;				// Local flag, either true or false
	
	// Opens file
	cout << "Welcome to the Tree Sort program!\n";
	cout << "Enter name of a file you want sorted: ";
	cin  >> inputValue;
	
	// Opens file from entered filename
	fin.open(inputValue);
	
	// If the input does not fail, or the input value is "0"
	if (!fin.fail())
	{
		
		// Loops through each line of the file
		// read each line of the file and stores it into the BST
		while (getline(fin, inputValue))
		{
			// Stores each line into the tree
			sortMonthsBST.insertValue(inputValue);
			
			// Indents every time a line is written to the tree
			indent++;
		}
		
		// Successfully read from file
		flag = true
	}
	
	// Returns either true or false, weather the file successfully opened or not
	return flag;
}

