//
//  BSTNode.h
//  Lab 5 - Sorting with a BST
//
//  Created by Rachel Vancleave on 12/1/16.
//  Copyright © 2016 Rachel Vancleave. All rights reserved.
//

#ifndef BSTNode_h
#define BSTNode_h

// Binary Search Tree Node Struct
class BstNode
{
private:
	BstNode() {};
	BstNode(std::string nodeData, BstNode *left = nullptr, BstNode *right = nullptr)
	:data(nodeData), leftPtr(left), rightPtr(right) {}

	std::string data;		// Stores node data
	
	BstNode* leftPtr;       // Stores reference to the left node
	BstNode* rightPtr;      // Stores reference to the right node
	
	friend class BinarySearchTree;
};
#endif /* BSTNode_h */
