#include <stdio.h>
#include <stdlib.h>
/*
typedef struct node
{
    int coeff;
    int exp;
    struct node *next;
} node;


node* createpolynomial(){
    node* p;
    int n;
    printf("Enter the degree of the polynomial: ");
    scanf("%d",&n);
    node* head = NULL;
    node* tail = NULL;
    for(int i = 0; i<=n;i++){
        node* newnode = malloc(sizeof(node));
        if(newnode == NULL){
            printf("Memory allocation failed\n");
            return head;
        }
        printf("Enter the %dth term of polynomial: \n",i);
        printf("Coefficient: ");
        scanf("%d",&(newnode->coeff));
        printf("Exponent: ");
        scanf("%d",&(newnode->exp));
        newnode->next = NULL;


        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
        return head;
    }


}

void display(node* p){
    if(p == NULL){
        printf("Polynomial is empty\n");
        return;
    }
    node* tmp = p;
    while(tmp!=NULL){
        printf("%d*x^%d",tmp->coeff,tmp->exp);
        if(tmp->next!=NULL){
            printf(" + ");
        }
        tmp = tmp->next;
    }
    printf("\n");
}

int main(){

    node* p = NULL;
    printf("Enter the operation to be performed: \n");
    printf("1.Create Polynomial 2.Display\n");
    int ch;
    do{
        printf("ENter Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Creating a polynomial:\n");
                    p = createpolynomial();
                    break;
            case 2: printf("Displaying polynomial: ");
                    display(p);
                    break;
            case 3: printf("Exiting");
                    break;
            default: printf("Invalid choice\n");
        }
    }while(ch!=3);
    return 0;
}
*/

