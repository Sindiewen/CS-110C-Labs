//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A class of nodes for an array-based binary tree.
 Listing 16-1.
 @file TreeNode.h */

#ifndef _TREE_NODE
#define _TREE_NODE

template<class ItemType>
class TreeNode
{
   
private:
   ItemType item;        // Data portion
   TreeNode<ItemType>      *leftChild;   // Index to left child
   TreeNode<ItemType>      *rightChild;  // Index to right child

public:
    TreeNode();
    TreeNode(const ItemType& nodeItem, TreeNode<ItemType> left, TreeNode<ItemType> right);
	
	void setItem(const ItemType& anItem);
	void setLeft(TreeNode<ItemType> *LeftNextNodePtr);
	void setRight(TreeNode<ItemType> *RightNextNodePtr);
	
	ItemType getItem() const;
	ItemType getLeft() const;
	ItemType getRight() const;
	
   
   // Declarations of the methods setItem, getItem, setLeft, getLeft,
   // setRight, and getRight are here.
}; // end TreeNode

template <Typename ItemType>
TreeNode<ItemType>::TreeNode() : leftChild(nullptr), rightChild(nullptr) {
	
}

template <typename ItemType>
TreeNode<ItemType>::TreeNode(const ItemType& nodeItem, TreeNode<ItemType> left, TreeNode<ItemType> right) : item(nodeItem), leftChild(left), rightChild(right){
	
}

void setItem(const ItemType& anItem)
{
	item = anItem;
}
void setLeft(TreeNode<ItemType> *LeftNextNodePtr)
{
	leftChild = LeftNextNodePtr;
}

void setRight(TreeNode<ItemType> *RightNextNodePtr)
{
	rightChild = RightNextNodePtr;
}

ItemType getItem() const
{
	return item;
}
ItemType getLeft() const;
ItemType getRight() const;



//#include "TreeNode.cpp"

#endif 
