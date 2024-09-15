#ifndef HOME_H
#define HOME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int value;
    int height;
} Node;

typedef struct {
    Node *root;
} AVLTree;

int max(int a, int b);
int height(Node *N);
int getBalance(Node *N);
Node* leftRotate(Node *unbalancedNode);
Node* rightRotate(Node *unbalancedNode);
Node* insertNode(int value);
void initializeTree();
void printTree(Node *next);

extern AVLTree *tree;

#endif
