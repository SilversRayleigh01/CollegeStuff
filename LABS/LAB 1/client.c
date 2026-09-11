#include <stdio.h>
#include "date.h"


int main(){
    date *p;
    int d,m,y;
    printf("Enter the day: ");
    scanf("%d",&d);
    printf("Enter the month: ");
    scanf("%d",&m);
    printf("Enter the year: \n");
    scanf("%d",&y);
    setdate(p,d,m,y);
    printf("Date has been set\n");
    dispdate(p);
    return 0;    
}