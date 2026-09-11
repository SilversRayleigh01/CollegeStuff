#ifndef RECT_H
#define RECT_H

typedef struct rect {
    float length;
    float breadth;
} rect_t;

void set_rect(rect_t *r, float l, float b);

void display_rect(rect_t r);

float find_area(rect_t r);

int is_smaller(rect_t r1, rect_t r2);

#endif