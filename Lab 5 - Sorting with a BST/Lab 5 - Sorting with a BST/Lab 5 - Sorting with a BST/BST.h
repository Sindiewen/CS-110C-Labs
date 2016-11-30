/* Frank M. Carrano, Data Abstraction & Problem Solving with C++, 
Walls & Mirrors, Fifth Edition, Pearson Education, Inc., 2007,  
pp. 556-559. 
*/

/** @file BST.h */
#include <cstddef>
#include <new>
#include "TreeException.h"
#include "TreeNode.h"

typedef void (*FunctionType)(TreeItemType& anItem);

/** @class BinarySearchTree
 * ADT binary search tree.
 * Assumption: A tree contains at most one item with a given
 *             search key at any time. */
class BinarySearchTree
{
public:
// constructors and destructor:
   BinarySearchTree();
   BinarySearchTree(const BinarySearchTree& tree)
      throw(TreeException);
   virtual ~BinarySearchTree();

// binary search tree operations:
// Precondition for all methods: No two items in a binary
// search tree have the same search key.

   /** Determines whether a binary search tree is empty.
    * @return True if the tree is empty; otherwise returns
    *         false. */
   virtual bool isEmpty() const;

   /** Inserts an item into a binary search tree.
    * @pre The item to be inserted into the tree is newItem.
    * @post newItem is in its proper order in the tree.
    * @throw TreeException  If memory allocation fails. */
   virtual void searchTreeInsert(const TreeItemType& newItem)
      throw(TreeException);

   /** Deletes an item with a given search key from a binary search
    *  tree.
    * @pre searchKey is the search key of the item to be deleted.
    * @post If the item whose search key equals searchKey existed
    *       in the tree, the item is deleted. Otherwise, the tree
    *       is unchanged.
    * @throw TreeException  If searchKey is not found in the
    *        tree. */
   virtual void searchTreeDelete(KeyType searchKey)
      throw(TreeException);

   /** Retrieves an item with a given search key from a binary
    *  search tree.
    * @pre searchKey is the search key of the item to be
    *      retrieved.
    * @post If the retrieval was successful, treeItem contains the
    *       retrieved item.
    * @throw TreeException  If no such item exists. */
   virtual void searchTreeRetrieve(KeyType searchKey,
				   TreeItemType& treeItem) const
      throw(TreeException);

   /** Traverses a binary search tree in preorder, calling function
    *  visit() once for each item.
    * @pre The function represented by visit() exists outside of
    *      the class implementation.
    * @post visit's action occurred once for each item in the
    *       tree.
    * @note visit() can alter the tree. */
   virtual void preorderTraverse(FunctionType visit);

   /** Traverses a binary search tree in sorted order, calling
    *  function visit() once for each item. */
   virtual void inorderTraverse(FunctionType visit);

   /** Traverses a binary search tree in postorder, calling
    *  function visit() once for each item. */
   virtual void postorderTraverse(FunctionType visit);

// overloaded operator:
   virtual BinarySearchTree& operator=(const BinarySearchTree& rhs)
      throw(TreeException);

protected:
   /** Recursively inserts an item into a binary search tree.
    * @pre treePtr points to a binary search tree, newItem is the
    *      item to be inserted.
    * @post Same as searchTreeInsert.
    * @throw Same as searchTreeInsert. */
   void insertItem(TreeNode *& treePtr,
                   const TreeItemType& newItem)
      throw(TreeException);

   /** Recursively deletes an item from a binary search tree.
    * @pre treePtr points to a binary search tree, searchKey is the
    *      search key of the item to be deleted.
    * @post Same as searchTreeDelete.
    * @throw Same as searchTreeDelete. */
   void deleteItem(TreeNode *& treePtr, KeyType searchKey)
      throw(TreeException);

   /** Deletes the item in the root of a given tree.
    * @pre nodePtr points to the root of a binary search tree;
    *      nodePtr != NULL.
    * @post The item in the root of the given tree is deleted. */
   void deleteNodeItem(TreeNode *& nodePtr);

   /** Retrieves and deletes the leftmost descendant of a given
    *  node.
    * @pre nodePtr points to a node in a binary search tree;
    *      nodePtr != NULL.
    * @post treeItem contains the item in the leftmost descendant
    *       of the node to which nodePtr points. The leftmost
    *       descendant of nodePtr is deleted. */
   void processLeftmost(TreeNode *& nodePtr,
                        TreeItemType& treeItem);

   /** Recursively retrieves an item from a binary search tree.
    * @pre treePtr points to a binary search tree, searchKey is the
    *      search key of the item to be retrieved.
    * @post Same as searchTreeRetrieve.
    * @throw Same as searchTreeRetrieve. */
   void retrieveItem(TreeNode *treePtr, KeyType searchKey,
                     TreeItemType& treeItem) const
      throw(TreeException);

// The following 9 methods are the same as for the ADT
// binary tree, and so their specifications are abbreviated.
   void copyTree(TreeNode *treePtr, TreeNode *& newTreePtr) const
      throw(TreeException);
   void destroyTree(TreeNode *& treePtr);

   void preorder(TreeNode *treePtr, FunctionType visit);
   void inorder(TreeNode *treePtr, FunctionType visit);
   void postorder(TreeNode *treePtr, FunctionType visit);

   TreeNode *rootPtr() const;
   void setRootPtr(TreeNode *newRoot);

   void getChildPtrs(TreeNode *nodePtr,
                     TreeNode *& leftChildPtr,
                     TreeNode *& rightChildPtr) const;
   void setChildPtrs(TreeNode *nodePtr,
                     TreeNode *leftChildPtr,
                     TreeNode *rightChildPtr);

private:
   /** Pointer to root of tree. */
   TreeNode *root;
}; // end BinarySearchTree
// End of header file.





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
			throw TreeException(
								"TreeException: insertItem cannot allocate memory");
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
	{
		processLeftmost(nodePtr->rightChildPtr, replacementItem);
		nodePtr->item = replacementItem;
	}  // end if two children
}  // end deleteNodeItem

void BinarySearchTree::processLeftmost(TreeNode *& nodePtr, TreeItemType& treeItem)
{
	if (nodePtr->leftChildPtr == NULL)
	{
		treeItem = nodePtr->item;
		TreeNode *delPtr = nodePtr;
		nodePtr = nodePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL;  // defense
		delete delPtr;
	}
	
	else
	{
		processLeftmost(nodePtr->leftChildPtr, treeItem);
	}
}  // end processLeftmost

void BinarySearchTree::retrieveItem(TreeNode *treePtr, KeyType searchKey, TreeItemType& treeItem) const
throw(TreeException)
{
	if (treePtr == NULL)
		throw TreeException("TreeException: searchKey not found");
	
	else if (searchKey == treePtr->item.getKey())
	{
		// item is in the root of some subtree
		treeItem = treePtr->item;
	}
	
	else if (searchKey < treePtr->item.getKey())
	{
		// search the left subtree
		retrieveItem(treePtr->leftChildPtr, searchKey, treeItem);
	}
	
	else  // search the right subtree
	{
		retrieveItem(treePtr->rightChildPtr, searchKey, treeItem);
	}
}

