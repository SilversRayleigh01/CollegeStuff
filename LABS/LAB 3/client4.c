#include <stdio.h>
#include "list.h"
int main()
{
    NODE *head;
    init(&head);
    int n;
    printf("Enter number of sites: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        float l, b;
        printf("Enter length and breadth for site %d: ", i + 1);
        scanf("%f %f", &l, &b);
        rect_t r;
        set_rect(&r, l, b);
        head = insertordered(r, head);
    }
    printf("\n--- Ordered Sites by Area ---\n");
    display(head);
    if (head != NULL)
    {
        float rate;
        printf("\nEnter rate per unit area: ");
        scanf("%f", &rate);
        printf("Total value of layout: %.2f\n", find_total_value(head, rate));

        printf("\nDetails of Site with highest length: \n");
        display_rect(find_highest_length(head));

        printf("Details of Site with least breadth: \n");
        display_rect(find_least_breadth(head));
    }

    return 0;
}