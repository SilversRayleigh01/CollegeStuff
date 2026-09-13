//STACK using linked list 
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int ele;
    struct node * next;
}node;

void init(node **);
node* createnode(int);
void push(node **,int);
void pop(node **);
int peek(node*);
void display(node*);

void init(node **head){
    *(head) = NULL;
}

node* createnode(int ele){
    node* newnode = malloc(sizeof(node));
    
   
    newnode->ele = ele;
    newnode->next = NULL;
    return newnode;

    
}

void push(node ** head,int ele){
    node * newnode = createnode(ele);
    if (newnode == NULL) return;
    newnode->next = *head;
    *head = newnode;

}

void pop(node **head){
    
    if (*head == NULL) {
        printf("Empty Stack\n");
        return;
    }
    node* p = *head;
    *head = (*head)->next;
    free(p);


}

int peek(node*head){
    if(head == NULL){
        printf("Empty stack\n");
        return 0;
    }
    return head->ele;
}

void display(node* head){
    if(head == NULL){
        printf("Empty stack\n");
        return;
    }
    node*p = head; 
    while (p!=NULL){
        printf("%d->",p->ele);
        p = p->next;
    }
    printf("NULL\n");

}



int main(){
    node *head;
    init(&head);
    int ch,ele;
    printf("1. Push 2. Pop 3. Peek 4. Display 5. Exit\n");
    do{
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter elemnet to push onto stack: ");
                    scanf("%d",&ele);
                    push(&head,ele);
                    break;
            case 2: 
                if (head == NULL) {
                    printf("Stack is empty! Nothing to pop.\n");
                } 
                else {
                        printf("Executing pop \n");
                        printf("Element popped: %d\n", peek(head));
                        pop(&head);
                    }
    break;
            case 3: printf("The top element is: %d\n",peek(head));
                    break;
            case 4: printf("STACK: ");
                    display(head);
                    break;
            case 5: break;
            default: printf("Invalid Choice\n");
        }
    }while(ch!=5);
    
}