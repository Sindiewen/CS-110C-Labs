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
#include <iostream>
#include "BSTNode.h"

using namespace std;

class BinarySearchTree
{
public: // Public Class Functions
	
	// Class COnstructor
	// Default
	BinarySearchTree();
	
	// Inserts a value
	void insertValue	(string data);
	
	// Searches tree for a value
	bool search			(string data);
	
	// Prints BST horizontally to the console
	void printTreeHorizontalToConsole(int indent);
	
	// Tree traversals - Printing data
	void preOrderPrint	(); // Prints Tree - PreOrder
	void inOrderPrint	(); // Prints Tree - InOrder
	void postOrderPrint	(); // Prints Tree - Post Order
	
	
protected:
	
	// Inserts data into the BST
	BstNode* Insert (BstNode *&root, const string data);
	
	// Searches the BST for a specific value
	bool SearchTree (BstNode *root, string data);
	
	// Prints data to console as a horizontal tree
	void printTreeToConsole (BstNode *root, int indent);
	
	// Traversals: Prints values in directed order
	void printDataPreOrder (BstNode *root);
	void printDataInOrder  (BstNode *root);
	void printDataPostOrder(BstNode *root);
	
	
	
private:
	// Pointer to the root node
	BstNode *rootPtr;
	
	friend class DisplayBST;
};

// BST implementation //

// BST Constructors
// Default


BinarySearchTree::BinarySearchTree() : rootPtr(nullptr)
{
	// Sets the root ptr to nullptr
}


///////////////////////
// Inserting a value //
///////////////////////

void BinarySearchTree::insertValue (string data)
{
	Insert(rootPtr, data);
}

// Inserts value into the BST
BstNode* BinarySearchTree::Insert(BstNode *&root, const string data)
{
	if (root == NULL)
	{
		root = new BstNode(data, nullptr, nullptr); //Passes data into the new node
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
bool BinarySearchTree::search(string data)
{
	return SearchTree(rootPtr, data);
}

bool BinarySearchTree::SearchTree(BstNode *root, string data)
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
		return SearchTree(root->leftPtr, data);
	}
	else
	{
		// Recursivley searches the right node
		return SearchTree(root->rightPtr, data);
	}
}

////////////////////////////////////////////////////////
// Prints binary tree to console as a horizontal tree //
////////////////////////////////////////////////////////
void BinarySearchTree::printTreeHorizontalToConsole(int indent)
{
	printTreeToConsole(rootPtr, indent);
}

void BinarySearchTree::printTreeToConsole(BstNode *root, int indent)
{
	
	if (root != nullptr)
	{
		// TODO: Use this to print the tree as a sideways tree in the console, use setw() to create indentation
		printTreeToConsole(root->rightPtr, 3 + indent);
		cout << setw(indent) << root->data << endl;
		printTreeToConsole(root->leftPtr, 3 + indent);
	}
}


////////////////////////////////////
// Prints binary tree in PreOrder //
////////////////////////////////////
void BinarySearchTree::preOrderPrint()
{
	printDataPreOrder(rootPtr);
}

void BinarySearchTree::printDataPreOrder(BstNode *root)
{
	if (root != nullptr)
	{
		cout << root->data << endl;
		printDataPreOrder(root->leftPtr);
		printDataPreOrder(root->rightPtr);
	}
	
}


/////////////////////////////////
// Prints binary tree In Order //
/////////////////////////////////
void BinarySearchTree::inOrderPrint()
{
	printDataInOrder(rootPtr);
}

void BinarySearchTree::printDataInOrder(BstNode *root)
{
	if (root != nullptr)
	{
		printDataInOrder(root->leftPtr);
		cout << root->data << endl;
		printDataInOrder(root->rightPtr);
	}
	
}


/////////////////////////////////////
// Prints binary tree in PostOrder //
/////////////////////////////////////
void BinarySearchTree::postOrderPrint()
{
	printDataPostOrder(rootPtr);
}

void BinarySearchTree::printDataPostOrder(BstNode *root)
{
	if (root != nullptr)
	{
		printDataPostOrder(root->leftPtr);
		printDataPostOrder(root->rightPtr);
		cout << root->data << endl;
	}
	
}

#endif /* BSTImplementation_hpp */
