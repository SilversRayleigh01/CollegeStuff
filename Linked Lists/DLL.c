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

void init(list* head);
void insertathead(list *obj,int ele);
void insertatend(list *obj,int ele);
void insertatpos(list *obj,int ele,int pos);
void deletehead(list* obj);
void deleteatend(list* obj);
void deleteatpos(list* obj,int pos);





void init(list* obj){
    obj->head = NULL;
}

node * createnode(int ele){
    node* newnode = malloc(sizeof(node));
    newnode->data = ele;
    newnode ->next = NULL;
    newnode ->prev = NULL;
    return newnode;
} 

void insertathead(list *obj,int ele){
    node* newnode = createnode(ele);
    if(obj->head == NULL){
        obj->head = newnode;
    }
    else{
        
        newnode->next = obj->head;
        obj->head->prev = newnode;
        obj->head = newnode;

    }

}

void insertatend(list *obj,int ele){
    node *newnode = createnode(ele);
    if(obj->head == NULL){
        obj->head = newnode;
    }
    else{
        node *p = obj->head;
        while(p->next!=NULL){
            p = p->next;
        } 
        p->next = newnode;
        newnode->prev = p;
    
        
    }
}




void insertatpos(list *obj,int ele,int pos){
    if (obj == NULL) return;
    int tot_cnt = count(obj);

    if(pos<1||pos>tot_cnt+1){
        printf("Invalid positon\n");
        return;
    }
    if(pos == 1){
        insertathead(obj,ele);
        return;
    }
    if(pos == tot_cnt+1){
        insertatend(obj,ele);
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


void deletehead(list* obj){
    node *p = obj->head;
    if(obj->head == NULL){
        printf("Error: Empty List");
        return;
    }
    if(obj->head->next == NULL){
       
        
        free(p);
        obj->head = NULL;
    }
    else{
        obj->head = p->next;
        obj->head->prev = NULL;
        free(p);
        
    }
}

void deleteatend(list* obj){
    node* p = obj->head;
    if(obj->head == NULL){
        printf("Error: Empty List");
        return;
    }
    if(obj->head->next == NULL){
       
        
        free(p);
        obj->head = NULL;
    }
    else{
        while(p->next!=NULL){
            p = p->next;
        }
        p->prev->next = NULL;
        free(p);
        p = NULL;
        
    }

}



void deleteatpos(list* obj,int pos){
    node* p = obj->head; 
    int cnt = count(obj);
    if(obj->head == NULL){
        printf("Error: Empty List");
        return;
    }
    if(obj->head->next == NULL){
        free(p);
        p = NULL;
    }
    else{
        if(pos<1 || pos>cnt){
            printf("invalid input\n");
            return; 
        }   
        else if(pos == 1){
            deletehead(obj);
        }
        else if (pos == cnt){
            deleteatend(obj);

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


void display(list *obj){
    if(obj->head==NULL){
        printf("Empty List\n");
    }
    else{
        node *p = obj->head;
        while(p!=NULL){
            printf("%d->",p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int count(list *obj){
    int count = 0;
    node*p = obj->head;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}




int main(){
    
}