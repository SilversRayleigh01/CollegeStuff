#include <stdio.h>
#include "book.h"
#include "date.h"



int main(){
    b book;
    int d,m,y,id,price;
    char title[15],author[15];
    printf("Enter the book id: ");
    scanf("%d",&id);
    printf("ENter the Book title: \n");
    scanf(" %[^\n]s",title);
    printf("Enter the Author name: \n");
    scanf(" %[^\n]s",author);

    printf("Enter the day: ");
    scanf("%d",&d);
    printf("Enter the month: ");
    scanf("%d",&m);
    printf("Enter the year: ");
    scanf("%d",&y);

    printf("Enter the price: ");
    scanf("%d",&price);

    setbook(&book,id,title,author,d,m,y,price);
    dispbook(&book);
    return 0;
}