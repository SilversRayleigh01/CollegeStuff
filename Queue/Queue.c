#include <stdio.h>
#include <stdlib.h>
typedef struct queue{
    int f,r;
    int *s;
}q;

void init(q *obj){
    obj->f = -1;
    obj->r = -1;

}


int *createQ(int sz){
    return malloc(sizeof(int)*sz);

}

void EnQ(int ele,q *obj,int sz){
    if(obj->r == sz-1){
        printf("Overflow");
        return;
    }
    else if(obj->f == obj->r){
        obj->f == 0;
        obj->s[++(obj->r)] = ele;
    }
}

void DeQ(q *obj,int sz){
    if(obj->f == -1){
        printf("Underflow");
        return;
    }
    else if(obj->f == obj->r){
        obj->r = obj->f=-1;
    }
    else{
        printf("Deleted ele: %d\n",obj->s[obj->f]);
    }
}


int main(){
    q obj;
    int ch,sz;
    init(&obj);
    printf("1. CREATE 2. ENQUEUE 3. DEQUEUE 4.DISPLAY");
    do{
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter arrary size");
                    scanf("%d",&sz);
                    obj.s = createQ;
                    break;
            case 2: 
            
        }
    }while(ch<5);

}
