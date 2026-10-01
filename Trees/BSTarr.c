#include <stdio.h>
#include <stdlib.h>
#define size 64


typedef struct node{
    int data;
    int used;
}node;


void insert(int ele, node *obj,int index){
    if (index >= size){
        printf("Overflow\n");
        return;
    }
    if (obj[index].used == 0){
        obj[index].data = ele;
        obj[index].used = 1;
        return;//this is used beacuse after this no other checks are required and no unnecessary recursion take place
    }
    else if(obj[index].data>ele){
        index = 2*index+1;
        insert(ele,obj,index);
    }
    else if(obj[index].data<ele){
        index = 2*index+2;
        insert(ele,obj,index);
    }
}

void inorder(node* obj,int index){
    if(index>=size || obj[index].used == 0)//index>=size must always be checked before obj[index].used
    {
        return;
    }
    inorder(obj,2*index+1);
    printf("%d ",obj[index].data);
    inorder(obj,(2*index+2));
}



int main(){
    node obj[size] ={} ;
    int ele,ch;

    do{
        printf("Enter element: ");
        scanf("%d",&ele);
        insert(ele,obj,0);
        
        printf("Enter 1 to continue(0 to stop): ");
        scanf("%d",&ch);
    
    }while(ch);

    printf("Inorder traversal: ");
    inorder(obj,0);
    return 0;
}

