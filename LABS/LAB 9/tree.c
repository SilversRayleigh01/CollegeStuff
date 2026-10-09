#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"

stack_t mem_stack;

void init(tree_t *ptr_tree)
{
	ptr_tree->root_ = -1;
	ptr_tree->count_ = 0;
    
    init_stack(&mem_stack);
    
    for(int i = MAXSIZE - 1; i >= 0; i--) {
        push(&mem_stack, i);
    }
}

int insert_recursive(node_t elem[], int root, int temp)
{
	if(root == -1)
	{
		root = temp;
	}
	else if(elem[root].key_ > elem[temp].key_)
	{
		elem[root].left_ = insert_recursive(elem, elem[root].left_, temp);
	}
	else
	{
		elem[root].right_ = insert_recursive(elem, elem[root].right_, temp);
	}
	return root;
}

void insert(tree_t *ptr_tree, int key)
{
    if (is_empty(&mem_stack)) {
        printf("Memory full; cannot insert\n");
        return;
    }
    
	int temp = pop(&mem_stack);
	ptr_tree->count_++;
	
	ptr_tree->elem_[temp].key_ = key;
	ptr_tree->elem_[temp].left_ = ptr_tree->elem_[temp].right_ = -1;
	ptr_tree->root_ = insert_recursive(ptr_tree->elem_, ptr_tree->root_, temp);
}

void disp_recursive(node_t elem[], int temp)
{
    if(temp != -1)
    {
        disp_recursive(elem, elem[temp].left_);
        printf("%d ", elem[temp].key_);
        disp_recursive(elem, elem[temp].right_);
    }
}

void disp(tree_t *ptr_tree)
{
	disp_recursive(ptr_tree->elem_, ptr_tree->root_); 
	printf("\n\n");
}

int delete_key_recursive(node_t elem[], int root, int key)
{
	if(root == -1) return -1;
	
	if(key < elem[root].key_)
	{
		elem[root].left_ = delete_key_recursive(elem, elem[root].left_, key);
	}
	else if(key > elem[root].key_)
	{
		elem[root].right_ = delete_key_recursive(elem, elem[root].right_, key);
	}
	else 
	{
		if(elem[root].left_ == -1 && elem[root].right_ == -1)
		{
            push(&mem_stack, root); 
			return -1;
		}
		else if(elem[root].left_ == -1)
		{
			int temp = elem[root].right_;
            push(&mem_stack, root); 
			return temp;
		}
		else if(elem[root].right_ == -1)
		{
			int temp = elem[root].left_;
            push(&mem_stack, root);
			return temp;
		}
		else 
		{
			int temp = elem[root].right_;
            while(elem[temp].left_ != -1) {
                temp = elem[temp].left_;
            }
			elem[root].key_ = elem[temp].key_;
			elem[root].right_ = delete_key_recursive(elem, elem[root].right_, elem[temp].key_);
			return root;
		}
	}
    return root;
}

int delete_key(tree_t *ptr_tree, int key)
{
	ptr_tree->root_ = delete_key_recursive(ptr_tree->elem_, ptr_tree->root_, key);
    ptr_tree->count_--;
    return 1;
}

int count_nodes_recursive(node_t elem[], int root)
{
    if (root == -1) 
    {
        return 0;
    }
    return 1 + count_nodes_recursive(elem, elem[root].left_) + count_nodes_recursive(elem, elem[root].right_);
}

int get_node_count(tree_t *ptr_tree)
{
    return count_nodes_recursive(ptr_tree->elem_, ptr_tree->root_);
}

int count_leaves_recursive(node_t elem[], int root)
{
    if (root == -1) 
    {
        return 0;
    }
    if (elem[root].left_ == -1 && elem[root].right_ == -1) 
    {
        return 1;
    }
    return count_leaves_recursive(elem, elem[root].left_) + count_leaves_recursive(elem, elem[root].right_);
}

int get_leaf_count(tree_t *ptr_tree)
{
    return count_leaves_recursive(ptr_tree->elem_, ptr_tree->root_);
}


int compare_trees_recursive(node_t elem1[], int root1, node_t elem2[], int root2)
{
    if (root1 == -1 && root2 == -1) return 1;
    if (root1 == -1 || root2 == -1) return 0;
    if (elem1[root1].key_ != elem2[root2].key_) return 0;
    
    return compare_trees_recursive(elem1, elem1[root1].left_, elem2, elem2[root2].left_) &&
           compare_trees_recursive(elem1, elem1[root1].right_, elem2, elem2[root2].right_);
}

int compare_trees(tree_t *t1, tree_t *t2)
{
    if (t1->count_ != t2->count_) return 0;
    return compare_trees_recursive(t1->elem_, t1->root_, t2->elem_, t2->root_);
}


int copy_tree_recursive(node_t src_elem[], int src_root, tree_t *dest_tree)
{
    if (src_root == -1) return -1;
    
    if (is_empty(&mem_stack)) 
    {
        printf("Memory full; cannot copy completely\n");
        return -1;
    }
    
    int dest_root = pop(&mem_stack);
    dest_tree->count_++;
    
    dest_tree->elem_[dest_root].key_ = src_elem[src_root].key_;
    dest_tree->elem_[dest_root].left_ = copy_tree_recursive(src_elem, src_elem[src_root].left_, dest_tree);
    dest_tree->elem_[dest_root].right_ = copy_tree_recursive(src_elem, src_elem[src_root].right_, dest_tree);
    
    return dest_root;
}

void copy_tree(tree_t *src, tree_t *dest)
{
    dest->root_ = -1;
    dest->count_ = 0;
    dest->root_ = copy_tree_recursive(src->elem_, src->root_, dest);
}