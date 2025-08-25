//
// Created by Prokash Sinha on 6/23/23.
//
#include "BST.h"

#include <iostream>
#include <climits>
using namespace std;

// Data structure to store a BST node
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;

    Node() {}
    Node(int data): data(data) {}
};

// Function to perform inorder traversal on the tree
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return new Node(key);
    }
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }else {
    // if the given key is more than the root node, recur for the right subtree
        root->right = insert(root->right, key);
    }
    return root;
}

// -- https://afteracademy.com/blog/check-if-a-binary-tree-is-BST-or-not/
// It does not check  SubTree(root->left) <= root->value <= SubTree(root->right)
bool wrong_isBST(Node* root) {
    bool bst = true;
    if (root == nullptr) {
        return bst;
    }
    if (root->left)
        if (root->left->data < root->data)
            bst = wrong_isBST(root->left);

    if (!bst) return false;
    if (root->right)
        if (root->data < root->right->data)
            bst = wrong_isBST(root->left);

    return bst;
}

    // -- need two ( i.e bst and helper )
    //
    //

    bool bsthelper ( Node* root, int minrange, int maxrange)
    {
        if ( root == nullptr) return true;

        if (root->data < minrange  || root->data > maxrange)
            return false;

        // max value has to be less than root->value
        // min value has to be greater than root->value
        return  (bsthelper(root->left, minrange, root->data-1) )
        & (bsthelper(root->right, root->data + 1, maxrange) ) ;

    }


    bool isBST ( Node* root)
    {
        int min = INT_MIN;
        int max = INT_MAX;

        return bsthelper( root, min, max);
    }

    /*
     * We know that an inorder traversal of a binary search tree returns the nodes in sorted order.
     * The idea is to perform inorder traversal on a given binary tree and keep track of the
     * last visited node while traversing the tree. Check whether its key is
     * smaller compared to the current key or not and mark the nodes where this property is violated
     * and later swap them.
     */

// Recursive function to fix a binary tree that is only one swap
// away from becoming a BST. Here, `prev` is the previously processed node
// in inorder traversal, and `x` & `y` stores node to be swapped (if any).
void correctBST(Node* root, Node* &x, Node* &y, Node* &prev)
{
    // base case
    if (root == nullptr) {
        return;
    }

    // recur for the left subtree
    correctBST(root->left, x, y, prev);

    // if the current node is less than the previous node
    if (root->data < prev->data)
    {
        // if this is the first occurrence, update `x` and `y` to the previous
        // and current node, respectively
        if (x == nullptr) {
            x = prev;
        }

        // if this is a second occurrence, update `y` to the current node
        y = root;
    }

    // update the previous node and recur for the right subtree
    prev = root;
    correctBST(root->right, x, y, prev);
}

// Fix given binary tree that is only one swap away from becoming a BST
void correctBST(Node* root)
{
    // `x` and `y` stores node to be swapped
    Node *x = nullptr, *y = nullptr;

    // stores previously processed node in the inorder traversal
    // initialize it by -INFINITY
    Node* prev = new Node(INT_MIN);

    // fix the binary tree
    correctBST(root, x, y, prev);

    // swap the nodes
    if (x && y) {
        swap(x->data, y->data);
    }
}

int BST_main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

    /* Construct the following tree
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    */

    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }

    // Check if it is BST
    bool bst = isBST(root);
    inorder(root);
    cout << "is it BST "<< bst <<endl;
    // swap any two nodes' values  -- MAKE IT NON-BST
    swap(root->left->data, root->right->right->data);

    bst = isBST(root);
    inorder(root);
    cout << "is it BST "<< bst <<endl;

    // fix the BST
    correctBST(root);

    // print the BST after fixing it
    inorder(root);

    return 0;
}

