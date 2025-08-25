#include <iostream>
#include <stdlib.h>
#include "tree.h"
#include "diameter.h"
#include "problems.h"
#include "BST.h"
#include "bfs.h"
#include "iterativeBst.h"
#include "Inordertree.h"
#include "Algotree.h"
node * BuildNode ( int val)
{
    node * x = (node*) malloc ( sizeof (struct _node) );
    if ( !x) return nullptr;
    else {
        x->val = val; x->right = x->left = nullptr;
        return x;
    }
}

// traverse first
node * BuildLeft ( node * root, int i)
{
    //while (root->left) root = root->
    root->left = BuildNode(i);
    if (root->left)
        root->left->parent = root;
    return root;
}

// traverse first
node * BuildRight ( node * root, int i)
{
    root->right = BuildNode(i);
    if (root->right)
        root->right->parent = root;
    return root;
}

// -- Building a BST
node * BuildTreeRecursive ( node * root, int key) {
    if (root == nullptr) {
        root = (node *) malloc(sizeof(struct _node));
        root->val = key;
        root->parent = root->left = root->right = nullptr;
    } else if (root->val < key){
        root->right = BuildTreeRecursive(root->right, key);
        root->right->parent = root;
    }else {
        root->left = BuildTreeRecursive(root->left, key);
        root->left->parent = root;
    }

    return root;
}
node *  BuildTree ( node * root)
{

//    int A[] = { 5, 2, 1 , 3, 4, 8, 7, 6, 11, 72, 31, 54, 68 };
    int A[] = { 5, 2, 1 , 3, 4, 8}; //, 7, 6, 11, 72, 31, 54, 68 };

    int nb_nodes = sizeof ( A ) / sizeof (A[0]);

    root = BuildTreeRecursive(nullptr, A[0]);

    for ( int i = 1; i < nb_nodes; i++){

        node * current = root;
        BuildTreeRecursive(current , A[i]);
    }
    return root;
}

//-Inorder visit => increasing order
void visit ( node * root)
{
    if ( !root) return;
    visit (root->left);
    std::cout  << " val = " << root->val << std::endl;
    visit (root->right);
}

void print_tree ( node * root)
{
    showtree(root, 0);

}

/* PostOrder, free left, free right. free root */
void FreeTree ( node * root)
{
    if (root == nullptr) return;

    FreeTree(root->left);
    FreeTree(root->right);
    free(root);
    root = nullptr;
}
node* BuildTreeNvisit( node* root)
{
    root = BuildTree(root);
    // - visit tree
    visit(root);
    print_tree(root);
    return root;
}

void AlgosMinMax ( node* root)
{
    // -- algos
    node* max = max_node(root);
    std::cout << "max =" << max->val << std::endl;
    node* min = min_node(root);
    std::cout << "min =" << min->val << std::endl;
}

void predecessor_successor ( node* root)
{
    node *previous = predecessor(root);
    std::cout <<"predecessor of = " << root->val << " is= " << previous->val << std::endl;
    node *next = successor(root );
    std::cout << "successor of = " << root->val << " is = " << next->val << std::endl;
}

void height_diameter ( node * root)
{
    //-height
    std::cout << "height = " << height(root) << std::endl;

    //- diameter
    std::cout << "diameter- " <<tree_diameter(root) << std::endl;
}

void test_iterative()
{
     iterative_main();
}
// -- tests for the algorithms ...
int main() {
    std::cout << "Hello, Trees!" << std::endl;

    node * root = nullptr;

    std::cout << "BuildTreeNvisit()" << std::endl;
    root = BuildTreeNvisit(root);
   FreeTree(root);

    GoodNodesMain( );
    std::cout << "Hello, World!" << std::endl;
   // root = nullptr;

    //iterative
    test_iterative();
    //- IsBST
    BST_main();


    //
    root = BuildTreeNvisit(root);
    Algotree_main(root);
    return 0;

}
