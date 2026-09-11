#include <stdio.h>
#include <string.h>
#include "event.h"
#include "date.h"

void setevent(eve *k,char details[25],int d,int m,int y){

    strcpy(k->detail,details);

    setdate(k->p,d,m,y);

}   


void display(eve *k){
    printf("The details of the event are: %s\n",k->detail);
    dispdate(k->p);
}