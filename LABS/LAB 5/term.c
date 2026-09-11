#include <stdio.h>
#include <stdlib.h>
#include "term.h"

term_t *create_term(double coeff, int exp) {
    if (coeff == 0.0) return NULL;

    term_t *node = (term_t *)malloc(sizeof(term_t));
    if (!node) return NULL;

    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void print_term(term_t *ptr_term, int is_first) {
    if (!ptr_term) return;

    double c = ptr_term->coeff;
    int e = ptr_term->exp;

    if (is_first) {
        if (c < 0) {
            printf("-");
            c = -c;
        }
    } else {
        if (c > 0) printf(" + ");
        else {
            printf(" - ");
            c = -c;
        }
    }

    if (e == 0) {
        printf("%.4g", c);
    } else if (e == 1) {
        if (c == 1.0) printf("x");
        else printf("%.4gx", c);
    } else {
        if (c == 1.0) printf("x^%d", e);
        else printf("%.4gx^%d", c, e);
    }
}

void integrate_term(term_t *ptr_term, term_t *ptr_integrated_term) {
    if (!ptr_term || !ptr_integrated_term) return;

    if (ptr_term->exp == -1) {
        printf("Error: Cannot integrate x^-1 into polynomial term.\n");
        ptr_integrated_term->coeff = 0;
        ptr_integrated_term->exp = 0;
        ptr_integrated_term->next = NULL;
        return;
    }

    ptr_integrated_term->exp = ptr_term->exp + 1;
    ptr_integrated_term->coeff = ptr_term->coeff / (ptr_term->exp + 1);
    ptr_integrated_term->next = NULL;
}