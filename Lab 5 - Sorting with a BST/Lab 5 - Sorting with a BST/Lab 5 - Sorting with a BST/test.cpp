#include <iostream>
#include "BSTImplementation.h"

using namespace std;

// Function prototypes
BstNode* Insert (BstNode *root, int data);      // Inserts data to the tree
bool Search     (BstNode *root, int data);      // Searches the tree for new data

int main()
{
    BstNode *root = nullptr;    // Creates an empty tree with no data

    int number;

    // Adding new values to the tree
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    cout << "Enter a number to be searched: ";
    cin  >> number;

    if (Search(root, number))
    {
        cout << "Value found." << endl;
    }
    else
    {
        cout << "Value Not Found." << endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

BstNode* Insert(BstNode *root, int data)
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

bool Search(BstNode *root, int data)
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
