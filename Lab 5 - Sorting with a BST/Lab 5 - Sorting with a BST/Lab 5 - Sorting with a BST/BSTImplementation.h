//
//  BSTImplementation.hpp
//  Lab 5 - Sorting with a BST
//
//  Created by Rachel Vancleave on 12/1/16.
//  Copyright © 2016 Rachel Vancleave. All rights reserved.
//

#ifndef BSTImplementation_hpp
#define BSTImplementation_hpp

#include <stdio.h>
#include "BSTNode.h"

template <typename ItemType>
class BinarySearchTree
{
public: // Public Class Functions
	
	// Class COnstructor
	// Default
	BinarySearchTree();
	
	// Inserts a value
	void insertValue (ItemType data);
	
	
protected:
	
	// Inserts data into the BST
	BstNode* Insert (BstNode *root ,ItemType data);
	
	// Searches the BST for a specific value
	bool Search (BstNode *root, ItemType data);
	
	// Traversals: Prints values in directed order
	void printPreOrder (BstNode *root, ItemType data);
	void printInOrder  (BstNode *root, ItemType data);
	void printPostOrder(BstNode *root, ItemType data);
	
	// Prints data to console as a horizontal tree
	void printTreeToConsole (BstNode *root, ItemType data);
	
private:
	// Pointer to the root node
	BstNode *rootPtr;
};

// BST implementation //

// BST Constructors
// Default

template <typename ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
	// Sets the root ptr to nullptr
}


///////////////////////
// Inserting a value //
///////////////////////

template <typename ItemType>
void BinarySearchTree<ItemType>::insertValue (ItemType data)
{
	Insert(rootPtr, data);
}

// Inserts value into the BST
template <typename ItemType>
BstNode* BinarySearchTree<ItemType>::Insert(BstNode *root ,ItemType data)
{
	if (root == nullptr)
	{
		root = GetNewNode(data);    // Passes data into the new node
	}
	else if(data <= root->data)
	{
		// Recursive call to add the value to the left subtree
		root->leftPtr = Insert(root->leftPtr, data);
	}
	else
	{
		// Recursively calls the function to add data to the right subtree
		root->rightPtr = Insert(root->rightPtr, data);
	}
	return root;
}


//////////////////////////
// Searches Binary Tree //
//////////////////////////
template <typename ItemType>
bool BinarySearchTree<ItemType>::Search(BstNode *root, ItemType data)
{
	if (root == nullptr)
	{
		// If no data was found
		return false;
	}
	else if (root->data == data)
	{
		// If the data was found
		return true;
	}
	else if (data <= root->data)
	{
		// Recursivley searches the left node
		return Search(root->leftPtr, data);
	}
	else
	{
		// Recursivley searches the right node
		return Search(root->rightPtr, data);
	}
}

#endif /* BSTImplementation_hpp */
