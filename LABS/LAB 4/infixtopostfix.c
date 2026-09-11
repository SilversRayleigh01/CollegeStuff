/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 10
typedef struct stack{
    char s[max];
    char top;
}stk;


void init(stk *obj){
    obj->top = -1;
}
char pop(stk *obj){
    if(obj->top == -1){
        printf("Empty stack\n");
    }
    else{
        return(obj->s[(obj->top)--]);
    }
}

void push(char ele,stk *obj){
    if (obj->top == max-1){
        printf("STACK OVERFLOW\n");
    }
    else{
        obj->s[++(obj->top)] = ele;

    }
}



char * eval(char infix[]){
    stk *obj;
    init(obj);
    char s[max];
    for(int i = 0; infix[i]!='\0';i++){
        if(isdigit(infix[i])){
            push(infix[i],&obj);
        }
        if(ord(infix[i])>=65 && ord(infix[i])<=122){
            push(infix[i],&obj);
        }
        if(infix[i] == "("){
            push(infix[i],&obj);
            int n = obj->top;
            if(infix[i]==")"){
                while(infix[n]!="("){
                    strcat(s,pop(obj));
                }

            }
        }
    }
}

int main(){
    

}
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 25

typedef struct {
    char items[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    return s->items[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    s.top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        
        if (ch == ' ') continue;

        if (isalnum(ch)) {
            while (isalnum(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' ';
            i--; 
        }
        else if (ch == '(') {
            push(&s, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
                postfix[k++] = ' ';
            }
            pop(&s); // remove '('
        }
        else {
            while (!isEmpty(&s) && peek(&s) != '(') {
                if (ch == '^' && getPrecedence(peek(&s)) > getPrecedence(ch)) {
                    postfix[k++] = pop(&s);
                    postfix[k++] = ' ';
                } 
                else if (ch != '^' && getPrecedence(peek(&s)) >= getPrecedence(ch)) {
                    postfix[k++] = pop(&s);
                    postfix[k++] = ' ';
                } 
                else {
                    break;
                }
            }
            push(&s, ch);
        }
    }

    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
        postfix[k++] = ' ';
    }

    if (k > 0 && postfix[k - 1] == ' ') {
        postfix[k - 1] = '\0';
    } else {
        postfix[k] = '\0';
    }
}

int main() {
    char infix[MAX];
    char postfix[MAX * 2];

    printf("Enter infix: ");
    fgets(infix, sizeof(infix), stdin);

    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);
    return 0;
}