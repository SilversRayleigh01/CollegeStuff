#include <stdio.h>
#define size 5

typedef struct queue{
    int f,r;
    int q[size];
}Cq;

void init(Cq *obj){
    obj->f = -1;
    obj->r = -1;

}


void insertrear(int ele, Cq* obj){
    if(((obj->r+1)%size)== obj->f){
        printf("Overflow\n");
    }
    else {
    if(obj->f == -1){
        obj->f =0;
    }
        obj->r = (obj->r+1)%size;
        obj->q[obj->r] = ele;


    
}
}



void dequeue(Cq * obj){
    if(obj->f == -1){
        printf("EMptyqueue\n");
    }
    else {
    if(obj->f == obj->r){
        obj->f = obj->r = -1;

    }

    else{
        printf("Deleted element: %d\n",obj->q[obj->f]);
        obj->f = ((obj->f)+1)%size;
    }
}
}

void display(Cq * obj){
    if(obj->f == -1){
        printf("EMptyqueue\n");
    }
    else{
        int i = obj->f;
        while(i!=obj->r){
            printf("%d",obj->q[i]);
            i = (i+1)%size;
        }
        printf("%d\n",obj->q[i]);
    }
}
int main(){
    Cq obj;
    init(&obj);
    int ch,ele;
    printf("1. insert rear 2: deletefront 3.display\n");
    do{
        printf("ENter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter element: ");
                    scanf("%d",&ele);
                    insertrear(ele,&obj);
                    break;

            case 2: dequeue(&obj);
                    break;

            case 3: display(&obj);
                    break;
            case 4: printf("Exited");
                    break;
        }
    }while(ch!=4);
}