#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
    struct NODE *prev;
}node;
typedef struct list{
    node* head;
}list;
void init(node** head){
    head = NULL;
}

node * createnode(int ele){
    node* newnode = malloc(sizeof(node));
    newnode->data = ele;
    newnode ->next = NULL;
    newnode ->prev = NULL;
    return newnode;
} 

void insertfront(list* obj,int val){
    node* newnode = createnode(val);
    if((obj->head) == NULL){
        obj->head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else{
        newnode->next = obj->head;
        newnode->prev = obj->head->prev;
        obj->head->prev->next = newnode;
        obj->head->prev = newnode;
        obj->head = newnode; 
    }
}