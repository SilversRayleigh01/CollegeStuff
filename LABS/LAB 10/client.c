#include <stdio.h>
#include "tree.h"

void run_test_suite(tree_t* t) {
    disp(t);
    level_order(t);
    printf("\n--- Level Order Lines ---\n");
    level_order_lines(t);
    printf("\n--- Draw Tree ---\n");
    disp_tree(t);
    printf("\n");
}
int main()
{
    tree_t t;
    init(&t);   
    int n, val;
    printf("Enter the number of nodes to insert into the BST: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n > 0) {
        printf("Enter %d integers separated by spaces: ", n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &val);
            insert(&t, val);
        }
    }
    run_test_suite(&t);
    
    deinit(&t);

    return 0;
}