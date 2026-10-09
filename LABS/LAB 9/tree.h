#ifndef TREE_H
#define TREE_H
#define MAXSIZE 200

struct node
{
	int key_;
	int left_;
	int right_;
};
typedef struct node node_t;

struct tree 
{
	int root_;
	int count_;  
	node_t elem_[MAXSIZE];
};
typedef struct tree tree_t;

void init(tree_t *ptr_tree);
void insert(tree_t *ptr_tree, int key);
void disp(tree_t *ptr_tree);
int delete_key(tree_t* ptr_tree, int key);

int get_node_count(tree_t *ptr_tree);
int get_leaf_count(tree_t *ptr_tree);
int compare_trees(tree_t *t1, tree_t *t2);
void copy_tree(tree_t *src, tree_t *dest);

#endif