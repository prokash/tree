#include <iostream>
#include <stdlib.h>
#include <cassert>
#include "tree.h"

using namespace std;

void printtreenode( int val, int height)
{
    int i;
    for ( i = 0; i < height; i++ ) cout << "  ";

    cout << val <<endl;
}

void showtree ( node* anode, int h)
{
    if (anode == nullptr){
        return  ; //printtreenode( -1, h);
    }else{
        //post order
        showtree(anode->right, h+1);
        printtreenode(anode->val, h);
        showtree(anode->left, h+1);
    }
}

// - recursive
node * max_node ( node * root)
{
    node *max = nullptr;
    if (root == nullptr) {
        return nullptr;
    }else {
        //max = root;
        node * current = max_node ( root->right);
        (current) ? max = current : max = root;
    }
    return max;
}


// - recursive
node * min_node ( node * root)
{
    node * min = nullptr;
    if (root == nullptr) {
        return nullptr;
    }else { /* min always at left subtree */
        node * current = min_node ( root->left);
        (current) ? min = current : min = root;
    }
    return min;
}
int height ( node * root)
{
    if ( root == nullptr) return 0;
    int lh = height( root->left) + 1;
    int rh = height (root->right) + 1;

    return  lh > rh ? lh : rh;
}

int Nbleaves ( node * root)
{
    if ( root == nullptr) return 0;
    if ( root->left == nullptr && root->right == nullptr) return 1;
    return Nbleaves(root->left) + Nbleaves(root->right);
}
// -- predecessor of a node is the max of its left subtree, if left subtree exist
// -- Find the parent moving upward from the node whose right subtree has this node.
extern
node * predecessor( node * anode)
{
    assert (anode);
    if (anode->left) {
        return max_node(anode->left);
    } else {
        //-- no left child, so find the parent closet to this node whose right subtree has this node
        node * y = anode->parent;
        while ( y && y->left == anode) {
            anode = y;
            y = y->parent;
        }
        return y;
    }
}

// -- successor of a node is the min of its right subtree, if it exists.
// -- otherwise find the parent whose left subtree contains this node.
extern
node * successor ( node* anode)
{
    assert(anode);
    if ( anode->right ) {
        return min_node(anode->right);
    }else {
        // -- implement
        node *x = anode->parent;
        while (x && x->right == anode){
            anode = x;
            x = x->parent;
        }
        return x;
    }
}


// Full Binary tree:: A binary tree in which each node has exactly zero or two children. Also known as proper binary tree.
// ==> check for each node if you have either zero children or two children


// A balanced binary tree, also referred to as a height-balanced binary tree,
// is defined as a binary tree in which the height of the left and right subtree
// of any node differ by not more than 1.

void PrintTree ( node * root)
{
    if (root == nullptr) return;
    
    PrintTree(root->left);
    cout << root->val << "  ";

    PrintTree(root->right);

    //cout << endl;
}


void MirrorTree ( node * root) {
    if (root == nullptr) return;
    /*post order traversal */
    pnode temp = root->left;
    root->left = root->right;
    root->right = temp;
    MirrorTree(root->left);
    MirrorTree(root->right);
}


// Definition for a Node.
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// -- In order traversal
int bst_to_list (node * cur_node, pnode *prev, pnode *head)
{
   if (!cur_node) return 0;
   bst_to_list(cur_node->left, prev, head);
   cur_node->left = *prev;

   if (*prev)
       (*prev)->right = cur_node;
   else
       *head = cur_node;

   *prev = cur_node;
   bst_to_list(cur_node->right, prev, head);

   return 0;

}

void PrintDL ( node * h){
    if ( h == nullptr)
        return;
    while (h){
        cout << h->val << " ";
        h = h->right;
    }

}
void FreeDL( node* h){

}

// BST->Doubly linked list
// ....
void BST_to_DL ( node * root) {


    pnode prev = nullptr;
    pnode head = nullptr;
    int res = bst_to_list(root, &prev, &head);
    assert (res == 0);
    cout << "Doubly linked list:";
    PrintDL(head);
    cout << endl;
    cout << "Freeing doubly linked list" << endl;
    FreeDL(head);
}
// - Tree is build already !!
void Algotree_main(pnode root)
{
    cout << "Algotree_main()start " << endl;

    cout <<"Tree before mirroring:";
    PrintTree(root);
    cout << endl;

    height_diameter (root);

    MirrorTree(root);
    cout << "Tree after mirroring:";
    PrintTree(root);
    cout << endl;

    MirrorTree(root); //Mirror again
    cout << "Mirroring again:";
    PrintTree(root);
    cout <<endl;


    cout << "Algotree_main() ends" << endl;
}