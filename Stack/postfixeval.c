// int isdigit(int digit) isdigit is a built in function in ctype.h.checks whther a single char is a decimal digit(0-9)
//return value  is non zero if char is digit. zero otherwise
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#define max 10

typedef struct stack{
    int s[max];
    int top;
}stk;

void init(stk *obj){
    obj->top = -1;
}
int pop(stk *obj){
    if(obj->top == -1){
        printf("Empty stack\n");
    }
    else{
        return(obj->s[(obj->top)--]);
    }
}

void push(int ele,stk *obj){
    if (obj->top == max-1){
        printf("STACK OVERFLOW\n");
    }
    else{
        obj->s[++(obj->top)] = ele;

    }
}

int eval(char postfix[]){
    stk obj;
    int res,A,B;
    init(&obj);
    for(int i = 0; postfix[i]!='\0';i++){
        if(isdigit(postfix[i])){
            push(postfix[i]-'0',&obj);
        }
        else{
            A = pop(&obj);
            B = pop(&obj);

        
        switch(postfix[i]){
            case '+':
            res  = B+A;
            break;
            case '-':
            res  = B-A;
            break;
            case '*':
            res  = B*A;
            break;
            case '/':
            if(A == 0){
                return INT_MAX;
            }
            else{
            res  = B/A;
            break;
            }


        }
        push(res,&obj);
    }
}
    return pop(&obj);
}


int main(){
    char postfix[25];
    int eval_postfix;
    printf("Enter the postfix expression");
    scanf("%s",postfix);
    eval_postfix = eval(postfix);
    if (eval_postfix == INT_MAX){
        printf("Division by zero error\n");
    }
    else{
        printf("Evaluated postfix value: %d\n",eval_postfix);
    }
    return 0;
}