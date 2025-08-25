//
// Created by Prokash Sinha on 6/14/23.
//

#include "bfs.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Node
{
    int  value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Queue
{
    Node *items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void enqueue (Queue * q, Node * item)
{
    if (q->rear == MAX_QUEUE_SIZE - 1)
    {
        printf ("Queue Overflow\n");
        exit (EXIT_FAILURE);
    }
    q->rear++;
    q->items[q->rear] = item;
}

Node *dequeue (Queue * q)
{
    if (q->front == q->rear)
    {
        printf ("Queue Underflow\n");
        exit (EXIT_FAILURE);
    }
    q->front++;
    return q->items[q->front];
}

int
is_empty (Queue * q)
{
    return q->front == q->rear;
}

void bfs (Node * root)
{
    Queue q;
    q.front = -1;
    q.rear = -1;

    enqueue (&q, root);

    while (!is_empty (&q))
    {
        Node *current = dequeue (&q);
        printf ("%d ", current->value);

        if (current->left != NULL)
        {
            enqueue (&q, current->left);
        }
        if (current->right != NULL)
        {
            enqueue (&q, current->right);
        }
    }
}

int bfs_main ()
{
    Node *root = (Node *) malloc (sizeof (Node));
    root->value = 1;

    Node *node1 = (Node *) malloc (sizeof (Node));
    node1->value = 2;

    Node *node2 = (Node *) malloc (sizeof (Node));
    node2->value = 3;

    Node *node3 = (Node *) malloc (sizeof (Node));
    node3->value = 4;

    Node *node4 = (Node *) malloc (sizeof (Node));
    node4->value = 5;

    Node *node5 = (Node *) malloc (sizeof (Node));
    node5->value = 6;

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = NULL;
    node3->left = NULL;
    node3->right = NULL;
    node4->left = NULL;
    node4->right = NULL;
    node5->left = NULL;
    node5->right = NULL;

    bfs (root);

    return 0;
}