#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *right,*left;
    int rthread;
}NODE;

typedef struct tree
{
    NODE *root;
}TREE;

void init(TREE *obj){
    obj->root = NULL;
}

NODE *createnode(int ele){
        NODE*tmp = (NODE *)malloc(sizeof(NODE));
        tmp->info = ele;
        tmp ->right = NULL;
        tmp->rthread = 1;

}

void set_left(NODE *p,int ele){
    NODE*tmp = (NODE *)malloc(sizeof(NODE));
    tmp->info=ele;
    p->left = tmp;
    tmp ->right = p;
}

void set_right(NODE*p,int ele){
    NODE*tmp = (NODE *)malloc(sizeof(NODE));
    tmp ->right = p->right;
    p->right = tmp;
    p->rthread = 0;    
}

void create(TREE *obj){
    int ele,ch;
    printf("Enter root ele: ");
    scanf("%d",&ele);
    obj->root = createnode(ele);

    do{
        printf("Enter choice: ");
        scanf("%d",&ch);
        NODE*p = obj->root;
        NODE *q;
        while(p!=NULL){
            if(ele<p->info){
                p = p->left;
            }
            else{
                    if(p->rthread){
                        p = NULL;
                    }
                    else{
                        p = p->right;
                    }
            }
        if(ele<q->info){
            set_left(q,ele);
        }
        else{
            set_right(q,ele);
        }
        }
    }while(ch!=0);
    
}

void inorder_traversal(){

}

