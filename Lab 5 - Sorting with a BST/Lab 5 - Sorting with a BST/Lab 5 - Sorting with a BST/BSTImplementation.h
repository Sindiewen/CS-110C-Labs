//
// Created by rachie on 11/8/16.
//

#ifndef BST_IMPLEMENTATION_MYCODESCHOOL_BSTIMPLEMENTATION_H
#define BST_IMPLEMENTATION_MYCODESCHOOL_BSTIMPLEMENTATION_H

// Binary Search Tree Node Struct
struct BstNode
{
    int data;               // Stores node data

    BstNode* leftPtr;       // Stores reference to the left node
    BstNode* rightPtr;      // Stores reference to the right node
};

// Creates a new node for the binary tree
BstNode* GetNewNode(int data)
{
    // Creates a new node for the tree
    BstNode *newNode = new BstNode();

    newNode->data       = data;             // Adds data to the Node
    newNode->leftPtr    = nullptr;          // Ensures the left pointer is pointing at nothing
    newNode->rightPtr   = nullptr;          // Ensures the right pointer is pointing to nothing
}

#endif //BST_IMPLEMENTATION_MYCODESCHOOL_BSTIMPLEMENTATION_H
