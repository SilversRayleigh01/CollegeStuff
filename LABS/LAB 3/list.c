#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init(NODE **head)
{
    *head = NULL;
}

NODE *createnode(rect_t val)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = val;
    newnode->link = NULL;
    return newnode;
}

NODE *insertordered(rect_t ele, NODE *head)
{
    NODE *newnode = createnode(ele);

    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    else if (is_smaller(ele, head->data))
    {
        newnode->link = head;
        head = newnode;
        return head;
    }
    else
    {
        NODE *p = head;
        NODE *q = NULL;

        while (p != NULL && !is_smaller(ele, p->data))
        {
            q = p;
            p = p->link;
        }
        q->link = newnode;
        newnode->link = p;

        return head;
    }
}

void display(NODE *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    NODE *p = head;
    int site_no = 1;
    while (p != NULL)
    {
        printf("Site %d: ", site_no++);
        display_rect(p->data);
        p = p->link;
    }
}


float find_total_value(NODE *head, float rate)
{
    float total_area = 0;
    NODE *p = head;
    while (p != NULL)
    {
        total_area += find_area(p->data);
        p = p->link;
    }
    return total_area * rate;
}

rect_t find_highest_length(NODE *head)
{
    rect_t max_rect_t = head->data;
    NODE *p = head->link;

    while (p != NULL)
    {
        if (p->data.length > max_rect_t.length)
        {
            max_rect_t = p->data;
        }
        p = p->link;
    }
    return max_rect_t;
}


rect_t find_least_breadth(NODE *head)
{
    rect_t min_rect_t = head->data;
    NODE *p = head->link;

    while (p != NULL)
    {
        if (p->data.breadth < min_rect_t.breadth)
        {
            min_rect_t = p->data;
        }
        p = p->link;
    }
    return min_rect_t;
}