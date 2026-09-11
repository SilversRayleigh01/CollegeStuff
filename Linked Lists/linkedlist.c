#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *link;

}node;

node* createnode(int);
void insertathead(node**, int);
void insertattail(node**, int);
void insertatpos(node**, int,int);
int count(node*);
void display(node*);
void init(node**);
void deleteathead(node**);
void deleteattail(node**);

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


void insertathead(node** head, int val){
    node* newnode = createnode(val);
    if (*head == NULL){
        *head = newnode;
    }
    else{
    newnode->link = *head;
    *head  = newnode;
    }
}



void init(node**head){
    *head =NULL;
}



void insertattail(node **head,int val){
    node* newnode = createnode(val);
    if (*head == NULL){
        *head = newnode;
    }
    else{
        node *tmp = *head;
        while (tmp->link!=NULL){
            tmp = tmp->link;
        }
        tmp->link = newnode;
        
    }

}

void insertatpos(node**head,int val, int pos){
    int tot_pos = count(*head);
    if (pos<0 || pos>tot_pos){
        printf("Enter a valid position to insert the element at: ");
        return ;
    }
    else{
        node*tmp = *head;
        for(int i = 0; i<pos-1;i++){
           tmp = tmp->link; 
        }
        node*newnode = createnode(val);
        newnode->link = tmp->link;
        tmp->link = newnode;

    }

}

int count(node*head){
    int cnt = 0;
    node* tmp = head;
    while(tmp!=NULL){
        tmp = tmp -> link;
        cnt++;
    }
    return cnt;
}

void display(node* head){
    if(head==NULL){
        printf("list is empty\n");
    }
    else{
        node *tmp = head;
        while(tmp!=NULL){
            printf("%d-> ",tmp->data);
            tmp = tmp->link;//stops just before the last node and pointer is at the last node

        }
        printf("NULL\n");//prints the last node 

    }
}

void deleteathead(node**head){
    
    if (*head == NULL){
        printf("Error the list is empty");
        return;
    }
    else{
        node *tmp = *head;
        *head = (*head)->link;
        free(tmp);
    }
}

void deleteattail(node** head){
    if (*head == NULL){
        printf("Error the list is empty");
        return;

    }
    
    else{
        node *tmp = *head;
        while(tmp->link!=NULL){
            tmp = tmp -> link;
        }
        tmp = tmp -> link;

    free(tmp);
    }
}


int main(){
    node* head;
    init(&head);
    printf("1. Insert at head 2. Insert at tail 3. Insert at given position\n");
    
    int ch,val,pos;
    
    do{
        printf("Enter choice");
        scanf("%d",&ch);
    switch(ch){
    case 1 :printf("Enter the value to be added at head: ");
            scanf("%d",&val);
            insertathead(&head,val);
            
            break;

    case 2 :printf("Enter value to be added at tail: ");
            scanf("%d",&val);
            insertattail(&head,val);
            break;
    case 3 :printf("Enter the value to be added at specific position");
            scanf("%d",&val);
            printf("Enter the position to add the element");
            scanf("%d",&pos);
            insertatpos(&head,val,pos);
            break;

    case 4 :printf("Deleting the first element of the list\n");
            deleteathead(&head);
            break;

    case 5 :printf("Deleting the last element of the list\n");
            deleteattail(&head);
            break;
    case 6 :printf("The list: ");
            display(head);
            break;

    }
}while(ch<7);

    

}  
             


