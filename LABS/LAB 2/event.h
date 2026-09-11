#include "date.h"
#ifndef EVENT_H
#define EVENT_H

typedef struct event{
    char detail[25];
    date *p;

}eve;

void setevent(eve *k,char details[25],int d,int m,int y);
void display(eve *k);
#endif