/*#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;
    int exp;
    struct node *next;
} NODE;
NODE* insertTerm(NODE *head, int c, int e) {
    if (c == 0) return head;

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    // Case 1: Insert at front
    if (head == NULL || e > head->exp) {
        newNode->next = head;
        return newNode;
    }

    // Case 2: Matches head's exponent
    if (head->exp == e) {
        head->coeff += c;
        free(newNode);
        return head;
    }

    // Case 3: Traverse to find correct position
    NODE *curr = head;
    while (curr->next != NULL && curr->next->exp > e)
        curr = curr->next;

    if (curr->next != NULL && curr->next->exp == e) {
        curr->next->coeff += c;
        free(newNode);
    } else {
        newNode->next = curr->next;
        curr->next = newNode;
    }
    return head;
}

NODE* createPolynomial() {
    NODE *head = NULL;
    int n, c, e;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Term %d (coeff exp): ", i + 1);
        scanf("%d %d", &c, &e);
        head = insertTerm(head, c, e);
    }
    return head;
}

void display(NODE *p) {
    if (p == NULL) {
        printf("0\n");
        return;
    }
    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next != NULL) printf(" + ");
        p = p->next;
    }
    printf("\n");
}

NODE* addPolynomial(NODE *p1, NODE *p2) {
    NODE *res = NULL;
    while (p1 != NULL) { res = insertTerm(res, p1->coeff, p1->exp); p1 = p1->next; }
    while (p2 != NULL) { res = insertTerm(res, p2->coeff, p2->exp); p2 = p2->next; }
    return res;
}

NODE* subtractPolynomial(NODE *p1, NODE *p2) {
    NODE *res = NULL;
    while (p1 != NULL) { res = insertTerm(res, p1->coeff, p1->exp); p1 = p1->next; }
    while (p2 != NULL) { res = insertTerm(res, -p2->coeff, p2->exp); p2 = p2->next; }
    return res;
}

NODE* multiplyPolynomial(NODE *p1, NODE *p2) {
    NODE *res = NULL;
    for (NODE *t1 = p1; t1 != NULL; t1 = t1->next)
        for (NODE *t2 = p2; t2 != NULL; t2 = t2->next)
            res = insertTerm(res, t1->coeff * t2->coeff, t1->exp + t2->exp);
    return res;
}

int evaluate(NODE *p, int x) {
    int total = 0;
    while (p != NULL) {
        int termVal = p->coeff;
        for (int i = 0; i < p->exp; i++)
            termVal *= x;
        total += termVal;
        p = p->next;
    }
    return total;
}

int main() {
    NODE *p1 = NULL, *p2 = NULL, *res = NULL;
    int ch, x;

    while (1) {
        printf("\n1. Create P1\n2. Create P2\n3. Display\n4. Add (P1+P2)\n5. Subtract (P1-P2)\n6. Multiply (P1*P2)\n7. Evaluate P1\n8. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &ch) != 1 || ch == 8) break;

        switch (ch) {
            case 1: p1 = createPolynomial(); break;
            case 2: p2 = createPolynomial(); break;
            case 3:
                printf("P1: "); display(p1);
                printf("P2: "); display(p2);
                break;
            case 4:
                res = addPolynomial(p1, p2);
                printf("Sum: "); display(res);
                break;
            case 5:
                res = subtractPolynomial(p1, p2);
                printf("Difference: "); display(res);
                break;
            case 6:
                res = multiplyPolynomial(p1, p2);
                printf("Product: "); display(res);
                break;
            case 7:
                printf("Enter x: ");
                scanf("%d", &x);
                printf("P1(%d) = %d\n", x, evaluate(p1, x));
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}


*/





    #include <stdio.h>
    #include <stdlib.h>
    #include "date.h"
    #include "event.h"

    #define MAX 10


    int read_all(FILE *fp, eve e[], int n) {
        int count = 0, d, m, y;
        char detail[25];

        while (count < n && fscanf(fp, "%d %d %d %s", &d, &m, &y, detail) == 4) {
            e[count].p = (date *)malloc(sizeof(date)); // Allocate memory for date pointer
            setevent(&e[count], detail, d, m, y);
            count++;
        }
        return count;
    }


    void disp_all(eve e[], int n) {
        if (n == 0) {
            printf("No events to display.\n");
            return;
        }
        for (int i = 0; i < n; i++) {
            display(&e[i]);
            printf("\n");
        }
    }

    int find_latest(eve e[], int n) {
        if (n == 0) return -1;
        int latest = 0;
        for (int i = 1; i < n; i++) {

            int d1 = e[i].p->year * 10000 + e[i].p->month * 100 + e[i].p->day;
            int d2 = e[latest].p->year * 10000 + e[latest].p->month * 100 + e[latest].p->day;
            if (d1 > d2)
                latest = i;
        }
        return latest;
    }


    int count_events_in_month(eve e[], int n, int m) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (e[i].p->month == m)
                count++;
        }
        return count;
    }


    int remove_events(eve e[], int n, int d, int m, int y) {
        for (int i = 0; i < n; i++) {
            if (e[i].p->day == d && e[i].p->month == m && e[i].p->year == y) {
                free(e[i].p);
                for (int j = i; j < n - 1; j++)
                    e[j] = e[j + 1];
                n--;
                i--;
            }
        }
        return n;
    }

    int main() {
        eve events[MAX];
        int n = 0, m, d, y;

        FILE *fp = fopen("events.txt", "r");
        if (!fp) {
            printf("Error: Could not open events.txt\n");
            return 1;
        }

        n = read_all(fp, events, MAX);
        fclose(fp);

        printf("--- All Events Read from File (%d) ---\n", n);
        disp_all(events, n);

        int latest = find_latest(events, n);
        if (latest != -1) {
            printf("\n--- Latest Event Chronologically ---\n");
            display(&events[latest]);
            printf("\n");
        }

        printf("\nEnter month to search (1-12): ");
        scanf("%d", &m);
        printf("Events in month %d: %d\n", m, count_events_in_month(events, n, m));


        printf("\nEnter date to remove (day month year): ");
        scanf("%d %d %d", &d, &m, &y);
        int prev_count = n;
        n = remove_events(events, n, d, m, y);
        printf("Removed %d event(s).\n", prev_count - n);

        printf("\n--- Events After Removal (%d remaining) ---\n", n);
        disp_all(events, n);

        return 0;
    }