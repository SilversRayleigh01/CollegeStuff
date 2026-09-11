#include <stdio.h>
#include "poly.h"

int main(void) {
    // PART A: Addition of Two Polynomials
    poly_t poly1, poly2, sum;

    printf("Enter first polynomial:\n");
    poly1 = create_poly();

    printf("Enter second polynomial:\n");
    poly2 = create_poly();

    add_poly(poly1, poly2, &sum);

    printf("Polynomial 1: "); 
    display_poly(poly1);
    printf("Polynomial 2: "); 
    display_poly(poly2);
    printf("Sum         : "); 
    display_poly(sum);

    destroy_poly(&poly1);
    destroy_poly(&poly2);
    destroy_poly(&sum);

    // PART B: Definite Integration of a Polynomial
    poly_t poly, integrated_poly;
    double lower_limit, upper_limit;
    double result;

    printf("\nEnter the polynomial to integrate:\n");
    poly = create_poly();

    integrated_poly = integrate_poly(poly);

    printf("Enter lower limit: ");
    scanf("%lf", &lower_limit);

    printf("Enter upper limit: ");
    scanf("%lf", &upper_limit);

    result = eval_poly(integrated_poly, upper_limit) 
           - eval_poly(integrated_poly, lower_limit);

    printf("Polynomial           : "); 
    display_poly(poly);
    printf("Integrated Polynomial: "); 
    display_poly(integrated_poly);
    printf("Definite integral from %.2lf to %.2lf = %.4lf\n",
           lower_limit, upper_limit, result);

    destroy_poly(&poly);
    destroy_poly(&integrated_poly);

    return 0;
}