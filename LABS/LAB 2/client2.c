#include <stdio.h>
#include "event.h"
#include "date.h"
    
    
int main(){

    eve k;
    char details[25];
    int d,m,y;
    printf("Enter the details of the event: ");
    scanf("%[^\n]s",details);
    printf("Enter the day: ");
    scanf("%d",&d);
    printf("Enter the month: ");
    scanf("%d",&m);
    printf("Enter the year: ");
    scanf("%d",&y);
    setevent(&k,details,d,m,y);
    printf("Displaying event details: \n");
    display(&k);

}