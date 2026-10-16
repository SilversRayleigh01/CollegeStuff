#ifndef TREE_H
#define TREE_H

struct tree_node 
{
    int key_;
    struct tree_node *left_;
    struct tree_node *right_;
};
typedef struct tree_node tree_node_t;

struct tree 
{
    tree_node_t *root_;
};
typedef struct tree tree_t;

void init(tree_t *ptr_tree);
void deinit(tree_t *ptr_tree);
void disp(tree_t *ptr_tree);
void insert(tree_t *ptr_tree, int key);


void level_order(tree_t *ptr_tree);
void level_order_lines(tree_t *ptr_tree);
void disp_tree(tree_t *ptr_tree);

#endif