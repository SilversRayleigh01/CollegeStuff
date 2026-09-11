//STACK using linked list 
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int ele;
    struct node * next;
}node;

void init(node **);
void init(node **head){
    *(head) = NULL;
}

node* createnode(node** head,int ele){
    node* newnode = malloc(sizeof(node));
    if(*(head) == NULL){
        *head  = newnode;
        return (*head);
    } 
    else{
    newnode->ele = ele;
    (*head)->next = newnode;
    return newnode;
    }
}

void push(node ** head,int ele){
    node * newnode = createnode(*head,ele);
    if (*(head) == NULL){
        *head = newnode;
    }
    else{
        
    }
}