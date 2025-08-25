//
// Created by Prokash Sinha on 6/14/23.
//
#include "tree.h"
#ifndef TREE_INORDERTREE_H
#define TREE_INORDERTREE_H
/* A binary tree node has data,
pointer to left child and a
pointer to right child */
struct Node {
    int data;
    Node* left, * right;
};

static int null = -1;
extern
node* insertLevelOrder(int arr[], int i, int n);
void visitPreOrder(node* root);

#endif //TREE_INORDERTREE_H
