//
// Created by Prokash Sinha on 6/14/23.
//

#include "Inordertree.h"
// CPP program to construct binary
// tree from given array in level
// order fashion Tree Node

#include <iostream>
#include "tree.h"
using namespace std;

/* Helper function that allocates a
new node */
node* newNode(int data)
{
    node* node = (pnode) malloc(sizeof(struct _node));
    node->val = data;
    node->left = node->right = NULL;
    return (node);
}

// Function to insert nodes in level order
node* insertLevelOrder(int arr[],
                       int i, int n)
{
    node *root = nullptr;
    // Base case for recursion

    if ( arr[i] == null) return nullptr;
    if (i < n)
    {
        root = newNode(arr[i]);

        // insert left child
        root->left = insertLevelOrder(arr,
                                      2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr,
                                       2 * i + 2, n);
    }
    return root;
}

// Function to print tree nodes in
// preOrder fashion
void visitPreOrder(node* root)
{
    if (root != NULL)
    {
        cout << root->val <<" ";
        visitPreOrder(root->left);
        visitPreOrder(root->right);
    }
}

// Driver program to test above function
int InOrderTree_main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);
    pnode root = insertLevelOrder(arr, 0, n);
    visitPreOrder(root);

    return 0;
}

// This code is contributed by Chhavi and improved by Thangaraj

