#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

static void disp_recursive(tree_node_t* temp) {
    if(temp) {
        disp_recursive(temp->left_);
        printf("%d ", temp->key_);
        disp_recursive(temp->right_);
    }
}

static tree_node_t* insert_recursive(tree_node_t* root, tree_node_t* temp) {
    if(root == NULL) {
        root = temp;
    } else if(root->key_ > temp->key_) {
        root->left_ = insert_recursive(root->left_, temp);
    } else {
        root->right_ = insert_recursive(root->right_, temp);
    }
    return root;
}

static void deinit_recursive(tree_node_t* root) {
    if(root) {
        deinit_recursive(root->left_);
        deinit_recursive(root->right_);
        free(root);
    }
}

void init(tree_t *ptr_tree) {
    ptr_tree->root_ = NULL;
}

void deinit(tree_t *ptr_tree) {
    deinit_recursive(ptr_tree->root_);
    ptr_tree->root_ = NULL;
}

void disp(tree_t *ptr_tree) {
    printf("Inorder     : ");
    disp_recursive(ptr_tree->root_);
    printf("\n");
}

void insert(tree_t *ptr_tree, int key) {
    tree_node_t *temp = (tree_node_t*)malloc(sizeof(tree_node_t));
    temp->key_ = key;
    temp->left_ = temp->right_ = NULL;
    ptr_tree->root_ = insert_recursive(ptr_tree->root_, temp);
}

void level_order(tree_t *ptr_tree) {
    queue_t q;
    init_queue(&q);
 
    printf("Level order : ");
    enqueue(&q, ptr_tree->root_);
    while(! is_empty(&q)) {
        tree_node_t* temp = dequeue(&q);
        if(temp != NULL) {
            printf("%d ", temp->key_);
            enqueue(&q, temp->left_);
            enqueue(&q, temp->right_);
        }
    }
    printf("\n");
    deinit_queue(&q);
}

void level_order_lines(tree_t *ptr_tree) {
    if(ptr_tree->root_ == NULL) { printf("(empty tree)\n"); return; }
 
    queue_t q;  
    init_queue(&q);
    enqueue(&q, ptr_tree->root_);
    
    int cur = 1, next = 0, level = 0, printed = 0;
 
    while(! is_empty(&q)) {
        tree_node_t* temp = dequeue(&q);
        --cur;
        
        if(temp != NULL) {
            if(printed == 0) printf("  Level %d : ", level);
            printf("%4d", temp->key_);
            ++printed;
            
            enqueue(&q, temp->left_);
            enqueue(&q, temp->right_);
            next += 2;
        }
        
        if(cur == 0) {
            if(printed > 0) {
                printf("\n");
                ++level;
            }
            cur = next;
            next = 0;
            printed = 0;
        }
    }
    deinit_queue(&q);
}


#define MAX_ROWS 30
#define MAX_COLS 150

typedef struct {
    char grid[MAX_ROWS][MAX_COLS];
    int cw;             
    int current_col;   
} canvas_t;

static int num_digits(int n) {
    if (n == 0) return 1;
    int count = 0;
    if (n < 0) { count++; n = -n; }
    while (n > 0) { count++; n /= 10; }
    return count;
}

static int height_recursive(tree_node_t* root) {
    if (!root) return 0;
    int lh = height_recursive(root->left_);
    int rh = height_recursive(root->right_);
    return (lh > rh ? lh : rh) + 1;
}

static int max_width_recursive(tree_node_t* root) {
    if (!root) return 0;
    int mw = num_digits(root->key_);
    int lw = max_width_recursive(root->left_);
    int rw = max_width_recursive(root->right_);
    if (lw > mw) mw = lw;
    if (rw > mw) mw = rw;
    return mw;
}


static int place(tree_node_t* root, int depth, canvas_t* cv) {
    if (!root) return -1;
    
    int left_col = place(root->left_, depth + 1, cv);
    
    int my_col = cv->current_col++; 
    int start_idx = my_col * cv->cw;
    
    char buf[32];
    sprintf(buf, "%*d", cv->cw, root->key_); // Format number with spaces
    for (int i = 0; i < cv->cw; i++) {
        if (buf[i] != '\0') {
            cv->grid[2 * depth][start_idx + i] = buf[i];
        }
    }
    

    int right_col = place(root->right_, depth + 1, cv);
    
    int branch_row = 2 * depth + 1;
    if (left_col != -1) {
        int start = left_col * cv->cw + cv->cw / 2;
        int end = my_col * cv->cw + cv->cw / 2;
        cv->grid[branch_row][start] = '+';
        for (int i = start + 1; i < end; i++) cv->grid[branch_row][i] = '-';
        cv->grid[branch_row][end] = '+';
    }
    if (right_col != -1) {
        int start = my_col * cv->cw + cv->cw / 2;
        int end = right_col * cv->cw + cv->cw / 2;
        cv->grid[branch_row][start] = '+';
        for (int i = start + 1; i < end; i++) cv->grid[branch_row][i] = '-';
        cv->grid[branch_row][end] = '+';
    }
    return my_col;
}

void disp_tree(tree_t *ptr_tree) {
    if (ptr_tree->root_ == NULL) {
        printf("(empty tree)\n");
        return;
    }
    
    canvas_t cv;
    cv.cw = max_width_recursive(ptr_tree->root_) + 2;
    cv.current_col = 0;
    
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            cv.grid[i][j] = ' ';
        }
        cv.grid[i][MAX_COLS - 1] = '\0'; 
    }
    

    place(ptr_tree->root_, 0, &cv);
    
    
    int h = height_recursive(ptr_tree->root_);
    int rows = 2 * h - 1;
    
    for (int i = 0; i < rows; i++) {
    
        int last = MAX_COLS - 2;
        while (last >= 0 && cv.grid[i][last] == ' ') {
            last--;
        }
        cv.grid[i][last + 1] = '\0';
        
        if (last >= 0) {
            printf("%s\n", cv.grid[i]);
        }
    }
}