#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    struct Node *right;
    struct Node *left;
    int value;
} Node;

typedef struct {
    Node *root;
} AVLTree;

AVLTree *tree = NULL;

void printTree(Node *next) {
    if(next != NULL) {
        printTree(next->left);
        printf("%d ", next->value);
        printTree(next->right);
    }
}

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