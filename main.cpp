#include <iostream>
#include <stdlib.h>


typedef struct _node {
    int val;
    struct _node * parent;
    struct _node * left;
    struct _node * right;
}node;

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

    int A[] = { 5, 2, 1 , 3, 4, 8, 7, 6, 11, 72, 31, 54, 68 };
    int nb_nodes = sizeof ( A ) / sizeof (A[0]);

    root = BuildTreeRecursive(nullptr, A[0]);

    for ( int i = 1; i < nb_nodes; i++){

        node * current = root;
        BuildTreeRecursive(current , A[i]);
    }
    return root;
}

void visit ( node * root)
{
    if ( !root) return;
    visit (root->left);
    std::cout  << " val = " << root->val << std::endl;
    visit (root->right);
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
    }else {
        node * current = min_node ( root->left);
        (current) ? min = current : min = root;
    }
    return min;
}

int height ( node * root)
{
    if ( root == nullptr) return 0;
    int lh = height( root->left) + 1;
    int rh = height (root->left) + 1;

    return  lh > rh ? lh : rh;
}
// -- predecessor of a node is the max of its left subtree

node * predecessor( node * anode)
{
    assert (anode);
    return max_node(anode->left);
}
// -- successor of a node is the min of its right subtree
node * successor ( node* anode)
{
    assert(anode);
    return min_node(anode->right);
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    node *root = BuildTree(root);
    // - visit tree
    visit(root);
    node* max = max_node(root);
    std::cout << "max =" << max->val << std::endl;
    node* min = min_node(root);
    std::cout << "min =" << min->val << std::endl;

    node *previous = predecessor(root);
    std::cout <<"predecessor of = " << root->val << " is= " << previous->val << std::endl;

    node *next = successor(root );
    std::cout << "successor of = " << root->val << " is = " << next->val << std::endl;

    //-height
    std::cout << "height = " << height(root) << std::endl;

    return 0;

}
