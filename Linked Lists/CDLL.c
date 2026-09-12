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
void init(list* obj){
   obj-> head = NULL;
}


node * createnode(int);
void insertfront(list*,int);
void insertrear(list*,int);
void insertpos(list*,int,int);
int count(list *);
void deletefront(list*);
void deleterear(list* );
void deletepos(list*,int);
void display(list*);

node * createnode(int ele){
    node* newnode = malloc(sizeof(node));
    newnode->data = ele;
    newnode ->next = NULL;
    newnode ->prev = NULL;
    return newnode;
} 

void insertfront(list* obj,int val){
    node* newnode = createnode(val);
    if(newnode == NULL) return;
    if((obj->head) == NULL){
        obj->head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }

    else{
            newnode -> next = obj->head;
            newnode->prev = obj->head->prev;
            obj->head->prev->next = newnode;
            obj->head->prev = newnode;
            obj->head = newnode; 
         
    }
}


void insertrear(list* obj,int val){
    node* newnode = createnode(val);
    if(newnode == NULL) return;
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

    }

}

void insertpos(list* obj,int pos,int ele){
    
    if (obj == NULL) return;
    int tot_cnt = count(obj);

    if(pos<1||pos>tot_cnt+1){
        printf("Invalid positon\n");
        return;
    }
    if(pos == 1){
        insertfront(obj,ele);
        return;
    }
    if(pos == tot_cnt+1){
        insertrear(obj,ele);
        return;
    }
    node* newnode = createnode(ele);
    node* p = obj->head;
    for (int i = 1;i<pos-1;i++){
        p = p->next;
    }
    newnode -> next = p->next;
    newnode ->prev = p;
    p->next->prev = newnode;
    p->next = newnode;
}

int count(list *obj){
    int count = 0;
    if(obj->head==NULL)return 0;
    node*p = obj->head;
    while(p->next!=obj->head){
        count++;
        p=p->next;
    }
    return count+1;
}


void deletefront(list* obj){
    if(obj->head==NULL){
        printf("Empty List\n");
        return;
    }
    else if(obj->head->next == obj->head){
        node* p = obj->head;
        free(p);
        obj->head = NULL;
    }
    else{
        obj->head->prev->next = obj->head->next;
        obj->head->next->prev = obj->head->prev;
        node*p = obj->head;
        obj->head = obj->head->next;
        free(p);
       

    }
}


void deleterear(list* obj){
    if(obj->head==NULL){
        printf("Empty List\n");
        return;
    }
    else if(obj->head->next == obj->head){
        node* p = obj->head;
        free(p);
        obj->head = NULL;
    }
    else{
        obj->head->prev->prev->next = obj->head;
        node* p = obj->head->prev;
        obj->head->prev = obj->head->prev->prev;
        free(p);
        
        
    }

}

void deletepos(list* obj,int pos){
    node* p = obj->head; 
    int cnt = count(obj);
    if (pos>=1 && pos<=cnt){
    if(obj->head == NULL){
        printf("Error: Empty List");
        return;
    }
    else if(obj->head->next == obj->head){
        free(p);
        obj->head = NULL;
    }
    else{
        if(pos == 1){
            deletefront(obj);
        }
        else if (pos == cnt){
            deleterear(obj);

        }
        else{
        for(int i = 0;i<pos-1;i++){
                p = p->next;
            }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
        }  
        
        
    }
}
    else{
        printf("Invalid Position");
        return;

    }
    
}

void display(list* obj){
    if(obj->head==NULL){
        printf("Empty List\n");
        return;
    }
    else{
        node* p = obj->head;
        while(p->next!=obj->head){
            printf("%d->",p->data);
            p=p->next;
        }
        printf("%d|",p->data);
        printf("\n");
    }
    

}





int main(){
    list obj;
    init((&obj));
    printf("1. Insert at head 2. Insert at tail 3. Insert at given position 4. Delete front 5.Delete head 6. Delete specific position 7. Display 8. Exit \n");
    
    int ch,val,pos;
    
    do{
        printf("Enter choice");
        scanf("%d",&ch);
    switch(ch){
    case 1 :printf("Enter the value to be added at head: ");
            scanf("%d",&val);
            insertfront(&obj,val);
            
            break;

    case 2 :printf("Enter value to be added at head: ");
            scanf("%d",&val);
            insertrear(&obj,val);
            break;
    case 3 :printf("Enter the value to be added at specific position");
            scanf("%d",&val);
            printf("Enter the position to add the element");
            scanf("%d",&pos);
            insertpos(&obj,pos,val);
            break;
    case 4 :printf("Deleting first element: \n");
            deletefront(&obj);
            break;
    case 5 :printf("Deleting last element: \n");
            deleterear(&obj);
            break;
    case 6 :printf("Enter the position of the element to be deleted: ");
            scanf("%d",&pos);
            deletepos(&obj,pos);
            break;
    case 7 :printf("The list: ");
            display(&obj);
            break;
    case 8 :break;
            }
}while(ch<8);
return 0;
}
