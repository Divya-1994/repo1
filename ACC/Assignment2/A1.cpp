#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include "input.h"

using namespace std;

struct Node *newNode(int key);
struct Node *insert(struct Node *node, int key);
int findLevels(struct Node *node);

struct Node
{
    int key;
    Node *left;
    Node *right;
};

int main()
{
    while (true)
    {
        char ch;
        cout << "\npress N to stop otherwise press any key\n";
        cin >> ch;
        if(ch == 'N') {
            break;
        }
        int n;
        cout << "\nEnter value of n\n";
        cin >> n;
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        std::chrono::nanoseconds elapsed_seconds;
        std::time_t end_time;
        Node *randomBSTRroot = new Node;
        randomBSTRroot = NULL;
        vector<int> inputVector = generateRandomNumbers(n);
        inputVector = checkIfDuplicateAndRoundOff(inputVector);
        // Constructing Binary search tree
        for (int i = 0; i < inputVector.size(); i++)
        {
            randomBSTRroot = insert(randomBSTRroot, inputVector[i]);
        }

        cout << "\nBST constructed, Now level calulation started\n";
        start = chrono::high_resolution_clock::now();
        int levels = findLevels(randomBSTRroot);
        cout << "\nTotal Number of levels : " << levels << endl;
        end = chrono::high_resolution_clock::now();
        end_time = std::chrono::high_resolution_clock::to_time_t(end);
        elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        cout << "finished computation at " << std::ctime(&end_time)
             << "elapsed time: " << elapsed_seconds.count() << " ns\n"
             << endl;
    }
    return 0;
}

struct Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

struct Node *insert(struct Node *node, int key)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    return node;
}

int findLevels(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return max(findLevels(node->left), findLevels(node->right)) + 1;
}