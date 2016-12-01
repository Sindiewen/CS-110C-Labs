/*#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
private:
	struct tree_node
	{
		tree_node* left;
		tree_node* right;
		int data;
	};
	tree_node* root;
	
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	
	bool isEmpty() const { return root==NULL; }
	void print_inorder();
	void inorder(tree_node*);
	void print_preorder();
	void preorder(tree_node*);
	void print_postorder();
	void postorder(tree_node*);
	void insert(int);
	void remove(int);
};

// Smaller elements go left
// larger elements go right
void BinarySearchTree::insert(int d)
{
	tree_node* t = new tree_node;
	tree_node* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	
	// is this a new tree?
	if(isEmpty()) root = t;
	else
	{
		//Note: ALL insertions are as leaf nodes
		tree_node* curr;
		curr = root;
		// Find the Node's parent
		while(curr)
		{
			parent = curr;
			if(t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}
		
		if(t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
	}
}

void BinarySearchTree::remove(int d)
{
	//Locate the element
	bool found = false;
	if(isEmpty())
	{
		cout<<" This Tree is empty! "<<endl;
		return;
	}
	
	tree_node* curr;
	tree_node* parent;
	curr = root;
	
	while(curr != NULL)
	{
		if(curr->data == d)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if(d>curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
	if(!found)
	{
		cout<<" Data not found! "<<endl;
		return;
	}
	
	
	// 3 cases :
	// 1. We're removing a leaf node
	// 2. We're removing a node with a single child
	// 3. we're removing a node with 2 children
	
	// Node with single child
	if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
													  && curr->right == NULL))
	{
		if(curr->left == NULL && curr->right != NULL)
		{
			if(parent->left == curr)
			{
				parent->left = curr->right;
				delete curr;
			}
			else
			{
				parent->right = curr->right;
				delete curr;
			}
		}
		else // left child present, no right child
		{
			if(parent->left == curr)
			{
				parent->left = curr->left;
				delete curr;
			}
			else
			{
				parent->right = curr->left;
				delete curr;
			}
		}
		return;
	}
	
	//We're looking at a leaf node
	if( curr->left == NULL && curr->right == NULL)
	{
		if(parent->left == curr) parent->left = NULL;
		else parent->right = NULL;
		delete curr;
		return;
	}
	
	
	//Node with 2 children
	// replace node with smallest value in right subtree
	if (curr->left != NULL && curr->right != NULL)
	{
		tree_node* chkr;
		chkr = curr->right;
		if((chkr->left == NULL) && (chkr->right == NULL))
		{
			curr = chkr;
			delete chkr;
			curr->right = NULL;
		}
		else // right child has children
		{
			//if the node's right child has a left child
			// Move all the way down left to locate smallest element
			
			if((curr->right)->left != NULL)
			{
				tree_node* lcurr;
				tree_node* lcurrp;
				lcurrp = curr->right;
				lcurr = (curr->right)->left;
				while(lcurr->left != NULL)
				{
					lcurrp = lcurr;
					lcurr = lcurr->left;
				}
				curr->data = lcurr->data;
				delete lcurr;
				lcurrp->left = NULL;
			}
			else
			{
				tree_node* tmp;
				tmp = curr->right;
				curr->data = tmp->data;
				curr->right = tmp->right;
				delete tmp;
			}
			
		}
		return;
	}
	
}

void BinarySearchTree::print_inorder()
{
	inorder(root);
}

void BinarySearchTree::inorder(tree_node* p)
{
	if(p != NULL)
	{
		if(p->left) inorder(p->left);
		cout<<" "<<p->data<<" ";
		if(p->right) inorder(p->right);
	}
	else return;
}

void BinarySearchTree::print_preorder()
{
	preorder(root);
}

void BinarySearchTree::preorder(tree_node* p)
{
	if(p != NULL)
	{
		cout<<" "<<p->data<<" ";
		if(p->left) preorder(p->left);
		if(p->right) preorder(p->right);
	}
	else return;
}

void BinarySearchTree::print_postorder()
{
	postorder(root);
}

void BinarySearchTree::postorder(tree_node* p)
{
	if(p != NULL)
	{
		if(p->left) postorder(p->left);
		if(p->right) postorder(p->right);
		cout<<" "<<p->data<<" ";
	}
	else return;
}

int main()
{
	BinarySearchTree b;
	int ch,tmp,tmp1;
	while(1)
	{
		cout<<endl<<endl;
		cout<<" Binary Search Tree Operations "<<endl;
		cout<<" ----------------------------- "<<endl;
		cout<<" 1. Insertion/Creation "<<endl;
		cout<<" 2. In-Order Traversal "<<endl;
		cout<<" 3. Pre-Order Traversal "<<endl;
		cout<<" 4. Post-Order Traversal "<<endl;
		cout<<" 5. Removal "<<endl;
		cout<<" 6. Exit "<<endl;
		cout<<" Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 : cout<<" Enter Number to be inserted : ";
				cin>>tmp;
				b.insert(tmp);
				break;
			case 2 : cout<<endl;
				cout<<" In-Order Traversal "<<endl;
				cout<<" -------------------"<<endl;
				b.print_inorder();
				break;
			case 3 : cout<<endl;
				cout<<" Pre-Order Traversal "<<endl;
				cout<<" -------------------"<<endl;
				b.print_preorder();
				break;
			case 4 : cout<<endl;
				cout<<" Post-Order Traversal "<<endl;
				cout<<" --------------------"<<endl;
				b.print_postorder();
				break;
			case 5 : cout<<" Enter data to be deleted : ";
				cin>>tmp1;
				b.remove(tmp1);
				break;
			case 6 :
				return 0;
				
		}
	}
}*/

/* Deleting a node from Binary search tree */
#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
//Function to find minimum in a tree.
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

// Function to search a delete a value from tree.
struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

//Function to visit nodes in Inorder
void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else
		root->right = Insert(root->right,data);
	return root;
}

int main() {
	/*Code To Test the logic
	 Creating an example tree
	 5
	 / \
	 3   10
	 / \   \
	 1   4   11
	 */
	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4);
	root = Insert(root,1); root = Insert(root,11);
	
	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,5);
	
	//Print Nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
}
