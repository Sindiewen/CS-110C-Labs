/* Frank M. Carrano, Data Abstraction & Problem Solving with C++, 
Walls & Mirrors, Fifth Edition, Pearson Education, Inc., 2007,  
pp. 559-563. */

/** @file BST.cpp. */
#include <cstddef>   // definition of NULL
#include <new>       // for bad_alloc
#include "BST.h"     // header file
#include "DisplayableBST.h"
//#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree() : root(NULL)
{
}  // end default constructor

BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree)
   throw(TreeException)
{
   copyTree(tree.root, root);
}  // end copy constructor

BinarySearchTree::~BinarySearchTree()
{
   destroyTree(root);
}  // end destructor

bool BinarySearchTree::isEmpty() const
{
   return (root == NULL);
}  // end searchTreeIsEmpty

void BinarySearchTree::searchTreeInsert(const TreeItemType& newItem)
   throw(TreeException)
{
   insertItem(root, newItem);
}  // end searchTreeInsert

void BinarySearchTree::searchTreeDelete(KeyType searchKey)
   throw(TreeException)
{
   deleteItem(root, searchKey);
}  // end searchTreeDelete

void BinarySearchTree::searchTreeRetrieve(KeyType searchKey,
					  TreeItemType& treeItem) const
   throw(TreeException)
{
   // if retrieveItem throws a TreeException, it is
   // ignored here and passed on to the point in the code
   // where searchTreeRetrieve was called
   retrieveItem(root, searchKey, treeItem);
}  // end searchTreeRetrieve

void BinarySearchTree::preorderTraverse(FunctionType visit)
{
   preorder(root, visit);
}  // end preorderTraverse

void BinarySearchTree::inorderTraverse(FunctionType visit)
{
   inorder(root, visit);
}  // end inorderTraverse

void BinarySearchTree::postorderTraverse(FunctionType visit)
{
   postorder(root, visit);
}  // end postorderTraverse

void BinarySearchTree::insertItem(TreeNode *& treePtr,
				  const TreeItemType& newItem)
   throw(TreeException)
{
   if (treePtr == NULL)
   {  // position of insertion found; insert after leaf

      // create a new node
      try
      {
		  treePtr = new TreeNode(newItem, NULL, NULL);
      }
      catch (bad_alloc e)
      {
		  throw TreeException("TreeException: insertItem cannot allocate memory");
      }  // end try
   }
   // else search for the insertion position
   else if (newItem.getKey() < treePtr->item.getKey())
      // search the left subtree
      insertItem(treePtr->leftChildPtr, newItem);

   else  // search the right subtree
      insertItem(treePtr->rightChildPtr, newItem);
}  // end insertItem

void BinarySearchTree::deleteItem(TreeNode *& treePtr,
                                  KeyType searchKey)
   throw(TreeException)
// Calls: deleteNodeItem.
{
   if (treePtr == NULL)
      throw TreeException("TreeException: delete failed");  // empty tree

   else if (searchKey == treePtr->item.getKey())
      // item is in the root of some subtree
      deleteNodeItem(treePtr);  // delete the item

   // else search for the item
   else if (searchKey < treePtr->item.getKey())
      // search the left subtree
      deleteItem(treePtr->leftChildPtr, searchKey);

   else  // search the right subtree
      deleteItem(treePtr->rightChildPtr, searchKey);
}  // end deleteItem

void BinarySearchTree::deleteNodeItem(TreeNode *& nodePtr)
// Algorithm note: There are four cases to consider:
//   1. The root is a leaf.
//   2. The root has no left child.
//   3. The root has no right child.
//   4. The root has two children.
// Calls: processLeftmost.
{
   TreeNode     *delPtr;
   TreeItemType replacementItem;

   // test for a leaf
   if ( (nodePtr->leftChildPtr == NULL) &&
        (nodePtr->rightChildPtr == NULL) )
   {  delete nodePtr;
      nodePtr = NULL;
   }  // end if leaf
   // test for no left child
   else if (nodePtr->leftChildPtr == NULL)
   {  delPtr = nodePtr;
      nodePtr = nodePtr->rightChildPtr;
      delPtr->rightChildPtr = NULL;
      delete delPtr;
   }  // end if no left child

   // test for no right child
   else if (nodePtr->rightChildPtr == NULL)
   {  delPtr = nodePtr;
      nodePtr = nodePtr->leftChildPtr;
      delPtr->leftChildPtr = NULL;
      delete delPtr;
   }  // end if no right child

   // there are two children:
   // retrieve and delete the inorder successor
   else
   {  processLeftmost(nodePtr->rightChildPtr,
                      replacementItem);
      nodePtr->item = replacementItem;
   }  // end if two children
}  // end deleteNodeItem

void BinarySearchTree::processLeftmost(TreeNode *& nodePtr, TreeItemType& treeItem)
{
   if (nodePtr->leftChildPtr == NULL)
   {  treeItem = nodePtr->item;
      TreeNode *delPtr = nodePtr;
      nodePtr = nodePtr->rightChildPtr;
      delPtr->rightChildPtr = NULL;  // defense
      delete delPtr;
   }

   else
      processLeftmost(nodePtr->leftChildPtr, treeItem);
}  // end processLeftmost

