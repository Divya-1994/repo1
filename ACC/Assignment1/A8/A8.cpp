#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include "input.h"

using namespace std;

int max(int a, int b);
int height(struct Node *N);
Node *newNode(int key);
Node *rightRotate(struct Node *y);
Node *leftRotate(struct Node *x);
int getBalance(struct Node *N);
Node *insert(struct Node *node, int key, bool isAVL);
void preOrder(struct Node *root);
void search(Node *root, int serachKey);

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

// Driver Code
int main()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::nanoseconds elapsed_seconds;
    std::time_t end_time;
    long searchKey;
    cout << "\nTime Calculation of searching an element in UNSORTED DATA\n";
    cout << "\nBINARY SEARCH TREE" << endl;
    Node *randomBSTRroot = new Node;
    Node *randomAVLRroot = new Node;
    randomBSTRroot = NULL;
    randomAVLRroot = NULL;
    vector<int> inputVector = generateRandomNumbers();
    inputVector = checkIfDuplicateAndRoundOff(inputVector);
    // Constructing Binary search tree
    for(int i = 0; i < inputVector.size(); i++) {
       randomBSTRroot = insert(randomBSTRroot, inputVector[i], false);
    }

    cout<<"\nEnter key to be search on BST and AVL Tree\n";
    cin >> searchKey;
    start = chrono::high_resolution_clock::now();
    search(randomBSTRroot, searchKey);
    end = chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << " ns\n"
         << endl;

    cout << "Preorder traversal of the "
            "constructed Binary Search Tree tree is \n";
    preOrder(randomBSTRroot);


    for(int i = 0; i < inputVector.size(); i++) {
       randomAVLRroot = insert(randomAVLRroot, inputVector[i], false);
    }
    cout << "\n\nAVL TREE";
    start = chrono::high_resolution_clock::now();
    search(randomAVLRroot, searchKey);
    end = chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << " ns\n"
         << endl;

    cout << "Preorder traversal of the "
            "constructed AVL Tree tree is \n";
    preOrder(randomAVLRroot);

    randomBSTRroot = NULL;
    randomAVLRroot = NULL;

    std::sort(inputVector.begin(), inputVector.end());

    return 0;
}

// A utility function to get the
// height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Helper function that allocates a  
   new node with the given key and  
   NULL left and right pointers. */
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially
                      // added at leaf
    return (node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(struct Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(struct Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node *insert(Node *node, int key, bool isAvl)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key, isAvl);
    else if (key > node->key)
        node->right = insert(node->right, key, isAvl);
    else // Equal keys are not allowed in BST
        return node;

    if (isAvl)
    {
        //Update height of this ancestor node
        node->height = 1 + max(height(node->left),
                               height(node->right));

        int balance = getBalance(node);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void search(Node *root, int serachKey)
{
    int depth = 0;
    Node *temp = new Node;
    temp = root;
    while (temp != NULL)
    {
        depth++;
        if (temp->key == serachKey)
        {
            cout << "\nitem found at depth: " << depth << endl
                 << endl;
            return;
        }
        else if (temp->key > serachKey)
            temp = temp->left;
        else
            temp = temp->right;
    }
    cout << "\n item not found\n"
         << endl;
    return;
}