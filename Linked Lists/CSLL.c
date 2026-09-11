#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *link;

}node;

node*createnode(int);
void insertfront(node**,int);
void init(node**);
void insertend(node**,int);
void display(node*);

node* createnode(int val){
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL){
        printf("memory not allocated");
        return 0;
    }
    else{
    newnode->data = val;
    newnode->link = NULL;
    return newnode;
    }
}

void init(node**tail){
    *tail =NULL;
}


void insertfront(node**tail,int val){
    node* newnode = createnode(val);
    if(*tail==NULL){
        *tail = newnode;
        newnode->link = *tail;
    }
    else{
            newnode->link = (*tail)->link;
            (*tail)->link = newnode;
    }
}


void insertend(node**tail,int val){
    node * newnode = createnode(val);
    if(*tail==NULL){
        *tail = newnode;
        newnode->link = *tail;
    }
    else{
        newnode->link = (*tail)->link;
        (*tail)->link= newnode;
        *tail = newnode;
    }
}

void display(node*tail){
    node* t = tail;
    while(t!=(tail)){
        printf("%d-> ",(t->link)->data);
        t=t->link;
    }
    printf("%d|",t->data);

}





int main(){
    node* tail;
    init(&tail);
    printf("1. Insert at head 2. Insert at tail 3. Insert at given position\n");
    
    int ch,val,pos;
    
    do{
        printf("Enter choice");
        scanf("%d",&ch);
    switch(ch){
    case 1 :printf("Enter the value to be added at head: ");
            scanf("%d",&val);
            insertfront(&tail,val);
            
            break;

    case 2 :printf("Enter value to be added at tail: ");
            scanf("%d",&val);
            insertend(&tail,val);
            break;
    /*case 3 :printf("Enter the value to be added at specific position");
            scanf("%d",&val);
            printf("Enter the position to add the element");
            scanf("%d",&pos);
            insertatpos(&tail,val,pos);
            break;*/
    case 4 :printf("The list: ");
            display(tail);
            break;
            }
}while(ch<5);
return 0;
}

 
        