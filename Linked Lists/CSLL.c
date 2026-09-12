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
int count(node* );
void display(node*);
void deletefront(node**);
void deleteend(node**);
void deletepos(node**,int);

node* createnode(int val){
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL){
        printf("memory not allocated");
        return NULL;
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



void insertpos(node**tail , int pos,int ele ){
    int totpos = count(*tail);

    
    if(pos >= 1 && pos <= totpos+1){
        
            
                if(pos==1){
                    insertfront(tail,ele);
                }
                else if(pos == totpos+1){
                    insertend(tail,ele);
                }
                else{
                    node* newnode = createnode(ele);
                    if(newnode == NULL)return;
                    node * p = (*tail)->link;
                    for(int i = 1;i<pos-1;i++){
                        p=p->link;
                    }
                    newnode->link = p->link;
                    p->link  = newnode;
                }
            }
    else{
            printf("Invalid position");
        }

}


void deletefront(node** tail){
    if(*tail ==NULL){
        printf("Empty List \n");
        return;
    }
    node* p = (*tail)->link;
    if(p==*tail){
        free(p);
        *tail = NULL;
    }
    else{
        (*tail)->link = p ->link;
        free(p);
    }
    
}

void deleteend(node** tail){
    if(*tail ==NULL){
        printf("Empty List \n");
        return;
    }
    node* p = (*tail)->link;
    if(p==*tail){
        free(p);
        *tail = NULL;
    }
    else{
        while(p->link!=*tail){
            p=p->link;
        } 
        
        p->link = (*tail)->link;
        free(*tail);
        *tail = p;
    }
}

void deletepos(node** tail,int pos){
    int totpos = count(*tail);

    
    if(pos >= 1 && pos <= totpos){
        if(pos == 1){
            deletefront(tail);
        }
        else if(pos == totpos){
            deleteend(tail);
        }
        else{
            node* p = (*tail)->link;
            for(int i = 1;i<pos-1;i++){
                p = p->link;
            }
            node* tmp = p->link;
            p->link = tmp->link;
            free(tmp);

        }


    }
            
    else{
            printf("Invalid position\n");
        }


}

int count(node* tail){
    int cnt = 0;
    node* p = tail;
    if(tail == NULL){
        return 0;
    }
    while(p->link!=tail){
        cnt++;
        p = p->link;
        
    }
    return cnt+1;
}
void display(node*tail){
    if(tail == NULL){
        return;
    }
    node* t = tail->link;
    
    while(t!=(tail)){
        printf("%d-> ",t->data);
        t=t->link;
    }
    printf("%d| ",t->data);
    printf("\n");
}





int main(){
    node* tail;
    init(&tail);
    printf("1. Insert at head 2. Insert at tail 3. Insert at given position 4. Delete front 5.Delete tail 6. Delete specific position 7. Display 8. Exit \n");
    
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
    case 3 :printf("Enter the value to be added at specific position");
            scanf("%d",&val);
            printf("Enter the position to add the element");
            scanf("%d",&pos);
            insertpos(&tail,pos,val);
            break;
    case 4 :printf("Deleting first element: \n");
            deletefront(&tail);
            break;
    case 5 :printf("Deleting last element: \n");
            deleteend(&tail);
            break;
    case 6 :printf("Enter the position of the element to be deleted: ");
            scanf("%d",&pos);
            deletepos(&tail,pos);
            break;
    case 7 :printf("The list: ");
            display(tail);
            break;
    case 8 :break;
            }
}while(ch<8);
return 0;
}

 
        