void BinarySearchTree::retrieveItem(TreeNode *treePtr,
                                    KeyType searchKey,
                                    TreeItemType& treeItem) const
   throw(TreeException)
{
   if (treePtr == NULL)
      throw TreeException("TreeException: searchKey not found");

   else if (searchKey == treePtr->item.getKey())
      // item is in the root of some subtree
      treeItem = treePtr->item;

   else if (searchKey < treePtr->item.getKey())
      // search the left subtree
      retrieveItem(treePtr->leftChildPtr,
                   searchKey, treeItem);

   else  // search the right subtree
      retrieveItem(treePtr->rightChildPtr,
                          searchKey, treeItem);
}  // end retrieveItem

// Implementations of copyTree, destroyTree, preorder,
// inorder, postorder, setRootPtr, rootPtr, getChildPtrs,
// setChildPtrs, and the overloaded assignment operator are
// the same as for the ADT binary tree.

void BinarySearchTree::copyTree(TreeNode *treePtr, TreeNode *& newTreePtr) const
	throw(TreeException)
{
	// preorder traversal
	if (treePtr != NULL)
	{  // copy node
		try
		{
			newTreePtr = new TreeNode(treePtr->item, NULL, NULL);
			copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
			copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
		}
		catch (bad_alloc e)
		{
			throw TreeException("TreeException: copyTree cannot allocate memory");
		}  // `end try
	}
	else
		newTreePtr = NULL;  // copy empty tree
}

void BinarySearchTree::destroyTree(TreeNode*& treePtr)
{
	// postorder traversal
	if (treePtr != NULL)
	{
		destroyTree(treePtr->leftChildPtr);
		destroyTree(treePtr->rightChildPtr);
		delete treePtr;
		treePtr = NULL;
	}  // end if
}

void BinarySearchTree::preorder(TreeNode *treePtr, FunctionType visit)
{
	if (treePtr != nullptr)
	{
		visit(treePtr->item);
		preorder(treePtr->leftChildPtr, visit);
		preorder(treePtr->rightChildPtr, visit);
	}
}

void BinarySearchTree::inorder(TreeNode *treePtr, FunctionType visit)
{
	if (treePtr != nullptr)
	{
		inorder(treePtr->leftChildPtr, visit);
		
		visit(treePtr->item);
		
		inorder(treePtr->rightChildPtr, visit);
	}
}

void BinarySearchTree::postorder(TreeNode *treePtr, FunctionType visit)
{
	if (treePtr != nullptr)
	{
		postorder(treePtr->leftChildPtr, visit);
		postorder(treePtr->rightChildPtr, visit);
		
		visit(treePtr->item);
	}
}

TreeNode *BinarySearchTree::rootPtr() const
{
	return root;
}

void BinarySearchTree::setRootPtr(TreeNode *newRoot)
{
	root = newRoot;
}

void BinarySearchTree::getChildPtrs(TreeNode *nodePtr, TreeNode *& leftChildPtr, TreeNode *& rightChildPtr) const
{
	leftChildPtr = nodePtr->leftChildPtr;
	rightChildPtr = nodePtr->rightChildPtr;
}

void BinarySearchTree::setChildPtrs(TreeNode *nodePtr, TreeNode *leftChildPtr, TreeNode *rightChildPtr)
{
	nodePtr->leftChildPtr = leftChildPtr;
	nodePtr->rightChildPtr = rightChildPtr;
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& rhs) throw(TreeException)
{
	if (this != &rhs)
	{
		destroyTree(root);  // deallocate left-hand side
		copyTree(rhs.root, root);  // copy right-hand side
	}  // end if
	return *this;
}








	///////////////////////////////////
	// Lab 5 Function Implementation //
	///////////////////////////////////

void BinarySearchTree::printTree()
{
	printTreeInOrder(root);
}

void BinarySearchTree::printTreeInOrder(TreeNode *treePtr)
{
	// TODO: Test moving code into BST.cpp and see if that helps regarding getting the inorder traversal and printing to work properly
	// Potential ideas:
	// - Keep function call here, move implementation to BST.cpp
	// - Get rid of this class in general and move everything to BST.cpp
	
	
	if (treePtr != nullptr)
	{
		//cout << "Tree is not empty" << endl;
		printTreeInOrder(treePtr->leftChildPtr);
		//cout << treePtr->item;
		tempItem = &treePtr->item;
		cout << &tempItem << endl;
		printTreeInOrder(treePtr->rightChildPtr);
	}
	else
	{
		//cout << "Tree is empty" << endl;
		return;
	}
	
	/*
		if (root is not empty)
		{
	 Print right subtree, increasing indentation by one level
	 Print contents of root
	 Print left subtree, increasing indentation by one level
		}*/
}




// End of implementation file.
