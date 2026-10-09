#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    tree_t my_tree, my_tree2;
    int choice, key;
    
    init(&my_tree);

    while(1)
    {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display (Inorder)\n");
        printf("4. Count Nodes\n");
        printf("5. Count Leaves\n");
        printf("6. Copy Tree and Compare\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch(choice)
        {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(&my_tree, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete_key(&my_tree, key);
                break;
            case 3:
                printf("Tree contents: ");
                disp(&my_tree);
                break;
            case 4:
                printf("Total Nodes: %d\n", get_node_count(&my_tree));
                break;
            case 5:
                printf("Total Leaves: %d\n", get_leaf_count(&my_tree));
                break;
            case 6:
                copy_tree(&my_tree, &my_tree2);
                printf("Tree copied. Comparing original and copy...\n");
                if (compare_trees(&my_tree, &my_tree2)) {
                    printf("The trees are identical.\n");
                } else {
                    printf("The trees are different.\n");
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}