//
//  main.cpp
//  Lab 5 - Sorting with a BST
//
//  Created by Rachel Vancleave on 11/21/16.
//  Copyright © 2016 Rachel Vancleave. All rights reserved.
//

// NOTE: When building and compiling the program, use either g++ or clang++.
// I've had linker issues using primarily clang as is.
/*
#include <iostream>

#include "BST.cpp"

using namespace std;

int main()
{
	// Class Objects
	BinarySearchTree myStringBST;	// Creates new Binary Search Tree
	displayBST<string> printBST;	// Creates Object to interact with the BST
	ifstream fin;
	
	string tempItem;
	
	
	
	
	// String to recieve file input
	string fileInput;

	
	// Opens file
	cout << "Welcome to the Tree Sort program!\n";
	cout << "Enter name of a file you want sorted: ";
	cin  >> fileInput;
	
	// Checks if file is successfully read
	// If it fails, close program
	// Opens file from passed filename
	fin.open(fileInput);
	
	
	if (!fin.fail())
	{
		// Temporary variable to store
		//TreeItemType tempData;
		
		// Loops through each line of the file
		// read each line of the file
		while (getline(fin, tempItem))
		{
			// Stores each line into the tree
			myStringBST.searchTreeInsert(tempItem);
		}
	}
	// Returns if reading the file failed or not
	//return fin.fail();


/*
	if (!myStringBST.readFile(myStringBST, fileInput))
	{
		// Failed
		cout << "FIle faled to open, Closing program..." << endl;
		
		// Closes program
		return 0;
	}
 */
	
	// will prints the binary search tree
	//printBST.printTree(myStringBST);
//	myStringBST.printTree();

	
	
	
	
//    return 0;
//}
