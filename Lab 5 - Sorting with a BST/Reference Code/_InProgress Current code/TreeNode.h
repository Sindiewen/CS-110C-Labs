/* Frank M. Carrano, Data Abstraction & Problem Solving with C++, 
Walls & Mirrors, Fifth Edition, Pearson Education, Inc., 2007,  
pp. 555-556. 
*/

/** @file TreeNode.h */

#include "KeyedItem.h"

typedef KeyedItem TreeItemType;

/** @class TreeNode
 * Node used in the ADT binary search tree. */
class TreeNode
{
private:
   TreeNode() {}
   TreeNode(const TreeItemType& nodeItem, TreeNode *left = NULL, TreeNode *right = NULL) : item(nodeItem),leftChildPtr(left), rightChildPtr(right) {}

   /** A data item in the tree. */
   TreeItemType item;
   /** Pointers to children. */
	TreeNode *leftChildPtr;
	TreeNode *rightChildPtr;

   // friend class - can access private parts
	friend class BinarySearchTree;
}; // end TreeNode
