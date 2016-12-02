#include <iostream>
#include <iomanip>
#include <fstream>
#include "BSTImplementation.h"

using namespace std;

// Function prototypes
//BstNode* Insert (BstNode *root, string data);      // Inserts data to the tree
//bool Search     (BstNode *root, string data);      // Searches the tree for new data
//void printTreeToConsole(BstNode *root, int indent);
//void printDataInOrder(BstNode *root);

int main()
{
	// Objects
	BinarySearchTree myBst;
    //BstNode *root = nullptr;    // Creates an empty tree with no data
	fstream fin;				// Creates File Input Stream Object

	// Variables
    string value;				// Stores the string from the file
	string fileInput;			// String to recieve file input
	
	// Opens file
	cout << "Welcome to the Tree Sort program!\n";
	cout << "Enter name of a file you want sorted: ";
	cin  >> fileInput;
	
	// Opens file from entered filename
	fin.open(fileInput);
	
	if (!fin.fail())
	{
		// Temporary variable to store
		//TreeItemType tempData;
		
		// Loops through each line of the file
		// read each line of the file
		while (getline(fin, value))
		{
			// Stores each line into the tree
			myBst.insertValue(value);
		}
		
		myBst.printTreeHorizontalToConsole(6);
		cout << endl << endl;
		myBst.inOrderPrint();
		
		//printTreeToConsole(root, 6);
		
		//cout << endl;
		
		//printDataInOrder(root);
	}
	else
	{
		cout << "File was unable to be opened... Closing program." << endl;
	}
	
	return 0;
}

/*
BstNode* Insert(BstNode *root, string data)
{
    if (root == nullptr)
    {
        root = GetNewNode(data);    // Passes data into the new node
    }
    else if(data <= root->data)
    {
        // Recursive call to add the value to the left subtree
        root->leftPtr = Insert(root->leftPtr, data);
    }
    else
    {
        // Recursively calls the function to add data to the right subtree
        root->rightPtr = Insert(root->rightPtr, data);
    }
    return root;
}
 

bool Search(BstNode *root, string data)
{
    if (root == nullptr)
    {
        // If no data was found
        return false;
    }
    else if (root->data == data)
    {
        // If the data was found
        return true;
    }
    else if (data <= root->data)
    {
        // Recursivley searches the left node
        return Search(root->leftPtr, data);
    }
    else
    {
        // Recursivley searches the right node
        return Search(root->rightPtr, data);
    }
}
 */
/*
void printTreeToConsole(BstNode *root, int indent)
{
	
	if (root != nullptr)
	{
		// TODO: Use this to print the tree as a sideways tree in the console, use setw() to create indentation
		printTreeToConsole(root->rightPtr, 3 + indent);
		cout << setw(indent) << root->data << endl;
		printTreeToConsole(root->leftPtr, 3 + indent);
	}
}

void printDataInOrder(BstNode *root)
{
	if (root != nullptr)
	{
		printDataInOrder(root->leftPtr);
		cout << root->data << endl;
		printDataInOrder(root->rightPtr);
	}
	
}*/
