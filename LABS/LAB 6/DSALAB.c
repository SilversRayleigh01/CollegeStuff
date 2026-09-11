/*Step 1*/
/*#include <stdio.h>
#include "clist.h"

int main(void)
{
    int n, k;
    printf("Enter n and k: ");
    if (scanf("%d %d", &n, &k) != 2 || n <= 0 || k <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    clist_t list;
    init(&list);

    for (int i = 1; i <= n; ++i)
    {
        add(&list, i);
    }

    // Eliminate n - 1 people
    for (int i = 0; i < n - 1; ++i)
    {
        find_kth(&list, k);
        int eliminated = delete(&list);
        printf("Executed: %d\n", eliminated);
    }

    printf("Survivor: ");
    disp(&list);

    deinit(&list);
    return 0;
}
   */ 


/*Step 2*/
#include <stdio.h>
#include "clist.h"

int main(void)
{
    int n, k;
    printf("Enter number of people (n) and step (k): ");
    if (scanf("%d %d", &n, &k) != 2 || n <= 0 || k <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    clist_t list;
    init(&list);

    char name[NAME_LEN];
    for (int i = 1; i <= n; ++i)
    {
        printf("Enter name %d: ", i);
        scanf("%63s", name);
        add(&list, i, name);
    }

    printf("\n--- Elimination Order ---\n");
    char eliminated_name[NAME_LEN];
    int eliminated_key;

    for (int i = 0; i < n - 1; ++i)
    {
        find_kth(&list, k);
        delete(&list, eliminated_name, &eliminated_key);
        printf("Executed: %s (Position %d)\n", eliminated_name, eliminated_key);
    }

    printf("\n--- Final Survivor ---\n");
    disp(&list);

    deinit(&list);
    return 0;
}