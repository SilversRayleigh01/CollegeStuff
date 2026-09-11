#include <stdio.h>
#include <stdlib.h>


// Array lists
/*MALLOC
int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int *p = (int*)malloc(n*sizeof(int));
    if(p == NULL){
        printf("memory not allocated\n");
        return 1;
    }
    for(int i = 0;i<n;i++){
        printf("The Base adress is: %p\n",p+i);
        printf("The contents in the memory is : %d\n",*(p+i));
        *(p+i) += 20;
        printf("Post operation: %d\n",*(p+i));
        printf("Contents: %d Base Adress: %p\n",*(p+i),p+i);
    }
    free(p);
    return 0;


}
*/



/*CALLOC
int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int *p = (int*)calloc(n,sizeof(int));
    if(p == NULL){
        printf("memory not allocated\n");
        return 1;
    }
    for(int i = 0;i<n;i++){
        printf("The Base adress is: %p\n",p+i);
        printf("The contents in the memory is : %d\n",*(p+i));
        *(p+i) += 20;
        printf("Post operation: %d\n",*(p+i));
        printf("Contents: %d Base Adress: %p\n",*(p+i),p+i);
    }
    free(p);
    return 0;
}*/



/*REALLOC
int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int *p = (int*)malloc(n*sizeof(int));
    if(p == NULL){
        printf("memory not allocated\n");
        return 1;
    }
    for(int i = 0;i<n;i++){
        printf("The Base adress is: %p\n",p+i);
        printf("The contents in the memory is : %d\n",*(p+i));
        *(p+i) += 20;
        printf("Post operation: %d\n",*(p+i));
        printf("Contents: %d Base Adress: %p\n\n",*(p+i),p+i);
    }
    int new;
    printf("Enter the new number of elements in the array: ");
    scanf("%d",&new);
    p = (int*)realloc(p,new*sizeof(int));
        if(p == NULL){
        printf("memory not reallocated\n");
        return 1;
    }
    for(int i = 0;i<new;i++){
        printf("The Base adress is: %p\n",p+i);
        printf("The contents in the memory is : %d\n",*(p+i));
        *(p+i) += 20;
        printf("Post operation: %d\n",*(p+i));
        printf("Contents: %d Adress: %p\n\n",*(p+i),p+i);
    }
    free(p);
    p = NULL;
    return 0;


}*/

#define max 10
typedef struct data{
    int c[max];
    int last;
}arrlist;


void init(arrlist *p){
    p -> last = -1;
}

int append(arrlist *p,int ele){
    if((p->last)==(max-1)){
        printf("Overflow\n");
        return 0;
    }
    else{

        ++p->last;
        p->c[p->last] = ele;
        printf("Insertion done");
        return 1;
        
    }
}


int display(arrlist *p){
    printf("Elements in the list is: ");
    ++p->last;
    for(int i = p->last;i<max;i++){
        printf("%d %d",i,p->c[i]);
    }
}










int main(){
    arrlist *obj;
    init(obj);
    printf("1. Append , 2. Delete , 3. Display");
    printf("Enter your choice");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Enter ele\n");
        scanf("%d",&ch);
        
    }

    
}
