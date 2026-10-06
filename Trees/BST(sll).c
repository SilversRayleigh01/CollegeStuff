#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}node;

typedef struct tree{
    node* root;
}tree;



void init(tree* obj){
    obj->root = NULL;
}

void insert(tree* obj,int ele,int index){
    node* newnode = malloc(sizeof(node));

    if (obj->root == NULL){
        obj->root = newnode;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    else{

    }

}