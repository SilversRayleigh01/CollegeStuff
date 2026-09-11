#include <stdio.h>
#include <stdlib.h>
#include "rect.h"

void set_rect(rect_t *r,float l,float b){
    r->length = l;
    r->breadth = b;
}


void display_rect(rect_t r){

    printf("The length of the rectangle is: %.2f\n",r.length);
    printf("The breadth of the rectangle is: %.2f\n",r.breadth);
    printf("The area of the rectangle is: %.2f\n",find_area(r));
}

float find_area(rect_t r){
    float area = (r.length)*(r.breadth);
    return area;
}


int is_smaller(rect_t r1, rect_t r2){
    if (find_area(r1)<find_area(r2)){
        return 1;
    }
    else {
        return 0;
    }
}