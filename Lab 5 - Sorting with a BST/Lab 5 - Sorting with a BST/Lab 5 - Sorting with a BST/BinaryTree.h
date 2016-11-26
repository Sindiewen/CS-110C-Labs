//
//  BinaryTree.h
//  Lab 5 - Sorting with a BST
//
//  Created by Rachel Vancleave on 11/22/16.
//  Copyright © 2016 Rachel Vancleave. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <iostream>

using namespace std;

template <typename ItemType>
class BinaryTree
{
public:
	// Constructor
	BinaryTree();	// Default constructor
	BinaryTree(const ItemType& rootItem);
	BinaryTree(const ItemType& rootItem, BinaryTree<ItemType>& leftTree, BinaryTree<ItemType>& rightTree);
	
	// Copy constructor
	BinaryTree(const BinaryTree<ItemType>& tree);
	
	// Destructor
	virtual ~BinaryTree();
	
	// Determines weather the binary tree is empty or not
	virtual bool isEmpty() const;
	
	// Returns a copy of the item at the root
	virtual ItemType getRootData() const;
	
	// If the binary tree is empty, creates a new binary tree with new item at root
	virtual void setRootData(const ItemType& newItem);
	
	// Creates left child of the root
	virtual void attachLeft(const ItemType& newItem);
	
	// Creates a right child of the root
	virtual void attachRight(const ItemType& newItem);
	
	// Attaches leftTree at the left subtree of the root of the binary tree
	virtual void attachLeftSubtree(BinaryTree<ItemType>& leftTree);
	
	// Attaches rightTree as the right subtree of the root of the binary tree
	virtual void attachRightSubtree(BinaryTree<ItemType>& rightTree);
	
	// Detatches left subtree of the root and places it in leftTree
	virtual void detatchLeftSubtree(BinaryTree<ItemType>& leftTree);
	
	// Detatches right subtree of the root and places it in rightTree
	virtual void detatchRightSubtree(BinaryTree<ItemType>& rightTree);
	
	// Returns (does not detatch) the left subtree of the root
	virtual BinaryTree& getLeftSubtree();
	
	// Returns (does not detatch) the right subtree of the root
	virtual BinaryTree& getRightSubtree();
	
	// Overloaded Assignment operator
	virtual BinaryTree& operator= (const BinaryTree<ItemType>& rhs);
	
	// These three traversal functions traverse the tree in preorder/inorder/postorder and
	// call the function visit once per node as it traverses each node
	virtual void preorderTraverse	(void visit(ItemType&));
	virtual void inorderTraverse	(void visit(ItemType&));
	virtual void postorderTraverse	(void visit(ItemType&));
	
protected:
	// Copies the binary tree in its parameter to the current object
	void copyTree(const BinaryTree<ItemType>& tree);
	
	// Destroys the binary tree unless it is part of another binary tree
	void destroyTree();
	
	// Determines whether or not the parameter tree is a subtree of the binary tree
	// or a subtree of a descendant of the binary tree's root.
	bool isSubtree(const BinaryTree<ItemType>& tree) const;
	
private:
	BinaryTree<ItemType>*	leftSubtreePtr;
	BinaryTree<ItemType>*	rightSubTreePtr;
	ItemType*				pItem;				// pointer to the root item
	bool					subTree;			// true if this is part of another object
};



/* Binary Tree Implementation */



// Default constructor
template <typename ItemType>
BinaryTree<ItemType>::BinaryTree()
{
	leftSubtreePtr = rightSubTreePtr = nullptr;
	pItem = nullptr;
	subTree = false;
}

// If the root item gets passed
template <typename ItemType>
BinaryTree<ItemType>:: BinaryTree(const ItemType& rootItem)
{
	pItem = new ItemType(rootItem);
	leftSubtreePtr = rightSubTreePtr = nullptr;
	subTree = false;
}

// If root item, and left tree and right tree has been passed in
template <typename ItemType>
BinaryTree<ItemType>::BinaryTree(const ItemType& rootItem, BinaryTree<ItemType>& leftTree, BinaryTree<ItemType>& rightTree)
{
	pItem = new ItemType(rootItem);
	leftSubtreePtr = rightSubTreePtr = nullptr;
	subTree = false;

	attachLeftSubtree(leftTree);
	attachRightSubtree(rightTree);
}

// Copy constructor
template <typename ItemType>
BinaryTree<ItemType>:: BinaryTree(const BinaryTree<ItemType>& tree)
{
	copyTree(tree);
	subTree = false;
}












#endif /* BinaryTree_h */
