//
//  DisplayableBST.h
//  Lab 5 - Sorting with a BST
//
//  Created by Rachel Vancleave on 11/30/16.
//  Copyright © 2016 Rachel Vancleave. All rights reserved.
//

#ifndef DisplayableBST_h
#define DisplayableBST_h
#include <fstream>

template <typename ItemType>
class displayBST : BinarySearchTree
{
private:

	// Stores the value to print to console
	//ItemType	itemToPrint;	// stores the item to print to the console
	//TreeItemType tempItem;
	
	// File IO operations
	ifstream	fin;			// File in
	
	
	
public:

	// Reads from a file
	bool readFile(BinarySearchTree& bst, string fileName)
	{
		
		// Opens file from passed filename
		fin.open(fileName);
		
		
		if (!fin.fail())
		{
			// Temporary variable to store
			ItemType tempData;
			
			// Loops through each line of the file
			// read each line of the file
			while (getline(fin, tempData))
			{
				// Stores each line into the tree
				bst.searchTreeInsert(tempData);
			}
		}
		// Returns if reading the file failed or not
		return fin.fail();
	}
	
	void PrintTree(BinarySearchTree& bst)
	{
		printTreeInOrder(bst, root);
	}
	
	void printTreeInOrder(BinarySearchTree& bst, TreeNode *& treePtr)
	{
		// TODO: Test moving code into BST.cpp and see if that helps regarding getting the inorder traversal and printing to work properly
		// Potential ideas:
		// - Keep function call here, move implementation to BST.cpp
		// - Get rid of this class in general and move everything to BST.cpp
		
		
		if (!bst.isEmpty())
		{
			cout << "Tree is not empty" << endl;
			//printTreeInOrder(bst, treePtr->leftChildPtr);
			//cout << treePtr->item << endl;
			//printTreeInOrder(bst, treePtr->rightChildPtr);
		}
		else
		{
			cout << "Tree is empty" << endl;
			return;
		}
		
		
//		if (root is not empty)
//		{
//			Print right subtree, increasing indentation by one level
//			Print contents of root
//			Print left subtree, increasing indentation by one level
//		}
	}
	
	void sortTree()
	{
		
	}
};

#endif /* DisplayableBST_h */
