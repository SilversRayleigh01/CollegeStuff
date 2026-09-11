#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;

NODE *createnode(int val)
{
    NODE * newnode = (NODE* )malloc(sizeof(NODE));
    newnode->data = val;
    newnode->link = NULL;
    return newnode;
}

NODE *insertordered(int ele, NODE * head)
{
    NODE *newnode = createnode(ele);

    if(head==NULL)
    {
        head = newnode;
        return head;
    }
    else if((head->data)>ele)
    {
        newnode->link = head;
        head = newnode;
    }

    else
    {
        NODE *p = head;
        NODE *q;

        while(p!=NULL && ele>=p->data)
        {
            q = p;
            p = p->link;
        }
        q->link = newnode;
        newnode->link = p;

        return head;
    }
}

void display(NODE * head)
{
    if(head==NULL)
    {
        printf("Empty list\n");
    }

    else
    {
        NODE *p = head;
        while(p->link!=NULL)
        {
            printf("%d ",p->data);  
            p = p->link;
        }
        printf("%d ",p->data);  
    }
}

void init(NODE ** head)
{
    *head=NULL;
}

int main()
{
    NODE *head;
    init(&head);

    printf("1:insert_ordered  2:display 3:exit\n");
    int ch,ele;

    do
    {
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&ele);
                head = insertordered(ele,head);
                break;

            case 2:
                display(head);
                printf("\n");
                break;

            case 3:
                printf("Exited\n");
                break;

            default:
                printf("Invalid choice");
        }
    } while (ch!=3);

    display(head);
    return 0;
}