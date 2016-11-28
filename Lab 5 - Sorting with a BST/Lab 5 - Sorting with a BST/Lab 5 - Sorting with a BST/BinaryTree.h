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
	BinaryTree<ItemType>*	rightSubtreePtr;
	ItemType*				pItem;				// pointer to the root item
	bool					subTree;			// true if this is part of another object
};



/* Binary Tree Implementation */



// Default constructor
template <typename ItemType>
BinaryTree<ItemType>::BinaryTree()
{
	leftSubtreePtr = rightSubtreePtr = nullptr;
	pItem = nullptr;
	subTree = false;
}

// If the root item gets passed
template <typename ItemType>
BinaryTree<ItemType>:: BinaryTree(const ItemType& rootItem)
{
	pItem = new ItemType(rootItem);
	leftSubtreePtr = rightSubtreePtr = nullptr;
	subTree = false;
}

// If root item, and left tree and right tree has been passed in
template <typename ItemType>
BinaryTree<ItemType>::BinaryTree(const ItemType& rootItem, BinaryTree<ItemType>& leftTree, BinaryTree<ItemType>& rightTree)
{
	pItem = new ItemType(rootItem);
	leftSubtreePtr = rightSubtreePtr = nullptr;
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

// Destructor
template <typename ItemType>
BinaryTree<ItemType>::~BinaryTree()
{
	// Destroys the Binary Tree
	destroyTree();
}

// Returns if the tree is empty
template <typename ItemType>
bool BinaryTree<ItemType>::isEmpty() const
{
	return bool (pItem == nullptr);
}

// Returns the root item
template <typename ItemType>
ItemType BinaryTree<ItemType>::getRootData() const
{
	return *pItem;
}

// Sets the root data of the tree
template <typename ItemType>
void BinaryTree<ItemType>::setRootData(const ItemType& newItem)
{
	if (pItem != nullptr)
	{
		*pItem = newItem;
	}
	else
	{
		pItem = new ItemType(newItem);
		leftSubtreePtr = rightSubtreePtr = nullptr;
		subTree = false;
	}
}

// Attaches left tree
template <typename ItemType>
void BinaryTree<ItemType>::attachLeft(const ItemType& newItem)
{
	if (isEmpty())
	{
		// Cannot attach to an empty tree
		return;
	}
	else if (leftSubtreePtr != nullptr)
	{
		// leftsubtree already has a tree, cannot overwrite
		return;
	}
	else
	{
		// Tree not empty, attach left tree
		leftSubtreePtr = new BinaryTree(newItem);
	}
}

// Attaches right tree
template <typename ItemType>
void BinaryTree<ItemType>::attachRight(const ItemType& newItem)
{
	if (isEmpty())
	{
		// Tree is empty, cannot attach to an empty tree
		return;
	}
	else if (rightSubtreePtr != nullptr)
	{
		// Right subtree already has a tree, canot overwrite
		return;
	}
	else
	{
		rightSubtreePtr = new BinaryTree(newItem);
	}
}

// Attaches exsisting left subtree
template <typename ItemType>
void BinaryTree<ItemType>::attachLeftSubtree(BinaryTree<ItemType>& leftTree)
{
	if (isEmpty())
	{
		// Tree is empty, cannot attach to an empty tree
		return;
	}
	else if (leftSubtreePtr != nullptr)
	{
		// Tree exsists already, cannot attach
		return;
	}
	else
	{
		leftSubtreePtr = new BinaryTree(leftTree);
		leftTree.destroyTree();
	}
}

// Attaches exsisting right subtree
template <typename ItemType>
void BinaryTree<ItemType>::attachRightSubtree(BinaryTree<ItemType>& rightTree)
{
	if (isEmpty())
	{
		// Tree is empty, cannot attach
		return;
	}
	else if (rightSubtreePtr != nullptr)
	{
		// Tree exsists already, cannot attach
		return;
	}
	else
	{
		// Attaches right tree
		rightSubtreePtr = new BinaryTree(rightTree);
		rightTree.destroyTree();
	}
}

// Detaches the left subtree
template <typename ItemType>
void BinaryTree<ItemType>::detatchLeftSubtree(BinaryTree<ItemType>& leftTree)
{
	if (isEmpty())
	{
		// Tree empty, cannot detatch
		return;
	}
	else
	{
		// Copies the left subtree to the left tree reference
		leftTree = *leftSubtreePtr;
		
		// Null's is - like it doesnt exsist
		leftSubtreePtr = nullptr;
		subTree = false;
	}
}

// Detatches right subtree
template <typename ItemType>
void BinaryTree<ItemType>::detatchRightSubtree(BinaryTree<ItemType>& rightTree)
{
	if(isEmpty())
	{
		// Tree empty, cannot detatch
		return;
	}
	else
	{
		// Copies the right subtree to the right tree reference
		rightTree = *rightSubtreePtr;
		
		// Null's it - like it doesnt exsist
		rightSubtreePtr = nullptr;
		subTree = false;
	}
}

// Returns the left subtree value
template <typename ItemType>
BinaryTree<ItemType>& BinaryTree<ItemType>::getLeftSubtree()
{
	if (leftSubtreePtr)
	{
		// Returns value in the left subtree
		leftSubtreePtr->subtree = true;
		return *leftSubtreePtr;
	}
	else
	{
		// Creates new empty subtree to return empty value
		BinaryTree<ItemType> *emptyTree = new BinaryTree();
		return *emptyTree;
	}
}

// Returns the right subtree value
template <typename ItemType>
BinaryTree<ItemType>& BinaryTree<ItemType>::getRightSubtree()
{
	if (rightSubtreePtr)
	{
		// Returns the value in the right subtree
		rightSubtreePtr->subtree = true;
		return *rightSubtreePtr;
	}
	else
	{
		// creates new empty subtree to return empty value
		BinaryTree<ItemType> *emptyTree = new BinaryTree();
		return *emptyTree;
	}
}

// Preorder traversal
template <typename ItemType>
void BinaryTree<ItemType>::preorderTraverse(void visit(ItemType&))
{
	if (pItem != nullptr)
	{
		visit (*pItem);
		if (leftSubtreePtr)
		{
			leftSubtreePtr->preorderTraverse(visit);
		}
		if (rightSubtreePtr)
		{
			rightSubtreePtr->preorderTraverse(visit);
		}
	}
}

// Inorder traverse
template <typename ItemType>
void BinaryTree<ItemType>::inorderTraverse(void visit(ItemType&))
{
	if (pItem != nullptr)
	{
		if (leftSubtreePtr)
		{
			leftSubtreePtr->inorderTraverse(visit);
		}
		
		visit(*pItem);
		
		if (rightSubtreePtr)
		{
			rightSubtreePtr->inorderTraverse(visit);
		}
	}
}

// postorder Traverse
template <typename ItemType>
void BinaryTree<ItemType>::postorderTraverse(void visit(ItemType&))
{
	if (pItem != nullptr)
	{
		if (leftSubtreePtr)
		{
			leftSubtreePtr->postorderTraverse(visit);
		}
		if (rightSubtreePtr)
		{
			rightSubtreePtr->postorderTraverse(visit);
		}
		
		visit(*pItem);
		
	}
}

// Operator overloading '='
template <typename ItemType>
BinaryTree<ItemType>& BinaryTree<ItemType>::operator=(const BinaryTree<ItemType>& rhs)
{
	if (this != &rhs)
	{
		destroyTree();	// Deallocate the lefthand side
		copyTree(rhs);
	}
	
	return *this;
}

// Copies the tree
template <typename ItemType>
void BinaryTree<ItemType>::copyTree(const BinaryTree<ItemType>& tree)
{
	// Preorder traversal
	if(tree.pItem)
	{
		// Copies node
		ItemType Temp = *(tree.pItem);
		pItem = new ItemType(Temp);
		
		if (tree.leftSubTreePtr)
		{
			leftSubtreePtr = new BinaryTree(* (tree.leftSubTreePtr));
		}
		else
		{
			leftSubtreePtr = nullptr;
		}
		if (tree.rightSubtreePtr)
		{
			rightSubtreePtr = new BinaryTree(* (tree.rightSubtreePtr));
		}
		else
		{
			rightSubtreePtr = nullptr;
		}
	}
	else
	{
		pItem = nullptr; // copy empty tree
		leftSubtreePtr = rightSubtreePtr = nullptr;
	}
}

// Destroys the tree
template <typename ItemType>
void BinaryTree<ItemType>::destroyTree()
{
	// postorder traversal
	if (leftSubtreePtr && !leftSubtreePtr->subtree)
	{
		leftSubtreePtr->destroyTree();
		delete leftSubtreePtr;
		leftSubtreePtr = nullptr;
	}
	if (rightSubtreePtr && !rightSubtreePtr->subtree)
	{
		rightSubtreePtr->destroyTree();
		delete rightSubtreePtr;
		rightSubtreePtr = nullptr;
	}
	if (pItem && !subTree)
	{
		delete pItem;
		pItem = nullptr;
	}
}

// If the value is a subtree
template <typename ItemType>
bool BinaryTree<ItemType>:: isSubtree(const BinaryTree<ItemType>& tree) const
{
	if (!pItem || !tree.pItem)
	{
		return false;
	}
	else if (leftSubtreePtr && leftSubtreePtr == &tree)
	{
		return true;
	}
	else if (rightSubtreePtr && rightSubtreePtr == &tree)
	{
		return true;
	}
	else
	{
		if (leftSubtreePtr && leftSubtreePtr->isSubtree(tree))
		{
			return true;
		}
		if (rightSubtreePtr && rightSubtreePtr -> isSubtree(tree))
		{
			return true;
		}
		
		return false;
	}
}







#endif /* BinaryTree_h */
