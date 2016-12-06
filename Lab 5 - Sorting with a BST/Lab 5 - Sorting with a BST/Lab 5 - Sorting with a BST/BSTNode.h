/*
 * @name Rachel Vancleave
 * @date 11/28/16
 * @class CS 110C
 *
 * @file BSTNode.h
 *
 * @summary This header file is the implementation of the Binary Search Tree Node.
 */

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
