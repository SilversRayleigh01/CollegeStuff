#include <stdio.h>
#include "book.h"
#include "date.h"
#include <string.h>


void setbook(b *k,int id,char t[15],char aut[15],int d,int m,int y,int price){
    k->bookid=id;
    strcpy(k->title,t);
    strcpy(k->author,aut);
    k->p->day = d;
    k->p->month = m;
    k->p->year = y;
    k->price = price;
    k->discount = price -( 0.1*price);

}


void dispbook(b *k){
    printf("Bookid: %d",k->bookid);
    printf("Book Title: %s",k->title);
    printf("Author: %s",k->author);
    dispdate(k->p);
    printf("price: %d",k->price);

}


