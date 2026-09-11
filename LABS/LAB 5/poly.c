#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"

// Helper: insert a term at the end of the list
static void insert_end(poly_t *p, double coeff, int exp) {
    if (coeff == 0.0) return;

    term_t *node = create_term(coeff, exp);
    if (!node) return;

    if (p->head == NULL) {
        p->head = node;
    } else {
        term_t *curr = p->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

// Create polynomial by reading input
poly_t create_poly(void) {
    poly_t p;
    p.head = NULL;

    int n;
    printf("Number of terms: ");
    if (scanf("%d", &n) != 1) return p;

    for (int i = 0; i < n; i++) {
        double c;
        int e;
        printf("Coefficient Exponent: ");
        scanf("%lf %d", &c, &e);
        insert_end(&p, c, e);
    }
    return p;
}

// Display terms linked together
void display_poly(poly_t poly) {
    if (poly.head == NULL) {
        printf("0\n");
        return;
    }

    term_t *curr = poly.head;
    int is_first = 1;
    while (curr != NULL) {
        print_term(curr, is_first);
        is_first = 0;
        curr = curr->next;
    }
    printf("\n");
}

// Merge-add two polynomials
void add_poly(poly_t poly1, poly_t poly2, poly_t *sum) {
    sum->head = NULL;
    term_t *p1 = poly1.head;
    term_t *p2 = poly2.head;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            insert_end(sum, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            insert_end(sum, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            insert_end(sum, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insert_end(sum, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insert_end(sum, p2->coeff, p2->exp);
        p2 = p2->next;
    }
}

// Integrate full polynomial term by term
poly_t integrate_poly(poly_t poly) {
    poly_t res;
    res.head = NULL;

    term_t *curr = poly.head;
    while (curr != NULL) {
        term_t temp;
        integrate_term(curr, &temp);
        insert_end(&res, temp.coeff, temp.exp);
        curr = curr->next;
    }
    return res;
}

// Evaluate polynomial for given x using Horner's / direct power
double eval_poly(poly_t poly, double x) {
    double total = 0.0;
    term_t *curr = poly.head;
    while (curr != NULL) {
        total += curr->coeff * pow(x, curr->exp);
        curr = curr->next;
    }
    return total;
}

// Free allocated memory
void destroy_poly(poly_t *poly) {
    if (!poly) return;
    term_t *curr = poly->head;
    while (curr != NULL) {
        term_t *temp = curr;
        curr = curr->next;
        free(temp);
    }
    poly->head = NULL;
}