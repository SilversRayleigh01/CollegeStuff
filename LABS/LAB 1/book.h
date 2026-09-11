#include <stdio.h>
#include "date.h"
#ifndef BOOK_H
#define BOOK_H


typedef struct book
{
    int bookid;
    char title[15];
    char author[10];
    date *p;
    int price;
    int discount;
}b;


void setbook(b *k,int id,char t[15],char aut[15],int d,int m,int y,int price);
void dispbook(b *k);



#endif