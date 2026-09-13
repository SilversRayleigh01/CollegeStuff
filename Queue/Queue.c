/*#include <stdio.h>
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
*/




#include <stdio.h>
#include <stdlib.h>


typedef struct queue{
    int f, r;
    int *s;
}q;

void init(q *);
void enq(q *,int ,int );
void deq(q *);
void display(q* );


void init(q *obj){
    obj->f = -1;
    obj->r = -1;
    obj->s = NULL;
}

int* createq(int sz){
    int *arr = malloc(sizeof(int) * sz);
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
    }
    return arr;
}

void enq(q *obj,int sz,int ele){
    if(obj->r == sz-1){
        printf("Overflow\n");
        return;
    }
    if(obj->f == -1){
        obj->f = 0;
    }
    obj->s[++(obj->r)] = ele;
    printf("Inserted: %d\n",ele);

    
}

void deq(q* obj){
    if(obj->f == -1 || obj->f>obj->r){
        printf("Underflow\n");
        return;
    }
    printf("Deleted element: %d\n",obj->s[(obj->f)]);
    if(obj->f == obj->r){
        obj->f = -1;
        obj->r = -1;
    }
    else{
        obj->f++;
    }
}



void display(q* obj){
    if(obj->f == -1 || obj->f>obj->r){
        printf("Queue Empty\n");
        return;
    }
    printf("Queue Elements: ");
    for(int i = obj->f;i<=obj->r;i++){
        printf("%d ",obj->s[i]);
    }
    printf("\n");
}
int main() {
    q obj;
    int ch, sz = 0, ele;
    init(&obj);
    
    printf("1. CREATE 2. ENQUEUE 3. DEQUEUE 4. DISPLAY 5. EXIT\n");
    do {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                if (obj.s != NULL) {
                    free(obj.s); // Free previously allocated memory before recreating
                    init(&obj);
                }
                printf("Enter array size: ");
                scanf("%d", &sz);
                obj.s = createq(sz);
                if (obj.s != NULL) {
                    printf("Queue of size %d created.\n", sz);
                }
                break;
            case 2:
                if (obj.s == NULL) {
                    printf("Create queue first!\n");
                    break;
                }
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                enq(&obj, sz, ele);
                break;
            case 3:
                deq(&obj);
                break;
            case 4:
                display(&obj);
                break;
            case 5:
                free(obj.s);
                obj.s = NULL;
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 5);

    return 0;
}