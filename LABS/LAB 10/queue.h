#ifndef queue_H
#define queue_H 

#include "tree.h"

struct queue_node
{
    tree_node_t* data_;
    struct queue_node* next_;
};
typedef struct queue_node queue_node_t;

struct queue 
{
    queue_node_t* front_;
    queue_node_t* rear_;
};
typedef struct queue queue_t;

void init_queue(queue_t *ptr_queue);
void deinit_queue(queue_t *ptr_queue);
void enqueue(queue_t *ptr_queue, tree_node_t* data);
tree_node_t* dequeue(queue_t *ptr_queue);
int is_empty(queue_t *ptr_queue);
int is_full(queue_t *ptr_queue);

#endif