// Assessment 3...
/*Construct a binary search tree, and perform the following operations... 
a. Inserting an element...
b. Search for an element...
c. Traversal...*/
#include <iostream>
using namespace std;
class Node              // Node class for defining Node attributes
{
    public:        // Data members
        int data;
        Node* left;
        Node* right;
        Node(int val)     // Parametrized Constructor
        {
            data = val;
            left = NULL; right = NULL;
        }
};
class BinaryTree       // BinaryTree class for Implementation of Binary Search Tree
{
    public:
        Node* root;     // Specifying root Node
        BinaryTree()
        {
            root = NULL;
        }
    public:
        Node* InsertNodeInTree(Node* root, int value)    // Inserting nodes O(log n) time...
        {
            if(root == NULL)
                return new Node(value);    // Done by recursion
            if(value <= root -> data)    // If value is lesser, then move to the Left Subtree
                root -> left = InsertNodeInTree(root -> left, value);
            if(value > root -> data)     // If value is larger, then move to the Right Subtree
                root -> right = InsertNodeInTree(root -> right, value);
            return root;
        }
        Node* SearchNode(Node* root, int value)     // Searching Node in the Tree O(log n) time...
        {
            if(root -> data == value)    // If Node found
            {
                cout << "Search Successfull !!" << endl;
                return root;
            }
            if(root == NULL)    // If Traversed to the Leaf Node without finding the value
            {
                cout << "Search Unsuccessfull !!" << endl;
                return root;
            }
            if(value < root -> data)   // If value is less than the current Root, move to Left Subtree
            {
                if(root -> left != NULL)    // If Left Subtree exists
                    root -> left = SearchNode(root -> left, value);
                else     // Otherwise
                {
                    cout << "Search Unsuccessfull !!" << endl;
                    return root;
                }
            }
            if(value > root -> data)   // If value is more than the current Root, move to Right Subtree
            {
                if(root -> right != NULL)    // If Right Subtree exists
                    root -> right = SearchNode(root -> right, value);
                else     // Otherwise
                {
                    cout << "Search Unsuccessfull !!" << endl;
                    return root;
                }
            }
            return root;
        }
        void PrintTree(Node* root)    // Printing Nodes of the Tree O(n) time...
        {
            if(root == NULL)
                return;
            PrintTree(root -> left);     // Traversing through Left first
            cout << "Node : " << endl;
            if(root -> left != NULL)
                cout << "\t" << root -> data << " ---> " << root -> left -> data << "\t Left (Occupied)" << endl;
            else
                cout << "\t" << root -> data << "\t\t Left (Empty)" << endl;
            if(root -> right != NULL)
                cout << "\t" << root -> data << " ---> " << root -> right -> data << "\t Left (Occupied)" << endl;
            else
                cout << "\t" << root -> data << "\t\t Left (Empty)" << endl;
            PrintTree(root -> right);    // Traversing through Right later
        }
        void InOrder(Node* root)    // InOrder Traversal
        {
            if(root == NULL)
                return;
            InOrder(root -> left);           // Left Subtree
            cout << root -> data << ", ";    // Root Node
            InOrder(root -> right);          // Right Subtree
        }
};
int main()
{
    int s, x;
    BinaryTree binarytree;      // Object creation
    Node* root = NULL;
    cout << "Enter the number of Nodes to add in the Binary Search Tree : ";
    cin >> s;
    for(int i = 0; i < s; i++)    // Loop for Operations
    {
        cout << "Enter the value of the Node : ";
        cin >> x;
        root = binarytree.InsertNodeInTree(root, x);
    }
    binarytree.PrintTree(root);     // Printing the Binary Search Tree 
    cout << "Enter the element value to be searched : ";
    cin >> x;
    binarytree.SearchNode(root, x);     // Searching a Node
    cout << "The InOrder Traversal of the Created Binary Search Tree is : " << endl;
    binarytree.InOrder(root);       // Calling function for InOrder Traversal
    return 0;
}