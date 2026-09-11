#include "date.h"
#include <stdio.h>


void setdate(date *p, int day, int month, int year){
    p->day = day;
    p->month = month;
    p->year = year;
}


void dispdate(date *p){
    printf("Date: %d-%d-%d",p->day,p->month,p->year);
}