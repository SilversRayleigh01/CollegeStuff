#include <stdio.h>
#ifndef DATE_H
#define DATE_H
typedef struct Date{
    int day;
    int month;
    int year;
}date;


void setdate(date *p, int day , int month, int year);

void dispdate(date *p);
#endif