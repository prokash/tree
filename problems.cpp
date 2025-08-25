//
// Created by Prokash Sinha on 6/13/23.
//
#include "Inordertree.h"
#include "problems.h"
#include "tree.h"

#include <stdlib.h>

node* Makenode ( int val)
{
    node* pnode = (node*) malloc ( sizeof(node));
    pnode->val = val;
    pnode->left = pnode->right = nullptr;

    return pnode;
}

node * BuildTree()
{
    //-- root always a good node
    node * root = (node*)malloc ( sizeof(node));
    root->val = 2;

    // -- it is a bad node, since 2->1 path has greater parents
    root->left = (node*) malloc ( sizeof(node));
    root->left->val = 1;
    root->left->left = root->left->right = nullptr;

    root->right = (node*)malloc ( sizeof(node));
    root->right->val = 3;
    root->right->left = root->right->right = nullptr;

    return root;
}
//Given a binary tree root, a node X in the tree is named good
// if in the path from root to X there are no nodes
// with a value greater than X.

//Return the number of good nodes in the binary tree.
///int MaxValue = -1;
int countGnodes ( node* root, int MaxValue)
{
    int count = 0;
    if ( root == nullptr){
        return 0;
    }
    if ( root->val < MaxValue) {
        //this node does not count
    }else {
        MaxValue = root->val;
        count++;
    }
    count +=  countGnodes(root->left, MaxValue);
    count +=  countGnodes(root->right, MaxValue) ;

    return count;
}

/* PostOrder, free left, free right. free root */
static
void FreeTree ( node * root)
{
    if (root == nullptr) return;
    FreeTree(root->left);
    FreeTree(root->right);
    free(root);
    root = nullptr;
}
int GoodNodesMain( )
{
    //int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };

    int arr[] = {3,1,4,3, null,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = insertLevelOrder(arr, 0, n);
    visitPreOrder(root);
    cout << endl;

    int count = 0;  //root is always good

    count = countGnodes(root, root->val);
    FreeTree(root);
    cout << "Nb of good nodes =" << count <<endl;
    return count;
}