//
//  Node.h
//  Lab 5 - Sorting with a BST
//
//  Created by Rachel Vancleave on 11/28/16.
//  Copyright © 2016 Rachel Vancleave. All rights reserved.
//

#ifndef Node_h
#define Node_h

template <class T>
struct Node {
	T value;
	Node *left;
	Node *right;
	
	Node(T val) {
		this->value = val;
	}
	
	Node(T val, Node<T> left, Node<T> right) {
		this->value = val;
		this->left = left;
		this->right = right;
	}
};

#endif /* Node_h */
