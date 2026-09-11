#ifndef LIST_H
#define LIST_H

#include "rect.h"

typedef struct node
{
    rect_t data;
    struct node *link;
} NODE;

void init(NODE **head);
NODE *createnode(rect_t val);
NODE *insertordered(rect_t ele, NODE *head);
void display(NODE *head);

float find_total_value(NODE *head, float rate);
rect_t find_highest_length(NODE *head);
rect_t find_least_breadth(NODE *head);

#endif