//
// Created by Prokash Sinha on 6/9/23.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H
typedef struct _node {
    int val;
    struct _node * parent;
    struct _node * left;
    struct _node * right;
}node, *pnode;


extern node * max_node ( node * root);
extern node * min_node ( node * root);
extern int height ( node * root);
int Nbleaves ( node * root);
extern node * successor ( node* anode);
extern node * predecessor( node * anode);
extern void printtreenode( int val, int height);
extern void showtree ( node* anode, int h);
void height_diameter ( node * root);
//extern void FreeTree(Node* root);
#endif //TREE_TREE_H
