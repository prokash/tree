//
// Created by Prokash Sinha on 6/30/23.
//
#include <iostream>
#include "diameter.h"

using namespace std;

#define MAX(A,B)  ( (A) > (B) ? (A) : (B))
// diameter of a tree is the longest path between two nodes
// in the tree
//the diameter of T’s left subtree.
//the diameter of T’s right subtree.
//the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)

int tree_diameter ( node * root)
{
    if (root == nullptr) return 0;

    int lheight = height(root->left);
    int rheight = height ( root->right);

    int ldiameter = tree_diameter(root->left);
    int rdiameter = tree_diameter(root->right);

    //- first one is when root is included
    return MAX( (lheight + rheight + 1), MAX(ldiameter, rdiameter));
}

void tree_diameter_main()
{

}