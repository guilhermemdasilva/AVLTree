#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    struct Node *right;
    struct Node *left;
    int value;
    int height;
} Node;

typedef struct {
    Node *root;
} AVLTree;

AVLTree *tree = NULL;

int max(int a, int b) {
    return (a > b)? a : b;
}

int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* leftRotate(Node* unbalancedNode) {
    Node* rightChild = unbalancedNode->right;
    Node* temp = rightChild->left;

    rightChild->left = unbalancedNode;
    unbalancedNode->right = temp;

    unbalancedNode->height = max(height(unbalancedNode->left), height(unbalancedNode->right)) + 1;
    rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;

    return rightChild;
}

Node* rightRotate(Node* unbalancedNode) {
    Node* leftChild = unbalancedNode->left;
    Node* temp = leftChild->right;

    leftChild->right = unbalancedNode;
    unbalancedNode->left = temp;

    unbalancedNode->height = max(height(unbalancedNode->left), height(unbalancedNode->right)) + 1;
    leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;

    return leftChild;
}

void printTree(Node *next) {
    if(next != NULL) {
        printTree(next->left);
        printf("%d ", next->value);
        printTree(next->right);
    }
}

// TODO: Update insert to utilize rotate functions.
void insertNode(int value) {
    Node *aux = tree->root;
    Node *new = NULL;
    new = (Node*)malloc(sizeof(Node));
    new->right = NULL;
    new->left = NULL;
    new->value = value;
    if (aux == NULL) {
        tree->root = new;
        return;
    }
    while(1) {
        if(aux->value > value) {
            if(aux->left != NULL) {
                aux = aux->left;
            } else {
                aux->left = new;
                break;
            }
        } else {
            if(aux->right != NULL) {
                aux = aux->right;
            } else {
                aux->right = new;
                break;
            }
        }
    }
}

void initializeTree() {
    int i, r;
    tree = (AVLTree*)malloc(sizeof(AVLTree));
    tree->root = NULL;
    srand(time(NULL));
    for(i = 0; i < 10; i++) {
        r = rand() % 50;
        insertNode(r);
    }
}

main() {
    initializeTree();
    printTree(tree->root);
    printf("\n");
}